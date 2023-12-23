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

      cv::Mat cur_rect = grayImage(rectangles[i_page][i_rect]);

      int N = NumberOfBlackPixels(cur_rect);

      int TH = HorizWhiteToBlackTransitions(cur_rect);

      int TV = VertWhiteToBlackTransitions(cur_rect);

      int delta_x = ColsWithBlackPixels(cur_rect);

      int height = rectangles[i_page][i_rect].height;

      int width = rectangles[i_page][i_rect].width;

      // count other features (based on previous)

      double R = static_cast<double>(width) / height;

      double D = N / static_cast<double>(width * height);

      double TH_X = static_cast<double>(TH) / delta_x;

      double TV_X = static_cast<double>(TV) / delta_x;

      double TH_Y = static_cast<double>(TH) / height;

    }
  } 

};

const std::vector<Labels>& ClassifyRectangles::operator[](ptrdiff_t ind) const {
  return rectangles_types.at(ind);
};

int ClassifyRectangles::NumberOfBlackPixels(const cv::Mat& img_area) {
  return img_area.rows * img_area.cols - cv::countNonZero(img_area);
};

int ClassifyRectangles::HorizWhiteToBlackTransitions(const cv::Mat& img_area) {
  int n_transitions = 0;
  for (int i_row = 0; i_row < img_area.rows; i_row += 1) {
    const uchar* p = img_area.ptr<uchar>(i_row);
    for (int i_col = 1; i_col < img_area.cols; i_col += 1) {
      if (p[i_col] == 0 && p[i_col - 1] == 255) { // 0 - black 255 - white
        n_transitions += 1;
      }
    }
  }
  return n_transitions;
};

int ClassifyRectangles::VertWhiteToBlackTransitions(const cv::Mat& img_area) {
  int n_transitions = 0;
  for (int i_row = 0; i_row < img_area.rows - 1; i_row += 1) {
    const uchar* p = img_area.ptr<uchar>(i_row);
    const uchar* n = img_area.ptr<uchar>(i_row + 1);
    for (int i_col = 0; i_col < img_area.cols; i_col += 1) {
      if (p[i_col] == 255 && n[i_col] == 0) { // 0 - black 255 - white
        n_transitions += 1;
      }
    }
  }
  return n_transitions;
};

int ClassifyRectangles::ColsWithBlackPixels(const cv::Mat& img_area) {
  int cnt_cols = 0;
  for (int i_col = 0; i_col < img_area.cols; i_col += 1) {
    if (cv::countNonZero(img_area.col(i_col))) {
      cnt_cols += 1;
    }
  }
  return cnt_cols;
};