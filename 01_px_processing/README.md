# Project 1: Pixel Processing Functions
## Compile and Run:
To compile, make sure you have `cmake` installed:
```
cmake --build .
make
```
To run:
```
./px_processing <input image> <test>
```
Accepted values of `<test>`:
- floodfill
- thresh
- morph
- all

## Overview
This project performs a variety of pixel processing functions useful for image processing algorithms.
The functions are accessed via functions/pixelfuncs.hpp, and split into several implementation files.

## Implementation
### Histogram Equalization
`void histeq(cv::Mat &img)`
First calculates the PDF of the image, then the CDF.
Uses the CDF's value to normalize the values.


### Floodfill
`void floodfill(cv::Mat &img_in, cv::Mat &img_out, cv::Point2i &seed, uchar fill_color)`
Fills a region in `img_out` according to regions of `in`.
Uses the frontier fill formula, with the frontier implemented as a vector of `Point2i`.

`void floodfill(cv::Mat &img_in, cv::Point2i &seed, uchar fill_color)`
in-place version of above.


### Thresholding


### Morphology


## Bugs & Errors
