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
        for (int r = -1; r < 2; r++) {
            for (int c = -1; c < 2; c++) {
                cv::Point2i n = q + cv::Point2i(r, c);
                if (img.at<uchar>(n) == old_color) {
                    frontier.push_back(n);
                    img.at<uchar>(n) = fill_color;
                }
            }
        }
    }
    
    return true;
}