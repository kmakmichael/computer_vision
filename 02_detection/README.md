## Project 2: Object Classification
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

# Overview
Project 2 uses the functions from Project 1 in conjunction with new ones to classify apples, tangerines, and bananas in the provided fruit images.
The relevant functions are split between several `.hpp` files, titled according to their function.

# Implementation
(expand on this)
First, the foreground and background are separated via double thresholding followed by erosion and dilation.
The thresholding marks a rough difference between foreground and background, and the erosion and dilation help to clean the noise and smooth the edges.


## Bugs & Errors


