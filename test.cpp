// #include <opencv2/opencv.hpp>
// #include <iostream>
// using namespace cv;
// using namespace std;
// int main(void)
// {
//     Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
//     if (src.empty()) {cerr << "Image load failed!" << endl; return -1;}
//     Mat dst(src.rows, src.cols, src.type()); //행,열의 수, 타입을 소스와 동일하게
//     for (int j = 0; j < src.rows; j++) {
//         for (int i = 0; i < src.cols; i++) {
//             dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100;
//         }
//     }
//     imshow("src", src);
//     imshow("dst", dst);
//     waitKey();

//     return 0;
// }