#include<opencv2/opencv.hpp>

#define file_out "out.bmp"
#define file_in "images/fruit1.bmp"


using namespace std;
using namespace cv;

int main() {
    bool result;

    Mat grey = imread(file_in, IMREAD_GRAYSCALE);
    if  (grey.empty()) {
        cout << "Failed to load " << file_in << endl;
    }

    result = imwrite(file_out, grey);
    if (!result) {
        cout << "Failed to write " << file_out << endl;
    }
    return 0;
}