#ifndef CLASSIFY_HPP_22_12_23
#define CLASSIFY_HPP_22_12_23
#endif

#include "rectangles/rectangles.hpp"

#include <vector>
#include <algorithm>

enum class Labels {
  text,
  large_text, // titles, headings
  small_text, // footnotes, remarks 
  horizontal_line,
  vertical_line,
  graphic,
  picture
};

class ClassifyRectangles {
  
  public:
    ClassifyRectangles(const std::vector<cv::Mat>& images, const CutRectangles& rectangles);
    void PrintPageWithClassifiedRect(ptrdiff_t i_page);

  private:
    double c1 = 0.8;
    double c2 = 1.2;
    double c3 = 0.95;
    double c4 = 1.05;
    double c5 = 0.2;
    double ch1 = 1.2;
    double ch2 = 3;
    double ch3 = 0.2;
    double cv1 = 1.2;
    double cv2 = 2.6;
    double cr = 5;

  private:
    const CutRectangles* rectangles_ptr;
    std::vector<std::vector<Labels>> rectangles_types;
    int NumberOfBlackPixels(const cv::Mat& img_area);
    int HorizWhiteToBlackTransitions(const cv::Mat& img_area);
    int VertWhiteToBlackTransitions(const cv::Mat& img_area);
    int ColsWithBlackPixels(const cv::Mat& img_area);
    std::vector<cv::Mat> pages_;

  private:
    static std::vector<cv::Scalar> color_for_label;
};  