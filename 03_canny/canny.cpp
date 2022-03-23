#include <opencv2/opencv.hpp>
#include <stdlib.h>
/*
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <cinttypes>
#include <cstdio>
*/
#include "kernels.hpp"
#include "convolution.hpp"

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
    cv::Mat1b original = cv::imread(file_in, cv::IMREAD_GRAYSCALE);
    if  (original.empty()) {
        return 1;
    }

    if (argc == 4) {
        // probably call a seperate function for this vs non-matching
        printf("template image given: %s\n", argv[4]);
        cv::Mat1f h_kern = gaussian(sigma);
    } else {
        printf("not performing templating\n");
        cv::Mat1f h_kern = gaussian(sigma);
        cv::Mat1f v_kern;
        cv::transpose(h_kern, v_kern);
        cv::Mat1f h_deriv = deriv(sigma);
        cv::Mat1f v_deriv;
        cv::transpose(h_deriv, v_deriv);
        cv::Mat1f temp = convolve<uchar>(original, h_kern);
        cv::Mat1f temp_h = convolve<float>(temp, h_deriv);
        temp = convolve<uchar>(original, v_kern);
        cv::Mat1f temp_v = convolve<float>(temp, v_deriv);
        show_img(temp_h, "Temp Hori", "temp_h.bmp");
        show_img(temp_v, "Temp Vert", "temp_v.bmp");
    }

    // cv::Mat img_color = cv::imread(file_in, cv::IMREAD_COLOR);
}

void show_img(cv::Mat &img, const char *title, const char *filename) {
    #ifdef WRITE_IMGS
        printf("writing to %s\n", filename);
        cv::imwrite(filename, img);
    #endif
    cv::namedWindow(title, cv::WINDOW_AUTOSIZE);
    cv::imshow(title, img);
}
