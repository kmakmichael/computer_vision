#ifndef FLOODFILLF_H
#define FLOODFILLF_H

#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>


bool floodfill_f(cv::Mat &img, cv::Point2i seed, uchar fill_color);

#endif