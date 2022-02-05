#ifndef PIXELFUNCS_H
#define PIEXLFUNCS_H

#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <cstdint>

/*
    performs histogram equalization on an image
 
    notes:
        could benefit from use of the Mat.setTo() function. Changing
        an array of pixels in parallel might be worth the overhead of
        storing a matrix of pixels with that value (pdf would be as 
        big as the original image at minimum to store all the indices)
 */
bool histeq(cv::Mat &img);

/*
    Floodfill
*/
bool floodfill(cv::Mat &img, cv::Point2i seed, uchar fill_color);
cv::Mat floodfill_new(cv::Mat &img, cv::Point2i seed, uchar fill_color);

/*
    Thresholding
*/
unsigned char ridler_calvard(cv::Mat &img);

#endif