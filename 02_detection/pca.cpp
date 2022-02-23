#include "pca.hpp"

std::pair<double, double> eigen(cv::Mat &img, uchar color) {
    double e1, e2;
    double u_00 = central_moment(img, color, 0, 0);
    double u_20 = central_moment(img, color, 2, 0);
    double u_02 = central_moment(img, color, 0, 2);
    double u_11 = central_moment(img, color, 1, 1);

    double sq = sqrt(pow(u_20-u_02, 2) - pow(2*u_11, 2));
    e1 = (u_20 + u_02 + sq) / (2*u_00);
    e2 = (u_20 + u_02 - sq) / (2*u_00);
    return std::make_pair(e1, e2);
}

std::pair<double, double> sm_ax_len(std::pair<double, double> evals) {
    return std::make_pair(2*sqrt(evals.first), 2*sqrt(evals.second));
}