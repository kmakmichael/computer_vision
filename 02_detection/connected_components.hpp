#ifndef CONNCOM_H
#define CONNCOM_H

#include <opencv2/core/mat.hpp>
#include <cstdint>

void cc_floodfill(cv::Mat &input);
void cc_union(cv::Mat &input);

#endif