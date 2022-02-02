#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat grey = imread("images/fruit1.bmp", 0);
    namedWindow("some fruits", WINDOW_AUTOSIZE );
    imshow("some fruits", grey);
    waitKey(0);
    return 0;
}