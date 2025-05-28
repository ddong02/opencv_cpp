// 2025-05-28
// chap 12-1

// 01

// #include <iostream>
// #include <opencv2/opencv.hpp>

// using namespace std;
// using namespace cv;

// int main()
// {
//     Mat src = imread("images/labelex.png", IMREAD_GRAYSCALE);
//     if (src.empty()) { cerr << "Image load failed!" << endl; return -1;}
//     Mat bin;
//     threshold(src, bin, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);

//     Mat labels, stats, centroids;
//     int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);

//     Mat dst;
//     cvtColor(src, dst, COLOR_GRAY2BGR);

//     int object_sizes[4];

//     for (int i = 1; i < cnt; i++) {
//         int* p = stats.ptr<int>(i); //stats객체의 i행의 시작주소를 리턴
//         object_sizes[i-1] = p[4];
//     }

//     int max_size_index = 0;
//     int min_size_index = 0;

//     for (int i=1; i<4; i++){
//         if (object_sizes[i] < object_sizes[min_size_index])
//             min_size_index = i;
//         else if (object_sizes[i] > object_sizes[max_size_index])
//             max_size_index = i;
//     }

//     cout << "면적이 최대인 객체의 레이블: " << max_size_index + 1 << endl;
//     cout << "무게 중심(x, y): " << centroids.at<double>(max_size_index + 1, 0) 
//         << ", " << centroids.at<double>(max_size_index + 1, 1) << endl;

//     cout << "면적이 최소인 객체의 레이블: " << min_size_index + 1 << endl;
//     cout << "무게 중심(x, y): " << centroids.at<double>(min_size_index + 1, 0) 
//         << ", " << centroids.at<double>(min_size_index + 1, 1) << endl;

//     int* ptr_min = stats.ptr<int>(min_size_index+1);
//     int* ptr_max = stats.ptr<int>(max_size_index+1);

//     rectangle(dst, Rect(ptr_min[0], ptr_min[1], ptr_min[2], ptr_min[3]), Scalar(255, 0, 0));
//     rectangle(dst, Rect(ptr_max[0], ptr_max[1], ptr_max[2], ptr_max[3]), Scalar(0, 0, 255));

//     imshow("src", src);
//     imshow("dst", dst);

//     waitKey(0);
//     destroyAllWindows();

//     return 0;
// }

// 02

// #include <iostream>
// #include <opencv2/opencv.hpp>

// using namespace std;
// using namespace cv;

// int main()
// {
//     Mat src = imread("images/polygon.bmp");
//     if (src.empty()) { cerr << "Image load failed!" << endl; return -1;}

//     Mat src_gray;
//     cvtColor(src, src_gray, COLOR_BGR2GRAY);

//     Mat bin;
//     threshold(src_gray, bin, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);

//     Mat labels, stats, centroids;
//     int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);

//     int* stats_ptr;
//     double* centroids_ptr;

//     for (int i=1; i<cnt; i++){
//         stats_ptr = stats.ptr<int>(i);
//         centroids_ptr = centroids.ptr<double>(i);

//         cout << i << ' ';
//             for (int j=0; j<5; j++)
//             cout << stats_ptr[j] << ' ';
//         cout << src.at<Vec3b>(centroids_ptr[1], centroids_ptr[0]) << endl;

//         rectangle(src,
//             Rect(stats_ptr[0], stats_ptr[1], stats_ptr[2], stats_ptr[3]),
//             Scalar(0, 255, 255)
//         );

//         putText(
//             src,
//             format("%d", i),
//             Point(centroids_ptr[0], centroids_ptr[1]),
//             FONT_HERSHEY_SIMPLEX,
//             1.0,
//             Scalar(0,0,255)
//         );
//     }

//     imshow("src", src);
//     imshow("src_gray", src_gray);

//     waitKey(0);
//     destroyAllWindows();

//     return 0;
// }