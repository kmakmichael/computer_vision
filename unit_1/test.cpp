#include <opencv2/opencv.hpp>
#include <iostream>

#include "histeq.hpp"

#define file_out "out.bmp"
#define file_in "images/fruit1.bmp"


int main(int ac, char** av) {
    bool result;

    cv::Mat grey = cv::imread(file_in, cv::IMREAD_GRAYSCALE);
    if  (grey.empty()) {
        return 1;
    }
    
    result = cv::imwrite(file_out, grey);
    if (!result) {
        return 1;
    }
    return 0;
}