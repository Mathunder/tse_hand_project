#include "webcam.h"
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include "qimage.h"
#include <QDebug>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Webcam::Webcam() {
    if (!dataset.compare("HAND")) {
        midx = 2; npairs = 20; nparts = 22;
    } else {
        std::cerr << "Can't interpret dataset parameter: " << dataset << std::endl;
        exit(-1);
    }
    // read the network model
    net = readNet(modelBin, modelTxt);

    window = new VideoCapture(0);
    img = new QImage();
}

Webcam* Webcam::s_instance = NULL;

Webcam* Webcam::getInstance() {
    if (s_instance == NULL) {
        s_instance = new Webcam();
    }
    return s_instance;
}

void Webcam::analyze_hand() {
    QFuture<void> future = QtConcurrent::run([this]() {
        *window >> frame;
        if (frame.empty()) {
            std::cerr << "Can't read image from the WebCam." << std::endl;
            exit(-1);
        }
        // send it through the network
        Mat inputBlob = blobFromImage(frame, scale, Size(W_in, H_in), Scalar(0, 0, 0), false, false);
        net.setInput(inputBlob);
        Mat *result = new Mat(net.forward());

        // the result is an array of "heatmaps", the probability of a body part being in location x,y
        int H = result->size[2];
        int W = result->size[3];
        // find the position of the body parts
        vector<Point> points(22);
        for (int n=0; n<nparts; n++) {
            // Slice heatmap of corresponding body's part.
            Mat heatMap(H, W, CV_32F, result->ptr(0,n));
            // 1 maximum per heatmap
            Point p(-1,-1), pm;
            double conf;
            minMaxLoc(heatMap, 0, &conf, 0, &pm);
            if (conf > thresh)
                p = pm;
            points[n] = p;
        }

        // connect body parts and draw it !
        float SX = float(frame.cols) / W;
        float SY = float(frame.rows) / H;

        for (int n=0; n<npairs; n++) {
            // lookup 2 connected body/hand parts
            Point2f a = points[POSE_PAIRS[midx][n][0]];
            Point2f b = points[POSE_PAIRS[midx][n][1]];

            switch(n) {
            case 3 :
                finger_length[0] = (a.x - b.x <= 0) ? 1 : -1;
            case 7 :
                finger_length[1] = (a.y - b.y >= 0) ? 1 : -1;
            case 11 :
                finger_length[2] = (a.y - b.y >= 0) ? 1 : -1;
            case 15 :
                finger_length[3] = (a.y - b.y >= 0) ? 1 : -1;
            case 19 :
                finger_length[4] = (a.y - b.y >= 0) ? 1 : -1;
            }

            // we did not find enough confidence before
            if (a.x<=0 || a.y<=0 || b.x<=0 || b.y<=0)
                continue;
            // scale to image size
            a.x*=SX; a.y*=SY;
            b.x*=SX; b.y*=SY;
//            line(frame, a, b, Scalar(0,200,0), 5);
//            circle(frame, a, 3, Scalar(0,0,200), 2);
//            circle(frame, b, 3, Scalar(0,0,200), 2);
        }

        for(int i=0; i < (int) std::size(finger_length); i++) {
            finger[i] = (finger_length[i] > 0.0) ? true : false;
        }
    });
    QThread::msleep(100);
}

QImage Webcam::run() {
    if(window->read(frame)) {
        flip(frame, frame, 1);
        cvtColor(frame,frame,COLOR_BGR2RGB);
        *img = QImage(frame.data,frame.cols,frame.rows,QImage::Format_RGB888);
    }

    return *img;
}

Webcam::~Webcam() {
    delete window;
    delete img;
    delete result;
}
