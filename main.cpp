// 1. contours 객체의 모든 점들 중에서 x, y 좌표의 최대, 최솟값을 구한다.
// 2. 저장된 x값의 중간 값을 구한다.
// 3. 저장된 x값의 최솟값~중간값, 중간값~최댓값을 기준으로 두 개의 ROI로 나눈다
//    이때, ROI의 y값은 contours 객체의 범위를 벗어나지 않도록 최솟값~최댓값으로 설정
// 4. 나눠진 ROI를 findContours() 함수를 통해 객체를 검출한다.
// 5. 열린 부분이 포함된 ROI는 그렇지 않은 ROI보다 객체가 하나 더 많을 것이다.
// 6. 이를 이용하여 열린 부분의 방향을 구할 수 있다.
// 7. 위, 아래로 열린 곡선은 x, y 기준을 바꿔 동일하게 구할 수 있다.

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(void)
{
    Mat src = imread("images/char_c.png", IMREAD_GRAYSCALE);
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1;}
    Mat bin;
    threshold(src, bin, 128, 255, THRESH_BINARY_INV);
    // 객체 검출을 위해 검은 배경에 흰 객체가 되도록 이진화
    vector<vector<Point>> contours;
    findContours(bin, contours, RETR_LIST, CHAIN_APPROX_NONE);

    int max_x, min_x, max_y, min_y;
    int middle_x;
    vector<vector<Point>> roi_contours;
    Mat roi_left, roi_right;
    int l_roi_contours_size, r_roi_contours_size;

    Mat dst;
    cvtColor(src, dst, COLOR_GRAY2BGR);

    for (int contour_index=0; contour_index<contours.size(); contour_index++)
    {
        for (int i=0; i<contours[contour_index].size(); i++)
        {
            if (!i) {
                max_x = min_x = contours[contour_index][i].x;
                max_y = min_y = contours[contour_index][i].y;
                continue;
            }
            if (max_x < contours[contour_index][i].x)
                max_x = contours[contour_index][i].x;
            if (min_x > contours[contour_index][i].x)
                min_x = contours[contour_index][i].x;
            if (max_y < contours[contour_index][i].y)
                max_y = contours[contour_index][i].y;
            if (min_y > contours[contour_index][i].y)
                min_y = contours[contour_index][i].y;
        }
        middle_x = (min_x + max_x) / 2;

        roi_left = bin(Range(min_y, max_y), Range(min_x, middle_x));
        findContours(roi_left, roi_contours, RETR_LIST, CHAIN_APPROX_NONE);
        l_roi_contours_size = roi_contours.size();

        roi_right = bin(Range(min_y, max_y), Range(middle_x, max_x));
        findContours(roi_right, roi_contours, RETR_LIST, CHAIN_APPROX_NONE);
        r_roi_contours_size = roi_contours.size();

        imshow("roi_left", roi_left);
        imshow("roi_right", roi_right);

        waitKey();

        // (l_roi_contours_size > r_roi_contours_size) -> 왼쪽으로 열린 객체
        if (l_roi_contours_size > r_roi_contours_size) {
            drawContours(dst, contours, contour_index, Scalar(255, 0, 0), 2);
        }
        // (l_roi_contours_size < r_roi_contours_size) ->  오른쪽으로 열린 객체
        else if (l_roi_contours_size < r_roi_contours_size){
            drawContours(dst, contours, contour_index, Scalar(0, 0, 255), 2);
        }
        else {
            cout << format("contours[%d] 객체는 좌 또는 우로 열리지 않았습니다.", contour_index) << endl;
        }
    }

    imshow("src", src);
    imshow("dst", dst);
    waitKey(0);

    return 0;
}