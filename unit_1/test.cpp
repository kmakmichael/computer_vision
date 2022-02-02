#include <opencv2/opencv.hpp>
#include "histeq.hpp"
#include <iostream>

using namespace cv;

#define file_out "out.bmp"
#define file_in "images/fruit1.bmp"


int main() {
    bool result;

    Mat grey = imread(file_in, IMREAD_GRAYSCALE);
    if  (grey.empty()) {
        return 1;
    }
    
    result = imwrite(file_out, grey);
    if (!result) {
        return 1;
    }
    return 0;
}