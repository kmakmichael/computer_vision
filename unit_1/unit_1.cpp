#include <opencv2/opencv.hpp>
#include <cstdio>
#include <cstring>

#include "functions/histeq.hpp"

/*
 * Test program for 7 different pixel processing functions
 *  usage: test <function> <input> <output>
 *
 *  functions:
 *      histeq: histogram equalization
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
    //char *file_out = argv[3];

    // read the given image
    cv::Mat img = cv::imread(file_in, cv::IMREAD_GRAYSCALE);
    if  (img.empty()) {
        return 1;
    }
    
    // call the proper function
    if (!strcmp(func, "histeq")) {
        fprintf(stdout, "running histeq\n");
        result = histeq(img);
    } else {
        fprintf(stderr, "%s is not a valid function\n", func);
        return 1;
    }

    // error checking
    if (!result) {
        fprintf(stderr, "unable to perform %s on %s", func, file_in);
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