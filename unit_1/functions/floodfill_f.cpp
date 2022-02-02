#include "floodfill_f.hpp"

bool floodfill_f(cv::Mat &img, cv::Point2i seed, uchar fill_color) {
    std::vector<cv::Point2i> frontier;
    cv::Point2i up(-1,0);
    cv::Point2i down(1,0);
    cv::Point2i left(0,-1);
    cv::Point2i right(0,1);

    uchar old_color = img.at<uchar>(seed);
    frontier.push_back(seed);
    img.at<uchar>(seed) = fill_color;
    while (frontier.size() != 0) {
        cv::Point2i q = frontier.back();
        frontier.pop_back();
    }
    
    return true;
}