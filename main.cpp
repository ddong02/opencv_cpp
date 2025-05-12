#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(void)
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1;}

    float data[] = {
        -1, 0, 1,
        -2, 0, 2,
        -1, 0, 1
    };

    Mat emboss(3, 3, CV_32FC1, data);
    Mat dst;

    filter2D(src, dst, -1, emboss, Point(-1, -1), 128);

    imshow("src", src);
    imshow("dst", dst);

    waitKey();

    return 0;
}