#include "proc.hpp"


cv::Mat1f suppress(cv::Mat1f direction, cv::Mat1f magnitude) {
    cv::Mat1f supp = cv::Mat::zeros(direction.rows, direction.cols, CV_32FC1);
    float theta = 0;
    cv::Point2i up(0,-1), down(0,1), left(-1,0), right(0,-1);
    for (auto s = supp.begin(); s != supp.end(); s++) {
        theta = direction.at<float>(s.pos());
        if (theta < 0) {
            theta += M_PI;
        }
        theta *= (180.0 / M_PI);
        *s = magnitude.at<float>(s.pos().x, s.pos().y);
        if (theta <= 22.5 || theta > 157.5) {
            // top
            if (s.pos().y > 0) {
                if (magnitude.at<float>(s.pos()) < magnitude.at<float>(s.pos() + up)) {
                    *s = 0;
                }
            }
            // bottom
            if (s.pos().y < supp.rows-1) {
                if (magnitude.at<float>(s.pos()) < magnitude.at<float>(s.pos() + down)) {
                    *s = 0;
                }
            }
        } else if (theta > 22.5 && theta <= 67.5) {
            //topleft
            if (s.pos().y > 0 && s.pos().x > 0) {
                if (magnitude.at<float>(s.pos()) < magnitude.at<float>(s.pos() + up + right)) {
                    *s = 0;
                }
            }
            // bottomright
            if (s.pos().y < supp.rows-1 && s.pos().x < supp.cols-1) {
                if (magnitude.at<float>(s.pos()) < magnitude.at<float>(s.pos() + down + right)) {
                    *s = 0;
                }
            }
        } else if (theta > 67.5 && theta <= 112.5) {
            // left
            if (s.pos().x > 0) {
                if (magnitude.at<float>(s.pos()) < magnitude.at<float>(s.pos() + left)) {
                    *s = 0;
                }
            }
            // right
            if (s.pos().x < supp.cols-1) {
                if (magnitude.at<float>(s.pos()) < magnitude.at<float>(s.pos() + right)) {
                    *s = 0;
                }
            }
        } else if (theta > 112.5 && theta <= 157.5) {
            // topright
            if (s.pos().y > 0 && s.pos().x < supp.cols-1) {
                if (magnitude.at<float>(s.pos()) < magnitude.at<float>(s.pos() + up + right)) {
                    *s = 0;
                }
            }
            // bottomleft
            if (s.pos().y < supp.rows-1 && s.pos().x > 0) {
                if (magnitude.at<float>(s.pos()) < magnitude.at<float>(s.pos() + down + left)) {
                    *s = 0;
                }
            }
        }
    }
    return supp;
}