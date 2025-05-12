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
    Mat dst1;
    Mat dst2;

    filter2D(src, dst1, -1, emboss, Point(-1, -1), 0);
    filter2D(src, dst2, -1, emboss, Point(-1, -1), 128);

    imshow("src", src);
    imshow("dst delta 0", dst1);
    imshow("dst delta 128", dst2);

    waitKey();

    return 0;
}