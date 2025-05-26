// 2025-05-20
// chap 8-2

// 1

// #include <opencv2/opencv.hpp>
// using namespace cv;
// using namespace std;
// int main(void)
// {
//     Mat src = imread("images/lenna.bmp");
//     if (src.empty()) {cerr << "Image load failed!" << endl; return -1;}
    
//     Point2f srcPts[3], dstPts[3];
//     srcPts[0] = Point2f(0, 0);
//     srcPts[1] = Point2f(src.cols - 1, 0);
//     srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
//     dstPts[0] = Point2f(150, 100);
//     dstPts[1] = Point2f(src.cols + 150 - 1, 100);
//     dstPts[2] = Point2f(src.cols + 150 - 1, src.rows + 100 - 1);

//     Mat M = getAffineTransform(srcPts, dstPts);
//     cout << M << endl;

//     Mat dst;
//     warpAffine(src, dst, M, Size());
//     imshow("src", src);
//     imshow("dst", dst);
//     waitKey();
//     return 0;
// }

// 4

// #include <opencv2/opencv.hpp>
// using namespace cv;
// using namespace std;
// int main(void)
// {
//     Mat src = imread("images/lenna.bmp");
//     if (src.empty()) {cerr << "Image load failed!" << endl; return -1;}
    
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

// 5

// #include <opencv2/opencv.hpp>
// using namespace cv;
// using namespace std;
// int main(void)
// {
//     Mat src = imread("images/lenna.bmp");
//     if (src.empty()) {cerr << "Image load failed!" << endl; return -1;}
//     Mat dst;
    
//     Mat M = Mat_<double>({ 2, 3 }, { 0.5, 0, 0, 0, 0.5, 0 }); 
//     warpAffine(src, dst, M, Size());

//     M = Mat_<double>({ 2, 3 }, { 1, 0, src.cols * 0.25 - 1, 0, 1, src.rows * 0.25 - 1 });
//     warpAffine(dst, dst, M, Size());

//     imshow("src", src);
//     imshow("dst2", dst);

//     waitKey();
//     return 0;
// }