#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h>
#include <cstdio>
//#include <cstring>

#include "pxfuncs/pixelfuncs.hpp"
#include "connected_components.hpp"

#define WRITE_IMGS

/*
    Fruit detection
*/
void seperation(cv::Mat &img);

int main(int argc, char *argv[]) {

    // handle params
	if (argc != 2) {
		fprintf(stderr, "usage: test <image>\n");
		return 1;
	}

    char *file_in = argv[1];

    // read the given image
    cv::Mat gray = cv::imread(file_in, cv::IMREAD_GRAYSCALE);
    if  (gray.empty()) {
        return 1;
    }

    // step 1: bg seperation
    seperation(gray);

    // step 2: connected components
    char ffill;
    printf("Floodfill or Union? (f/u)\n");
    scanf("%c", &ffill);
    std::fflush(stdin);
    if (ffill == 'F') {ffill = 'f';}
    if (ffill == 'U') {ffill = 'u';}
    while (ffill != 'f' && ffill != 'u') {
        printf("bad input\n");
        printf("Floodfill or Union? (f/u)\n");
        scanf("%c", &ffill);
        std::fflush(stdin);
        if (ffill == 'F') {ffill = 'f';}
        if (ffill == 'U') {ffill = 'u';}
    }
    if (ffill == 'f') {
        cc_floodfill(gray);
    } else {
        cc_union(gray);
    }

    // step 3: region properties

    // step 4: moments

    // step 5: wall-following

    // step 6: classification

    #ifdef WRITE_IMGS
        printf("writing to clean_thresh.bmp\n");
        cv::imwrite("clean_thresh.bmp", gray);
    #endif
    cv::namedWindow("Clean Threshold Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Clean Threshold Image", gray);
}


void seperation(cv::Mat &img) {
    cv::Mat temp1 = img.clone();
    cv::Mat temp2 = img.clone();
    double_thresh(img, temp1);
    histeq(img);
    erosion(temp1, temp2, true);
    dilation(temp2, temp1, true);
    temp1.copyTo(img);
}