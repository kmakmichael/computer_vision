#ifndef PCA_H
#define PCA_H

#include <utility>
#include <cmath>
#include <opencv2/core/mat.hpp>

#include "moment.hpp"

std::pair<double, double> eigen(cv::Mat &img, uchar color);
std::pair<double, double> eigen(cv::SparseMat &u);
std::pair<double, double> sm_ax_len(std::pair<double, double> evals);

#endif