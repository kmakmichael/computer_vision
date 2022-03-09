#include "wall.hpp"


// helper functions
cv::Point2i find_start(cv::Mat &img, uchar color);


cv::Mat wall(cv::Mat &img, uchar color) {
    cv::Mat mask = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
    cv::Point2i start = find_start(img, color);
    printf("starting at (%d, %d)\n", start.x, start.y);
    mask.at<uchar>(start) = 255;
    return mask;
}


cv::Point2i find_start(cv::Mat &img, uchar color) {
    cv::MatConstIterator_<uchar> iter_end = img.end<uchar>();
    cv::MatIterator_<uchar> iter = img.begin<uchar>();
    for(; iter != iter_end; iter++) {
        if (*iter == color) {
            return iter.pos();
        }
    }
}