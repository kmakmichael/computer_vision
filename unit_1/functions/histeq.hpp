#ifndef HISTEQ_H
#define HISTEQ_H

#include <opencv2/core/mat.hpp>
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

#endif