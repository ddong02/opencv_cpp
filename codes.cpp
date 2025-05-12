/* 5-2

### 1

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void on_mouse(int event, int x, int y, int flags, void* param); 
int main(void)
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {cerr << "Image load failed!" << endl; return -1;}

    namedWindow("src");
    setMouseCallback("src", on_mouse, &src);

    while(true) {
        imshow("src",src);
        if (waitKey(5) != -1) break;
    }

    return 0;
}
void on_mouse(int event, int x, int y, int flags, void* param)
{
    Mat* img_ptr = (Mat*)param;
    if (event == EVENT_LBUTTONDOWN)
        *img_ptr += 10;
    else if (event == EVENT_RBUTTONDOWN)
        *img_ptr -= 10;
}

*/

/*

### 2

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void on_mouse(int event, int x, int y, int flags, void* param); 
int main(void)
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {cerr << "Image load failed!" << endl; return -1;}

    namedWindow("src");
    setMouseCallback("src", on_mouse, &src);

    while(true) {
        imshow("src",src);
        if (waitKey(5) != -1) break;
    }

    return 0;
}
void on_mouse(int event, int x, int y, int flags, void* param)
{
    Mat* img_ptr = (Mat*)param;
    static Point prev_pt;

    if (event == EVENT_LBUTTONDOWN)
        prev_pt = Point(x, y);
    else if (event == EVENT_LBUTTONUP) {
        if (prev_pt.x < x && prev_pt.y < y)
            (*img_ptr)(Range(prev_pt.y, y), Range(prev_pt.x, x)) += 100;
    }
}



*/

/*

### 3

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

struct Mydata {
    int pos;
    Mat* src_ptr;
};

void on_mouse(int event, int x, int y, int flags, void* userdata);
void on_trackbar(int pos, void* userdata);

int main(void)
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {cerr << "Image load failed!" << endl; return -1;}

    int pos = 0;
    Mydata mydata = {pos, &src};

    namedWindow("src");
    setMouseCallback("src", on_mouse, &mydata);
    createTrackbar("mode", "src", 0, 1, on_trackbar, &mydata);

    while(true) {
        imshow("src",src);
        if (waitKey(5) != -1) break;
    }

    return 0;
}
void on_trackbar(int pos, void* userdata)
{
    ((Mydata*)userdata)->pos = pos;
}
void on_mouse(int event, int x, int y, int flags, void* userdata)
{
    Mydata* data_ptr = (Mydata*)userdata;
    Mat src = *(data_ptr->src_ptr);
    if (event == EVENT_LBUTTONDOWN)
        src = data_ptr->pos ? src - 10 : src + 10;
}


*/

/*

### 4

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void on_mouse(int event, int x, int y, int flags, void* userdata);

int main(void)
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {cerr << "Image load failed!" << endl; return -1;}

    namedWindow("src");
    setMouseCallback("src", on_mouse, &src);

    while(true) {
        imshow("src",src);
        if (waitKey(5) != -1) break;
    }

    return 0;
}

void on_mouse(int event, int x, int y, int flags, void* userdata)
{
    Mat src = *((Mat*)userdata);
    int pixel_change = 100;

    if (event == EVENT_MOUSEMOVE) {
        if (flags & EVENT_FLAG_LBUTTON) {
            cout << "Event occured" << endl;
            src.at<uchar>(y, x) = saturate_cast<uchar>(src.at<uchar>(y, x) + pixel_change);
            src.at<uchar>(y-1, x) = saturate_cast<uchar>(src.at<uchar>(y-1, x) + pixel_change);
            src.at<uchar>(y+1, x) = saturate_cast<uchar>(src.at<uchar>(y+1, x) + pixel_change);
            src.at<uchar>(y, x-1) = saturate_cast<uchar>(src.at<uchar>(y, x-1) + pixel_change);
            src.at<uchar>(y, x+1) = saturate_cast<uchar>(src.at<uchar>(y, x+1) + pixel_change);
        }
    }
}

*/

/*  5-2

### 1

### 2
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

*/