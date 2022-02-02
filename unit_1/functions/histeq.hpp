#ifndef HISTEQ_H
#define HISTEQ_H

#include<opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include <cstdint>

// performs histogram equalization on an image
bool histeq(cv::Mat &img);

#endif