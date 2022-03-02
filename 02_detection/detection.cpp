#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h>
#include <cstdio>
#include <cinttypes>
//#include <cstring>

#include "pxfuncs/pixelfuncs.hpp"
#include "connected_components.hpp"
#include "moment.hpp"
#include "pca.hpp"

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

    // step 3: region 
    int sz [2] = {3, 3};
    cv::SparseMat moments(2, sz, CV_64F);
    moments.ref<double>(0,0) = moment(label_image, 31, 0, 0);
    moments.ref<double>(0,1) = moment(label_image, 31, 0, 1);
    moments.ref<double>(1,0) = moment(label_image, 31, 1, 0);
    moments.ref<double>(1,1) = moment(label_image, 31, 1, 1);
    moments.ref<double>(2,0) = moment(label_image, 31, 2, 0);
    moments.ref<double>(0,2) = moment(label_image, 31, 0, 2);
    cv::SparseMatIterator miter = moments.begin();
    for(; miter != moments.end(); miter++) {
        printf("Moment = %.2f\n", miter.value<double>());
    }

    cv::Point2i cen(moments.value<double>(1,0)/moments.value<double>(0,0), moments.value<double>(0,1)/moments.value<double>(0,0));
    
    printf("centroid: (%" PRId32 ", %" PRId32 ")\n", cen.x, cen.y);
    
    cv::SparseMat central_moments(2, sz, CV_64F);
    central_moments.ref<double>(0, 0) = central_moment(label_image, 31, 0, 0);
    central_moments.ref<double>(1, 1) = central_moment(label_image, 31, 1, 1);
    central_moments.ref<double>(2, 0) = central_moment(label_image, 31, 2, 0);
    central_moments.ref<double>(0, 2) = central_moment(label_image, 31, 0, 2);
    
    
    printf("u_00 = %.2f\n", central_moments.ref<double>(0,0));
    printf("u_11 = %.2f\n",central_moments.ref<double>(1,1));
    printf("u_20 = %.2f\n", central_moments.ref<double>(2,0));
    printf("u_02 = %.2f\n", central_moments.ref<double>(0,2));
    


    // step 4: more region properties
    /* current issue here: bad moments makes us take the root of a negative number */
    std::pair<double, double> evals = eigen(central_moments);
    printf("eigenvalues: (%.2f, %.2f)\n", evals.first, evals.second);
    std::pair<double, double> lens = sm_ax_len(evals);
    printf("lengths: (%.2f, %.2f)\n", lens.first, lens.second);
    printf("direction: %.2f, eccentricity: %.2f\n", direction(central_moments), eccentricity(central_moments));

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