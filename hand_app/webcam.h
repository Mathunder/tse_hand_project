#ifndef WEBCAM_H
#define WEBCAM_H

#include "qimage.h"
#include <future>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace cv::dnn;
#include <iostream>

class Webcam
{
public:
    Webcam();
    static void analyze_hand(Webcam *webcam);
    QImage run(bool analyze_hand);
    static Webcam* getInstance();
    bool finger[5];

private:
    cv::VideoCapture *window;
    cv::Mat frame;
    Mat *result;
    QImage *img;
    static Webcam* s_instance;
    Net net;
    String modelTxt, modelBin, dataset;
    int W_in, H_in;
    float thresh, scale;
    int midx, npairs, nparts;

    int sign;
    float finger_length[5];


    const int POSE_PAIRS[3][20][2] = {
        {   // COCO body
            {1,2}, {1,5}, {2,3},
            {3,4}, {5,6}, {6,7},
            {1,8}, {8,9}, {9,10},
            {1,11}, {11,12}, {12,13},
            {1,0}, {0,14},
            {14,16}, {0,15}, {15,17}
        },
        {   // MPI body
            {0,1}, {1,2}, {2,3},
            {3,4}, {1,5}, {5,6},
            {6,7}, {1,14}, {14,8}, {8,9},
            {9,10}, {14,11}, {11,12}, {12,13}
        },
        {   // hand
            {0,1}, {1,2}, {2,3}, {3,4},         // thumb
            {0,5}, {5,6}, {6,7}, {7,8},         // pinkie
            {0,9}, {9,10}, {10,11}, {11,12},    // middle
            {0,13}, {13,14}, {14,15}, {15,16},  // ring
            {0,17}, {17,18}, {18,19}, {19,20}   // small
        }
    };
};

#endif
