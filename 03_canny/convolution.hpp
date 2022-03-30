#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include <opencv2/opencv.hpp>

template <typename T>
cv::Mat1f convolve(cv::Mat_<T> img, cv::Mat1f kern) {
    cv::Mat1f conv(img.rows, img.cols, CV_32FC1);
    cv::Point2i p;
    cv::Point2i kshift(kern.rows/2, kern.cols/2);
    for (auto i = conv.begin(); i != conv.end(); i++) {
        float sum = 0;
        for (auto k = kern.begin(); k != kern.end(); k++) {
            p = i.pos() - kshift + k.pos();
            if (p.x >= 0 && p.y >= 0 && p.x < img.cols && p.y < img.rows) {
                // printf("[%0.2f*%0.2f=%f]", static_cast<float>(img(p)),*k,static_cast<float>(img(p)) * (*k));
                sum += static_cast<float>(img(p)) * (*k);
            }
        }
        *i = sum;
        // printf("\n\t-->%f\n", *i);
    }
    return conv;
}

#endif