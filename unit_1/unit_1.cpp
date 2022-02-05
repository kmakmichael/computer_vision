#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h>
#include <cstdio>
#include <cstring>

#include "functions/pixelfuncs.hpp"

/*
    Test program for 7 different pixel processing functions
        usage: unit_1 <function> <input>
*/
int main(int argc, char *argv[]) {
    bool result;

    // handle params
	if (argc != 3) {
		fprintf(stderr, "usage: test <function> <input>\n");
		return 1;
	}

    char *func = argv[1];
    char *file_in = argv[2];

    // read the given image
    cv::Mat img = cv::imread(file_in, cv::IMREAD_GRAYSCALE);
    if  (img.empty()) {
        return 1;
    }
    
    // call the proper function
    fprintf(stdout, "running %s on %s\n", func, file_in);
    if (!strcmp(func, "histeq")) {
        result = histeq(img);
    } else if (!strcmp(func, "floodfill")) {
        result = floodfill(img, cv::Point2i(0,0), 255);
    } else if (!strcmp(func, "floodfill_new")) {

        cv::Mat new_img = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
        result = floodfill_new(img, new_img, cv::Point2i(0,0), 255);
        result = cv::imwrite("ffnew.bmp", new_img);
    } else if (!strcmp(func, "ridler-calvard")) {
        result = true;
        printf("rc = %u\n", ridler_calvard(img));
    } else {
        fprintf(stderr, "%s is not a valid function\n", func);
        return 1;
    }

    // error checking
    if (!result) {
        fprintf(stderr, "unable to perform %s on %s\n", func, file_in);
        return 1;
    }

    // show the result (doesn't work???)
    cv::namedWindow("output image", cv::WINDOW_AUTOSIZE);
    cv::imshow("output image", img);

    // write the result for now
    result = cv::imwrite("out.bmp", img);
    if (!result) {
        return 1;
    }
    return 0;
}