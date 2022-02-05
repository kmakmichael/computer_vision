#include "pixelfuncs.hpp"

bool floodfill(cv::Mat &img, cv::Point2i seed, uchar fill_color) {
    std::vector<cv::Point2i> frontier;

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

cv::Mat floodfill_new(cv::Mat &img, cv::Point2i seed, uchar fill_color) {
    std::vector<cv::Point2i> frontier;
    cv::Mat new_img = img.clone();

    uchar old_color = img.at<uchar>(seed);
    frontier.push_back(seed);
    new_img.at<uchar>(seed) = fill_color;
    while (frontier.size() != 0) {
        cv::Point2i q = frontier.back();
        frontier.pop_back();
        for (int r = -1; r < 2; r++) {
            for (int c = -1; c < 2; c++) {
                cv::Point2i n = q + cv::Point2i(r, c);
                if (img.at<uchar>(n) == old_color && new_img.at<uchar>(n) != fill_color) {
                    frontier.push_back(n);
                    new_img.at<uchar>(n) = fill_color;
                }
            }
        }
    }
    
    return new_img;
}