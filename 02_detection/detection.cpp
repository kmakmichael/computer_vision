#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h>
#include <cstdio>
#include <cinttypes>
//#include <cstring>

#include "pxfuncs/pixelfuncs.hpp"
#include "connected_components.hpp"
#include "moment.hpp"

#define WRITE_IMGS

/*
    Fruit detection
*/
void seperation(cv::Mat &img);
void show_img(cv::Mat &img, const char *title, const char *filename);

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

    // step 3: region properties
    float m_00 = moment(label_image, 31, 0, 0);
    float m_01 = moment(label_image, 31, 0, 1);
    float m_10 = moment(label_image, 31, 1, 0);
    float m_11 = moment(label_image, 31, 1, 1);
    float m_20 = moment(label_image, 31, 2, 0);
    float m_02 = moment(label_image, 31, 0, 2);
    cv::Point2i cen(m_10/m_00, m_01/m_00);
    
    printf("Moment 00: %.2f\n", m_00);
    printf("Moment 01: %.2f\n", m_01);
    printf("Moment 10: %.2f\n", m_10);
    printf("Moment 11: %.2f\n", m_11);
    printf("Moment 20: %.2f\n", m_20);
    printf("Moment 02: %.2f\n", m_02);
    printf("centroid: (%" PRId32 ", %" PRId32 ")\n", cen.x, cen.y);
    
    float u_00 = central_moment(label_image, 31, 0, 0);
    float u_10 = central_moment(label_image, 31, 1, 0);
    float u_20 = central_moment(label_image, 31, 2, 0);
    float u_02 = central_moment(label_image, 31, 0, 2);
    
    printf("u_00 = %.2f (%.2f)\n", u_00, m_00);
    printf("u_10 = %.2f (%.2f, %.2f)\n", u_10, m_11 - cen.y*m_10, m_11 - cen.x*m_01);
    printf("u_20 = %.2f (%.2f)\n", u_20, m_20 - cen.x*m_10);
    printf("u_02 = %.2f (%.2f)\n", u_02, m_02 - cen.y*m_01);

    // step 4: more region properties

    // step 5: wall-following

    // step 6: classification

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

void show_img(cv::Mat &img, const char *title, const char *filename) {
    #ifdef WRITE_IMGS
        printf("writing to %s\n", title);
        cv::imwrite(filename, img);
    #endif
    cv::namedWindow(title, cv::WINDOW_AUTOSIZE);
    cv::imshow(title, img);
}