#include <opencv2/opencv.hpp>
#include <stdlib.h>
/*
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <cinttypes>
#include <cstdio>
*/

#define WRITE_IMGS

void show_img(cv::Mat &img, const char *title, const char *filename);

int main(int argc, char *argv[]) {

    // handle params
	if (argc > 4 || argc == 1) {
		fprintf(stderr, "usage: canny <image> <sigma> <template match (optional)>\n");
		return 1;
	}

    char *file_in = argv[1];
    float sigma;

    if (argc > 2) {
        sigma = atof(argv[2]);
        printf("sigma = %f", sigma);
    } else {
        sigma = 1.0;
        printf("no sigma given, assuming %f\n", sigma);
    }

    // read the given image
    cv::Mat original = cv::imread(file_in, cv::IMREAD_GRAYSCALE);
    if  (original.empty()) {
        return 1;
    }

    if (argc == 4) {
        // probably call a seperate function for this vs non-matching
        printf("template image given: %s\n", argv[4]);
    } else {
        printf("not performing templating\n");
    }

    // cv::Mat img_color = cv::imread(file_in, cv::IMREAD_COLOR);

    show_img(original, "Original", "original.bmp");

}

void show_img(cv::Mat &img, const char *title, const char *filename) {
    #ifdef WRITE_IMGS
        printf("writing to %s\n", title);
        cv::imwrite(filename, img);
    #endif
    cv::namedWindow(title, cv::WINDOW_AUTOSIZE);
    cv::imshow(title, img);
}
