// 2025-05-26
// chap 11-1

// 02

// #include <opencv2/opencv.hpp>
// #include <iostream>

// using namespace std;
// using namespace cv;

// // 회색조 히스토그램 계산 함수
// Mat calcGrayHist(const Mat& img)
// {
//     CV_Assert(img.type() == CV_8UC1);

//     Mat hist;
//     int channels[] = {0};
//     int dims = 1;
//     const int histSize[] = {256};
//     float graylevel[] = {0, 256};
//     const float* ranges[] = {graylevel};

//     calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
//     return hist;
// }

// // 히스토그램 시각화 함수
// Mat getGrayHistImage(const Mat& hist)
// {
//     CV_Assert(hist.type() == CV_32F);
//     CV_Assert(hist.size() == Size(1, 256));

//     double histMax;
//     minMaxLoc(hist, 0, &histMax);

//     Mat histImage(100, 256, CV_8UC1, Scalar(255));
//     for (int i = 0; i < 256; i++) {
//         float binVal = hist.at<float>(i, 0);
//         int intensity = cvRound(binVal * 100 / histMax);
//         line(histImage, Point(i, 100), Point(i, 100 - intensity), Scalar(0));
//     }

//     return histImage;
// }

// int main()
// {
//     // 1. 이미지 불러오기
//     Mat src = imread("images/lenna.bmp", IMREAD_GRAYSCALE);
//     if (src.empty()) {
//         cerr << "Error: Image load failed!" << endl;
//         return -1;
//     }

//     // 2. 히스토그램 계산 및 시각화
//     Mat hist = calcGrayHist(src);
//     Mat histImage = getGrayHistImage(hist);
//     imshow("Histogram", histImage);

//     // 3. Otsu 알고리즘으로 자동 임계값 결정 (출력 따로 받기)
//     Mat binary;
//     double thresh_val = threshold(src, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
//     cout << "자동 임계값 (Otsu): " << thresh_val << endl;

//     // 4. 결과 출력
//     imshow("Original Image", src);    // 원본 이미지 그대로
//     imshow("Binary Image", binary);   // 이진화된 이미지

//     waitKey(0);
//     destroyAllWindows();
//     return 0;
// }

// 03




// 04

// #include <opencv2/opencv.hpp>
// #include <iostream>

// using namespace std;
// using namespace cv;

// // 회색조 히스토그램 계산
// Mat calcGrayHist(const Mat& img)
// {
//     CV_Assert(img.type() == CV_8UC1);

//     Mat hist;
//     int channels[] = {0};
//     int dims = 1;
//     const int histSize[] = {256};
//     float graylevel[] = {0, 256};
//     const float* ranges[] = {graylevel};

//     calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
//     return hist;
// }

// // 히스토그램 시각화
// Mat getGrayHistImage(const Mat& hist)
// {
//     CV_Assert(hist.type() == CV_32F);
//     CV_Assert(hist.size() == Size(1, 256));

//     double histMax;
//     minMaxLoc(hist, 0, &histMax);

//     Mat imgHist(100, 256, CV_8UC1, Scalar(255));
//     for (int i = 0; i < 256; i++) {
//         line(imgHist,
//              Point(i, 100),
//              Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)),
//              Scalar(0));
//     }

//     return imgHist;
// }

// int main(void)
// {
//     VideoCapture cap("images/line.mp4");
//     if (!cap.isOpened()) {
//         cerr << "Error: Cannot open the video file!" << endl;
//         return -1;
//     }

//     Mat frame, gray, binary;

//     while (true) {
//         cap >> frame;
//         if (frame.empty())
//             break;

//         cvtColor(frame, gray, COLOR_BGR2GRAY);

//         // 히스토그램 계산 및 출력
//         Mat hist = calcGrayHist(gray);
//         Mat histImg = getGrayHistImage(hist);
//         imshow("Histogram", histImg);

//         // 자동 임계값 찾기 (Otsu)
//         double thresh_val = threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);

//         // 이진 영상 출력
//         imshow("Binary", binary);
//         imshow("Frame", frame);
//         cout << "Current Otsu Threshold: " << thresh_val << endl;

//         char key = waitKey(30);
//         if (key == 27 || key == 'q') break; // ESC or q to quit
//     }

//     cap.release();
//     destroyAllWindows();
//     return 0;
// }
