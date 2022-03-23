#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include <opencv2/opencv.hpp>

template <typename T>
cv::Mat1f convolve(cv::Mat_<T> img, cv::Mat1f kern) {
    cv::Mat1f conv(img.rows, img.cols, CV_16FC1);
    cv::Point2i p;
    for (auto i = conv.begin(); i != conv.end(); i++) {
        float sum = 0;
        for (auto k = kern.begin(); k != kern.end(); k++) {
            p = i.pos() + k.pos();
            if (p.x >= 0 && p.y >= 0 && p.x < img.cols && p.y < img.rows) {
                sum += static_cast<float>(img(p)) * (*k);
            }
        }
        *i = sum;
    }
    return conv;
}

#endif