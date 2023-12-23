#include "classify_blocks/classify_blocks.hpp"


ClassifyRectangles::ClassifyRectangles(const std::vector<cv::Mat>& images, const CutRectangles& rectangles)
  : rectangles_ptr(&rectangles) {

  rectangles_types.resize(rectangles.ssize());
  for (int i_page = 0; i_page < rectangles.ssize(); i_page += 1) {
    for (int i_rect = 0; i_rect < rectangles[i_page].size(); i_rect += 1) {
      MeanBlocksHeight += static_cast<double>(rectangles[i_page][i_rect].height);
      n_rectangles += 1;
    }
    rectangles_types[i_page].resize(rectangles[i_page].size());
  }

  MeanBlocksHeight /= n_rectangles;

  for (int i_page = 0; i_page < rectangles.ssize(); i_page += 1) {
    
    cv::Mat grayImage;

    cv::cvtColor(images[i_page], grayImage, cv::COLOR_BGR2GRAY);

    for (int i_rect = 0; i_rect < rectangles[i_page].size(); i_rect += 1) {

      // start extracting features

      int N = NumberOfBlackPixels(grayImage(rectangles[i_page][i_rect]));

      // std::cout << N << ", ";



    }
  } 

};

const std::vector<Labels>& ClassifyRectangles::operator[](ptrdiff_t ind) const {
  return rectangles_types.at(ind);
};

int ClassifyRectangles::NumberOfBlackPixels(const cv::Mat& img_area) {
  return img_area.rows * img_area.cols - cv::countNonZero(img_area);
};

int ClassifyRectangles::WhiteToBlackTransitions(const cv::Mat& img_area) {
  int ans = 0;
  for (int i_row = 0; i_row < img_area.rows; i_row += 1) {
    const uchar* p = img_area.ptr<uchar>(i_row);
    for (int i_col = 0; i_col < img_area.cols; i_col += 1) {
      
    }
  }
};