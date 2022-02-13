#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h>
#include <cstdio>
//#include <cstring>

#include "pxfuncs/pixelfuncs.hpp"

/*
    Fruit detection
*/

int main(int argc, char *argv[]) {

    // handle params
	if (argc != 3) {
		fprintf(stderr, "usage: test <input> <section>\n");
		return 1;
	}

    char *func = argv[2];
    char *file_in = argv[1];

    // read the given image
    cv::Mat img = cv::imread(file_in, cv::IMREAD_GRAYSCALE);
    if  (img.empty()) {
        return 1;
    }

    printf("no problems here\n");
}