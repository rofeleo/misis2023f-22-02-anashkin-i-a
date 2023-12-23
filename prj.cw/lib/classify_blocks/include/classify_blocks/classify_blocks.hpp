#ifndef CLASSIFY_HPP_22_12_23
#define CLASSIFY_HPP_22_12_23
#endif

#include "rectangles/rectangles.hpp"
#include <vector>

enum class Labels {
  text,
  horizontal_line,
  vertical_line,
  graphic,
  picture
};

class ClassifyRectangles {
  
  public:
    ClassifyRectangles(const std::vector<cv::Mat>& images, const CutRectangles& rectangles);
    const std::vector<Labels>& operator[](ptrdiff_t ind) const;
  
  private:
    double MeanBlocksHeight = 0;
    int n_rectangles = 0;

  private:
    const CutRectangles* rectangles_ptr;
    std::vector<std::vector<Labels>> rectangles_types;
    int NumberOfBlackPixels(const cv::Mat& img_area);
    int WhiteToBlackTransitions(const cv::Mat& img_area);
};  