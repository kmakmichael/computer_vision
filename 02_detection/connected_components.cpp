#include <inttypes.h>
#include <utility>

#include "connected_components.hpp"
#include "pxfuncs/pixelfuncs.hpp"

size_t cc_floodfill(cv::Mat &input, cv::Mat &output) {
    // setup
    size_t num_components = 0;
    output = cv::Mat::zeros(input.rows, input.cols, input.type());

    // iteration
    cv::MatConstIterator_<uchar> iter_end = output.end<uchar>();
    cv::MatConstIterator_<uchar> iter = output.begin<uchar>();
    cv::Point2i n;
    for(; iter != iter_end; iter++) {
        if(*iter == 0 && input.at<uchar>(iter.pos()) == 255) {
            n = iter.pos();
            num_components++;
            if (num_components > 8) {
                // horrible way of handling things but deal with that later
                fprintf(stderr, "more than 8 components\n");
                floodfill(input, output, n, 255);
            }
            printf("filling %zuth component with color %u\n", num_components, (uchar)(num_components*32-1));
            floodfill(input, output, n, (uchar)(num_components*32-1));
        }
    }
    return num_components;
}

size_t cc_union(cv::Mat &input, cv::Mat &output) {
    size_t num_components = 0;
    cv::Point2i up(0, -1);
    cv::Point2i left(-1, 0);
    std::vector<std::pair<uint16_t, uint16_t>> equiv;
    output = cv::Mat::zeros(input.rows, input.cols, input.type());
    cv::Mat c = cv::Mat::zeros(input.rows, input.cols, CV_16UC1);

    /* 
        first loop 
    */
    cv::MatConstIterator_<uchar> iter = input.begin<uchar>();
    cv::Point2i p, u, l;
    // do the first iteration by hand
    c.at<uint32_t>(cv::Point2i(0, 0)) = 0;
    equiv.push_back(std::make_pair(num_components, num_components));
    iter++;
    for(; iter != input.end<uchar>(); iter++) {
        p = iter.pos();
        l = p + left;
        u = p + up;
        if (p.y > 0 && *iter == input.at<uchar>(u)) {
            c.at<uint16_t>(p) = c.at<uint16_t>(u);
            if (p.x > 0 && *iter == input.at<uchar>(l)) {
                std::pair<uint16_t, uint16_t> e = std::make_pair(c.at<uint16_t>(u), c.at<uint16_t>(l));
                if (find(equiv.begin(), equiv.end(), e) == equiv.end() && *(equiv.end()) != e) {
                    //printf("equivalence made\n");
                    equiv.push_back(e);
                }
            }
        } else if (p.x > 0 && *iter == input.at<uchar>(l)) {
            c.at<uint16_t>(p) = c.at<uint16_t>(l);
        } else {
            c.at<uint16_t>(p) = ++num_components;
            equiv.push_back(std::make_pair(num_components, num_components));
        }
    }
    for(int i = 0; i < equiv.size(); i++) {
        //printf("(%d, %d)\n", equiv[i].first, equiv[i].second);
    }
    //printf("found %zu components\n", num_components);
    return num_components;
}