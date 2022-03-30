#include "proc.hpp"


cv::Mat1f suppress(cv::Mat1f direction, cv::Mat1f magnitude) {
    cv::Mat1f supp(direction.rows, direction.cols, CV_32FC1);
    for (auto s = supp.begin(); s != supp.end(); s++) {
        // printf(" %f ", *s);
    }
    return supp;
}