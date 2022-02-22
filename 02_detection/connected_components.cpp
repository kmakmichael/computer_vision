#include "connected_components.hpp"
#include "pxfuncs/pixelfuncs.hpp"

size_t cc_floodfill(cv::Mat &input, cv::Mat &output) {
    // setup
    size_t num_components = 0;
    output = cv::Mat::zeros(input.rows, input.cols, input.type());

    // iteration
    cv::MatConstIterator_<uchar> iter_end = output.end<uchar>();
    cv::MatIterator_<uchar> iter = output.begin<uchar>();
    cv::Point2i n;
    for(; iter != iter_end; iter++) {
        if(*iter == 0 && input.at<uchar>(iter.pos()) == 255) {
            n = iter.pos();
            floodfill(input, output, n, 128);
            num_components++;
        }
    }
    return num_components;
}

size_t cc_union(cv::Mat &input, cv::Mat &output) {
    size_t num_components = 0;
    return num_components;
}