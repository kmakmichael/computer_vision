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
    cv::Mat deriv(2*a+1, 1, CV_16FC1);
    return deriv;
}

void print_kern(cv::Mat1f kern) {
    printf("Kernel: [ ");
    for (auto i = kern.begin(); i != kern.end(); i++) {
        printf("%f ", *i);
    }
    printf("]\n");
}