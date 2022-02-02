#include "floodfill_f.hpp"

bool floodfill_f(cv::Mat &img, cv::Point_<uchar> seed, uchar fill_color) {
    std::vector<cv::Point_<uchar>> frontier;
    cv::Point_<uchar> up(-1,0);
    cv::Point_<uchar> down(1,0);
    cv::Point_<uchar> left(0,-1);
    cv::Point_<uchar> right(0,1);

    uchar old_color = img.at<uchar>(seed);
    frontier.push_back(seed);

    std::printf("Seed is %d at (%d, %d), front has %zu members\n", old_color, seed.x, seed.y, frontier.size());
    return true;
}