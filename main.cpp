#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat src = imread("images/polygon.bmp");
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1;}

    Mat src_gray;
    cvtColor(src, src_gray, COLOR_BGR2GRAY);

    Mat bin;
    threshold(src_gray, bin, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);

    Mat labels, stats, centroids;
    int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);

    int* stats_ptr;
    double* centroids_ptr;

    for (int i=1; i<cnt; i++){
        stats_ptr = stats.ptr<int>(i);
        centroids_ptr = centroids.ptr<double>(i);

        cout << i << ' ';
            for (int j=0; j<5; j++)
            cout << stats_ptr[j] << ' ';
        cout << src.at<Vec3b>(centroids_ptr[1], centroids_ptr[0]) << endl;

        rectangle(src,
            Rect(stats_ptr[0], stats_ptr[1], stats_ptr[2], stats_ptr[3]),
            Scalar(0, 255, 255)
        );

        putText(
            src,
            format("%d", i),
            Point(centroids_ptr[0], centroids_ptr[1]),
            FONT_HERSHEY_SIMPLEX,
            1.0,
            Scalar(0,0,255)
        );
    }

    imshow("src", src);
    imshow("src_gray", src_gray);

    waitKey(0);
    destroyAllWindows();

    return 0;
}