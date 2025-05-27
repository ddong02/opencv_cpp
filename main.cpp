#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat calcGrayHist(const Mat& img)
{
    CV_Assert(img.type() == CV_8UC1);

    Mat hist;
    int channels[] = {0};
    int dims = 1;
    const int histSize[] = {256};
    float graylevel[] = {0, 256};
    const float* ranges[] = {graylevel};

    calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
    return hist;
}

Mat getGrayHistImage(const Mat& hist)
{
    CV_Assert(hist.type() == CV_32F);
    CV_Assert(hist.size() == Size(1, 256));

    double histMax;
    minMaxLoc(hist, 0, &histMax);

    Mat histImage(100, 256, CV_8UC1, Scalar(255));
    for (int i = 0; i < 256; i++) {
        float binVal = hist.at<float>(i, 0);
        int intensity = cvRound(binVal * 100 / histMax);
        line(histImage, Point(i, 100), Point(i, 100 - intensity), Scalar(0));
    }

    return histImage;
}

int main()
{
    // 1. 이미지 불러오기
    Mat src = imread("images/lenna.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Error: Image load failed!" << endl;
        return -1;
    }

    // 2. 히스토그램 계산 및 시각화
    Mat hist = calcGrayHist(src);
    Mat histImage = getGrayHistImage(hist);
    imshow("Histogram", histImage);

    // 3. 적응형 이진화
    Mat adaptive_binary;
    adaptiveThreshold(
        src, adaptive_binary,
        255,                       // 최대값
        ADAPTIVE_THRESH_MEAN_C,   // 또는 ADAPTIVE_THRESH_GAUSSIAN_C
        THRESH_BINARY,
        11,  // blockSize (이웃 영역 크기, 홀수)
        5    // C 값 (평균에서 빼는 값, 조정용)
    );

    // 4. 결과 출력
    imshow("Original Image", src);
    imshow("Adaptive Binary", adaptive_binary);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
