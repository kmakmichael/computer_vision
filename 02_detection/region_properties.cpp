#include "region_properties.hpp"


// helper functions
int32_t moment_x(cv::Mat &region, uchar color, uint8_t p);
int32_t moment_y(cv::Mat &region, uchar color, uint8_t q);
int32_t moment_00(cv::Mat &region, uchar color);

int32_t moment(cv::Mat &region, uchar color, uint8_t p, uint8_t q) {
    if (!p && !q) {
        return moment_00(region, color);
    }
    if (!p) {
        return moment_y(region, color, q);
    } 
    if (!q) {
        return moment_x(region, color, p);
    }
    int32_t sum = 0;
    cv::MatConstIterator_<uchar> iter = region.begin<uchar>();
    for(; iter != region.end<uchar>(); iter++) {
        if (*iter == color) {
            sum += pow(iter.pos().x, p) * pow(iter.pos().y, q);
        }
    }
    return sum;
}

int32_t moment_x(cv::Mat &region, uchar color, uint8_t p) {
    int32_t sum = 0;
    cv::MatConstIterator_<uchar> iter = region.begin<uchar>();
    for(; iter != region.end<uchar>(); iter++) {
        if (*iter == color) {
            sum += pow(iter.pos().x, p);
        }
    }
    return sum;
}

int32_t moment_y(cv::Mat &region, uchar color, uint8_t q) {
    int32_t sum = 0;
    cv::MatConstIterator_<uchar> iter = region.begin<uchar>();
    for(; iter != region.end<uchar>(); iter++) {
        if (*iter == color) {
            sum += pow(iter.pos().y, q);
        }
    }
    return sum;
}

int32_t moment_00(cv::Mat &region, uchar color) {
    int32_t sum = 0;
    cv::MatConstIterator_<uchar> iter = region.begin<uchar>();
    for(; iter != region.end<uchar>(); iter++) {
        if (*iter == color) {
            sum += 1;
        }
    }
    return sum;
}