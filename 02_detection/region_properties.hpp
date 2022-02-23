#ifndef RPROPS_H
#define RPROPS_H

#include <opencv2/opencv.hpp>
#include <cmath>

int32_t moment(cv::Mat &region, uchar color, uint8_t p, uint8_t q);


#endif