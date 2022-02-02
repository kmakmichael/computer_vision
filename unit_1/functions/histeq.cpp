#include "histeq.hpp"

bool histeq(cv::Mat &img) {
    uint32_t pdf[256] = {};
    uint32_t cdf[256] = {};
    // calculate pdf
    cv::MatConstIterator_<uchar> iter_end = img.end<uchar>();
    cv::MatIterator_<uchar> iter = img.begin<uchar>();
    for(; iter != iter_end; iter++) {
        pdf[*iter]++;
    }
    // calculate cdf
    cdf[0] = pdf[0];
    for(size_t i = 1; i < 256; i++) {
        cdf[i] = cdf[i-1] + pdf[i];
    }

    // apply equalization
    cv::MatConstIterator_<uchar> iter_begin = img.begin<uchar>();
    for(; iter != iter_begin; iter--) {
        *iter = 255 * (cdf[*iter] / (float) img.total());
    }
    return true;
}