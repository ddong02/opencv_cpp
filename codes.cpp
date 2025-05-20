// 2025-05-20
// chap 8-1

// 01

// #include <opencv2/opencv.hpp>
// #include <iostream>

// using namespace cv;
// using namespace std;

// int main(void)
// {
//     Mat src = imread("images/lenna.bmp");
//     if (src.empty()) { cerr << "Image load failed!" << endl; return -1;}
//     Point2f srcPts[3], dstPts[3];
//     srcPts[0] = Point2f(0, 0);
//     srcPts[1] = Point2f(src.cols - 1, 0);
//     srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
//     dstPts[0] = Point2f(0, 0);
//     dstPts[1] = Point2f(src.cols / 2, 0);
//     dstPts[2] = Point2f(src.cols / 2, src.rows / 2);
//     Mat M = getAffineTransform(srcPts, dstPts);
//     cout << M << endl;
//     Mat dst;
//     warpAffine(src, dst, M, Size());
//     imshow("src", src);
//     imshow("dst", dst);
//     waitKey();
//     return 0;
// }

// 2025-05-20
// chap 8-1

// 02

// #include <opencv2/opencv.hpp>
// #include <iostream>

// using namespace cv;
// using namespace std;

// int main(void)
// {
//     Mat src = imread("images/lenna.bmp");
//     if (src.empty()) { cerr << "Image load failed!" << endl; return -1;}

//     Point2f srcPts[3], dstPts[3];
//     srcPts[0] = Point2f(0, 0);
//     srcPts[1] = Point2f(src.cols - 1, 0);
//     srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
//     dstPts[0] = Point2f(0, 0);
//     dstPts[1] = Point2f(src.cols / 2, 0);
//     dstPts[2] = Point2f(src.cols / 2, src.rows / 2);

//     Mat M = getAffineTransform(srcPts, dstPts);

//     Mat dst;
//     warpAffine(src, dst, M, Size());

//     vector<Point2f> src_center = {Point2f(src.cols / 2, src.rows / 2)};
//     vector<Point2f> dst_center;
//     transform(src_center, dst_center, M);
    
//     cout << "src center : " << src_center[0] << endl;
//     cout << "dst center : " << dst_center[0] << endl;

//     imshow("src", src);
//     imshow("dst", dst);
//     waitKey();

//     return 0;
// }

// 2025-05-20
// chap 8-1

// 03

// #include <opencv2/opencv.hpp>
// #include <iostream>

// using namespace cv;
// using namespace std;

// int main(void)
// {
//     Mat src = imread("images/lenna.bmp");
//     if (src.empty()) { cerr << "Image load failed!" << endl; return -1;}

//     Point2f srcPts[3], dstPts[3];
//     srcPts[0] = Point2f(0, 0);
//     srcPts[1] = Point2f(src.cols - 1, 0);
//     srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
//     dstPts[0] = Point2f(0, 0);
//     dstPts[1] = Point2f(src.cols * 2 - 1, 0);
//     dstPts[2] = Point2f(src.cols * 2 - 1, src.rows * 2 - 1);

//     Mat M = getAffineTransform(srcPts, dstPts);
//     cout << M << endl;

//     Mat dst;
//     warpAffine(src, dst, M, Size(src.cols * 2, src.rows * 2));

//     cout << src.size() << endl;
//     cout << dst.size() << endl;

//     imshow("src", src);
//     imshow("dst", dst);
//     waitKey();

//     return 0;
// }

// 2025-05-20
// chap 8-1

// 04

// #include <opencv2/opencv.hpp>
// #include <iostream>

// using namespace cv;
// using namespace std;

// int main(void)
// {
//     VideoCapture cap(1);
//     if (!cap.isOpened()) { cerr << "Camera open failed!" << endl; return -1; }

//     Mat frame;
//     int key = -1;

//     cap >> frame;

//     Point2f orgPts[3];
//     orgPts[0] = Point2f(0, 0);
//     orgPts[1] = Point2f(frame.cols - 1, 0);
//     orgPts[2] = Point2f(frame.cols - 1, frame.rows - 1);

//     Point2f zoominPts[3];
//     zoominPts[0] = Point2f(0, 0);
//     zoominPts[1] = Point2f(frame.cols * 2 - 1, 0);
//     zoominPts[2] = Point2f(frame.cols * 2 - 1, frame.rows * 2 - 1);

//     Point2f zoomoutPts[3];
//     zoomoutPts[0] = Point2f(0, 0);
//     zoomoutPts[1] = Point2f(frame.cols / 2 - 1, 0);
//     zoomoutPts[2] = Point2f(frame.cols / 2 - 1, frame.rows / 2 - 1);

//     Mat M;

//     bool zoomout = false;
//     bool zoomin = false;

//     while (true) {
//         cap >> frame;
        
//         if (zoomout) {            
//             M = getAffineTransform(orgPts, zoomoutPts);
//             warpAffine(frame, frame, M, Size());
//         }
//         else if (zoomin) {
//             M = getAffineTransform(orgPts, zoominPts);
//             warpAffine(frame, frame, M, Size());
//         }
//         imshow("camera", frame);
//         key = waitKey(5);

//         if (key == 'q') break;
//         if (key == 'a') {
//             zoomout = true;
//             zoomin = false;
//         }
//         if (key == 'b'){
//             zoomin = true;
//             zoomout = false;
//         }
//         if (key == 'c') {
//             zoomin = false;
//             zoomout = false;
//         }
//     }

//     return 0;
// }