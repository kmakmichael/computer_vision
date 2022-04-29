# Project 2: Object Classification

## Overview
Project 2 uses the functions from Project 1 in conjunction with new ones to classify apples, tangerines, and bananas in the provided fruit images.
The relevant functions are split between several `.hpp` files, titled according to their function.

## Compile and Run:
To compile, make sure you have `cmake` installed:
```
cmake --build .
make
```
To run:
```
./detection <image>
```

## Implementation
First, the foreground and background are separated via double thresholding followed by erosion and dilation.
The thresholding marks a rough difference between foreground and background, and the erosion and dilation help to clean the noise and smooth the edges.
The connected components algorithm is implemented with both floodfill and union find.
The image is then split into objects and each is analyzed for its moments, central moments, eigenvalues, direction, and eccentricity.
For each object, the axis lengths are calculated and drawn onto the image before the wall-following function generates a mask of the object.
The object is classified from the eccentricity and eigenvalues, and the mask is then used to color the original image around the object's borders.

### Seperation
`void seperation(cv::Mat &img)`
Double thresholding followed by erosion and dilation help create clear seperation between foreground and background.
The process fails to get a clean seperation, unfortunately.

### Connected Components
`size_t cc_floodfill(cv::Mat &input, cv::Mat &output)`
Uses floodfill to seperate foreground and background.
The algorithm iterates through the output image and applies a floodfill at every point where the input pixel is ON (255) and the output pixel is not.
Thus, a floodfill is applied to every foreground object.
A color for this object is used according to how many objects have been filled so far.
After 8 objects, the code will just use `255` for the color.
This was so that the objects would be visible when I was checking the function's output and was never adjusted.

`size_t cc_union(cv::Mat &input, cv::Mat &output)`
The union find algorithm iterates through the image twice, checking the pixels above and to the left of each pixel.
Preprocessor macros `C(x)` and `I(x)` are used to make the code look a bit more like the math.
The first loop creates groups and equivalences between the groups, and the second loop replaces these equivalences.

The equivalence matrix is implemented as a vector, where the value stored at each index represents a single equivalence.
As group number increases, equivalences are applied within the vector.
The thought process here is that, when multiple equivalences exist, they can all be traced back to a common group.
This common group will be the smallest equivalence.
When a new equivalence is found, the table is checked and the new equivalence is stored only if it's smaller than the current.
In essence, the equivalence table is traversed and simplified during the loop rather than after.
However I have no idea if this logic really checks out because this function will sometimes split an object in two.
It's likely that some chains of equivalences are broken by changing the table before the first iteration's completion.

`uint16_t eq_search(const std::vector<uint16_t> &table, size_t idx)`
Recursively searches an equivalence table for the smallest value.

### Region Analysis


## Bugs & Errors
- Seperation is not clean
- Floodfill connected components only reliably handles 8 images
- Union find connected components "finds" extra objects and will count holes as objects
