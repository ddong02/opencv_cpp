#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(void)
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
     }
    float alpha = 1.f;
    Mat dst = Mat(src.rows, src.cols, src.type());

    uchar src_pixel;
    for (int row = 0; row < src.rows; row++) {
        for (int col = 0; col < src.cols; col++) {
            src_pixel = src.at<uchar>(row, col);
            dst.at<uchar>(row, col)
                = saturate_cast<uchar>(src_pixel + (src_pixel - 128) * alpha);
        }
    }

    imshow("src", src);
    imshow("dst", dst);
    waitKey();
return 0;
}
