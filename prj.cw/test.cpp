#include <iostream>
#include <opencv2/opencv.hpp>
#include <filesystem>
#include <rectangles/rectangles.hpp>

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

    long long su = 0;
    int cnt = 0;
    CutRectangles rectangles(srcImages);

    for(int p = 0; p < rectangles.ssize(); ++p){
        cv::Mat tempImage;
        tempImage = srcImages[p];
        for(auto& i: rectangles[p]){
            cv::rectangle(tempImage, i, cv::Scalar(0, 255, 0));
        }
        cv::imshow("debug", tempImage);
        cv::waitKey(0);
    }
}