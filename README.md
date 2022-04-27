# ECPE 291: Computer Vision
Results from a guided independent study course regarding computer vision techniques.

report - due Apr 27
    about 2 pages per program
    explain code, bugs, errors, etc
    guide for students
    include github link

## Installation and Usage of OpenCV
ahem
## OpenCV Basics
   The basis of OpenCV's library is the `Mat`, which defines a matrix of arbitrary dimensions.
The `Mat` object itself defines a header that points to a region of memory containing the data, allowing the user to edit the matrix, make sub-matrices, and more without having to fully re-allocate.
OpenCV handles all of the memory allocations and garbage collection, so there's no worrying about missing a `malloc()` or `free()`.
`Mat` also has static Matlab-style initializers like `Mat::zeros()` and `Mat::ones()`.
The type of a `Mat` can be one of many that OpenCV offers, typically defined as `CV_[bits][type]C[channels]`.
For example, these projects make frequent use of `CV_8UC1` - a 1-channel unsigned character matrix - for grayscale images.
Several predefined `Mat` types are also available, though are not used until Project 3.
The above example can be assigned to a `Mat1b` - a Mat that holds `uchar`.
These are more convenient than the templated `Mat_` for functions that only work in grayscale or color, not both.

There are several ways to access data in a `Mat`.
The `Mat::at()` function provides a reference to an element at a certain position, and the `Mat::ptr()` similarly provides a pointer to an element.
These functions can be called with a variety of arguments, and I found `at(int row, int col)` and `at(Point p)` to be the most useful.
The `Point` class defines a 2D coordinate.
Similar to `Mat`, there are some predefined Point types, and I found `Point2i` (integer coordinates) to be the most useful since we're working with pixels.
 
The `MatIterator` classes are also helpful for accessing data with these matrices.
They can be most easily accessed with the `Mat.begin()` and `Mat.end()` functions.
`MatIterators` are smart enough to iterate in order and will not get lost if the `Mat`'s data does not occupy a continuous chunk of memory.
They're compatible with STL functions like `sort()`, since they're random access iterators, which was useful for the implementation of hysteresis in Project 3.

## Project 1: Pixel Processing Functions
copy the overview (& link each project's readme?)

## Project 2: Object Classification


## Project 3: Canny Edge Detection


## Project 4: Mosaicking
  


