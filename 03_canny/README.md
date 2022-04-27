## Project 3: Canny Edge Detection
## Compile and Run:
To compile, make sure you have `cmake` installed:
```
cmake --build .
make
```
To run:
```
./canny <image> <sigma> <template to match>
```

## Overview

## Implementation

## Bugs & Errors

# (temp)
Project 3 utilizes the canny edge detection algorithm to detect and illustrate the edges of an image.
For the kernels, I used horizontal and vertical `Mat`s.
When iterating through the image for convolution, I also iterate through the kernels, using their position as an offset.


