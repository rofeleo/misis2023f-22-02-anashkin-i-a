#include <iostream>
#include <opencv2/opencv.hpp>
#include <filesystem>
#include <rectangles/rectangles.hpp>
#include <classify_blocks/classify_blocks.hpp>
#include <queue>
#include <vector>

using namespace std;


int main() {

    const int DPI = 300;
    constexpr double TO_PT = 72.0 / DPI;
    cv::Mat srcImage;
    std::vector<cv::Mat> srcImages;
    cv::Mat scan = cv::imread("/Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/data/img1.png", cv::IMREAD_COLOR);
    srcImages.push_back(scan);
    cv::Mat grayScan;
    cv::cvtColor(scan, grayScan, cv::COLOR_BGR2GRAY);
    cv::Mat A = (cv::Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cout << "A = " << endl << " " << A << endl << endl;

    

    std::cout <<  cv::countNonZero(A.col(1));
    
    // for (int i = 0; i < 10; ++i) {
    //     uchar* p = scan.ptr<cv::pixel>(i);
    //     for (int j = 0; j < 10; ++j) {
    //         std::cout << int(p[j]) << " ";
    //     }
    //     std::cout << "\n";
    // }
    // long long su = 0;
    // int cnt = 0;
    // CutRectangles cutted_rectangles(srcImages);

    // ClassifyRectangles clf_rect(srcImages, cutted_rectangles);


}