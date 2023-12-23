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
    uchar* p = scan.ptr<uchar>(0);
    cv::Mat grayScan;

    cv::cvtColor(scan, grayScan, cv::COLOR_BGR2GRAY);
    long long su = 0;
    int cnt = 0;
    CutRectangles cutted_rectangles(srcImages);

    ClassifyRectangles clf_rect(srcImages, cutted_rectangles);


}