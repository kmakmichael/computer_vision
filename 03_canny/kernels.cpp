#include "kernels.hpp"

cv::Mat1f gaussian(float sigma) {
    int a = round(2.5 * sigma - 0.5);
    printf("preparing kernel of length %d\n", 2*a+1);
    cv::Mat1f kern(1, 2*a+1, CV_16FC1);
    float sum = 0;
    for (auto i = kern.begin(); i != kern.end(); i++) {
        *i = exp((-1.0 * (i.pos().x-a) * (i.pos().x-a)) / (2.0 * sigma * sigma));
        sum += *i;
    }
    for (auto i = kern.begin(); i != kern.end(); i++) {
        *i /= sum;
    }
    return kern;
}

cv::Mat1f deriv(float sigma) {
    int a = round(2.5 * sigma - 0.5);
    printf("preparing deriv kernel of length %d\n", 2*a+1);
    cv::Mat1f kern(1, 2*a+1, CV_16FC1);
    float sum = 0;
    for (auto i = kern.begin(); i != kern.end(); i++) {
        *i = -1.0 * (i.pos().x-a) * exp((-1.0 * (i.pos().x-a) * (i.pos().x-a)) / (2.0 * sigma * sigma));
        sum -= *i * i.pos().x;
    }
    for (auto i = kern.begin(); i != kern.end(); i++) {
        *i /= sum;
    }
    // kernel flipping
    for (int i = 0; i < (kern.cols/2); i++) {
        float temp = kern.at<float>(1,kern.cols-1-i);
        kern.at<float>(1,kern.cols-1-i) = kern.at<float>(1,i);
        kern.at<float>(1,i) = temp;
    }
    return kern;
}

void print_kern(cv::Mat1f kern) {
    printf("Kernel: [ ");
    for (int r = 0; r < kern.rows; r++) {
        for (int c = 0; c < kern.cols; c++) {
            printf("%f ", kern.at<float>(r,c));
        }
        printf("\n");
    }
    printf("]\n");
}