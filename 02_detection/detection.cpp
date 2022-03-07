#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h>
#include <cstdio>
#include <cinttypes>
//#include <cstring>

#include "pxfuncs/pixelfuncs.hpp"
#include "connected_components.hpp"
#include "moment.hpp"
#include "pca.hpp"
#include "region.hpp"

#define WRITE_IMGS

/*
    Fruit detection
*/
void seperation(cv::Mat &img);
void show_img(cv::Mat &img, const char *title, const char *filename);
std::set<uchar> components(cv::Mat &region);

int main(int argc, char *argv[]) {

    // handle params
	if (argc != 2) {
		fprintf(stderr, "usage: test <image>\n");
		return 1;
	}

    char *file_in = argv[1];

    // read the given image
    cv::Mat original = cv::imread(file_in, cv::IMREAD_GRAYSCALE);
    if  (original.empty()) {
        return 1;
    }

    // step 1: bg seperation
    cv::Mat gray;
    original.copyTo(gray);
    seperation(gray);
    show_img(gray, "Clean Threshold Image", "clean_thresh.bmp");

    // step 2: connected components
    char ffill;
    cv::Mat label_image;
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
        cc_floodfill(gray, label_image);
    } else {
        cc_union(gray, label_image);
    }
    show_img(label_image, "Connected Components", "connected_components.bmp");

    // step 3: region 
    std::vector<region> objects = image_analysis(label_image);
    for (size_t i = 0; i < objects.size(); i++) {
        printf("\n== Region %zu ==\n", i);
        print_region_info(objects[i]);
    }


    // step 5: wall-following

    // step 6: classification

}


void seperation(cv::Mat &img) {
    cv::Mat temp1 = cv::Mat::zeros(img.rows, img.cols, img.type());
    cv::Mat temp2 = cv::Mat::zeros(img.rows, img.cols, img.type());
    double_thresh(img, temp1);
    erosion(temp1, temp2, true);
    dilation(temp2, temp1, true);
    temp1.copyTo(img);
}

void show_img(cv::Mat &img, const char *title, const char *filename) {
    #ifdef WRITE_IMGS
        printf("writing to %s\n", title);
        cv::imwrite(filename, img);
    #endif
    cv::namedWindow(title, cv::WINDOW_AUTOSIZE);
    cv::imshow(title, img);
}


std::set<uchar> components(cv::Mat &region) {
    std::set<uchar> colors;
    cv::MatConstIterator_<uchar> iter = region.begin<uchar>();
    for(; iter != region.end<uchar>(); iter++) {
        colors.insert(*iter);
    }
    return colors;
}