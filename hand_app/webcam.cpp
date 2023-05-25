#include "webcam.h"
#include "qimage.h"

using namespace std;
using namespace cv;

Webcam::Webcam() {
//    CommandLineParser parser(argc, argv,
//                             "{ h help           | false     | print this help message }"
//                             "{ p proto          | C:/Users/Matthieu/Documents/Ecole/TelecomSaintEtienne/FISE2/S8/Bibliotheque_de_developpement/TestOpenCV/pose_deploy.prototxt | (required) model configuration, e.g. hand/pose.prototxt }"
//                             "{ m model          | C:/Users/Matthieu/Documents/Ecole/TelecomSaintEtienne/FISE2/S8/Bibliotheque_de_developpement/TestOpenCV/pose_iter_102000.caffemodel | (required) model weights, e.g. hand/pose_iter_102000.caffemodel }"
//                             "{ i image          | C:/Users/Matthieu/Documents/Ecole/TelecomSaintEtienne/FISE2/S8/Bibliotheque_de_developpement/TestOpenCV/hand3.png | (required) path to image file (containing a single person, or hand) }"
//                             "{ d dataset        | HAND      | specify what kind of model was trained. It could be (COCO, MPI, HAND) depends on dataset. }"
//                             "{ width            |  368      | Preprocess input image by resizing to a specific width. }"
//                             "{ height           |  368      | Preprocess input image by resizing to a specific height. }"
//                             "{ t threshold      |  0.1      | threshold or confidence value for the heatmap }"
//                             "{ s scale          |  0.003922 | scale for blob }"
//                             );
    modelTxt = samples::findFile("../hand_app/pose_iter_102000.caffemodel");
    modelBin = samples::findFile("../hand_app/pose_deploy.prototxt");
    dataset = "HAND";
//    W_in = 368;
//    H_in = 368;
//    thresh = 0.1;
//    scale  = 0.003922;
    if (!dataset.compare("HAND")) {  midx = 2; npairs = 20; nparts = 22; }
    else
    {
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

void Webcam::analyze_hand(Webcam* webcam) {
    webcam->run();
}

QImage Webcam::toImg() {
    if(window->read(frame)) {
        flip(frame, frame, 1);
        cvtColor(frame,frame,COLOR_BGR2RGB);
        *img = QImage((const unsigned char*)(frame.data),frame.cols,frame.rows,QImage::Format_RGB888);
    }
    return *img;
}

void Webcam::run() {
    window->open(0);
    while (keepRunning) {
        *window >> frame;
        if (frame.empty())
        {
            std::cerr << "Can't read image from the WebCam." << std::endl;
            exit(-1);
        }
        // send it through the network
        Mat inputBlob = blobFromImage(frame, scale, Size(W_in, H_in), Scalar(0, 0, 0), false, false);
        net.setInput(inputBlob);
        Mat result = net.forward();
        // the result is an array of "heatmaps", the probability of a body part being in location x,y
        int H = result.size[2];
        int W = result.size[3];
        // find the position of the body parts
        vector<Point> points(22);
        for (int n=0; n<nparts; n++)
        {
            // Slice heatmap of corresponding body's part.
            Mat heatMap(H, W, CV_32F, result.ptr(0,n));
            // 1 maximum per heatmap
            Point p(-1,-1),pm;
            double conf;
            minMaxLoc(heatMap, 0, &conf, 0, &pm);
            if (conf > thresh)
                p = pm;
            points[n] = p;
        }
        // connect body parts and draw it !
        float SX = float(frame.cols) / W;
        float SY = float(frame.rows) / H;
        for (int n=0; n<npairs; n++)
        {
            // lookup 2 connected body/hand parts
            Point2f a = points[POSE_PAIRS[midx][n][0]];
            Point2f b = points[POSE_PAIRS[midx][n][1]];
            // we did not find enough confidence before
            if (a.x<=0 || a.y<=0 || b.x<=0 || b.y<=0)
                continue;
            // scale to image size
            a.x*=SX; a.y*=SY;
            b.x*=SX; b.y*=SY;
            line(frame, a, b, Scalar(0,200,0), 2);
            circle(frame, a, 3, Scalar(0,0,200), -1);
            circle(frame, b, 3, Scalar(0,0,200), -1);
        }

        imshow("WebCam", frame);
        if (waitKey(1) == 27) {
            break;
        }
    }
}