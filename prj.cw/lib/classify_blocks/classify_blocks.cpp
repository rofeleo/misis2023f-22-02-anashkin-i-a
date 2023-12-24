#define DEBUG

#include "classify_blocks/classify_blocks.hpp"

std::ostream& operator<<(std::ostream& ostrm, const Labels& lbl) {
  switch (lbl) {
    case Labels::text:
      ostrm << "text";
      break;
    case Labels::horizontal_line:
      ostrm << "horizontal_line";
      break;
    case Labels::vertical_line:
      ostrm << "vertical_line";
      break;
    case Labels::graphic:
      ostrm << "graphic";
      break;
    case::Labels::picture:
      ostrm << "picture";
    default:
      break;
  }
  return ostrm;
}

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
    
    cv::Mat gray_image;

    cv::cvtColor(images[i_page], gray_image, cv::COLOR_BGR2GRAY);

    cv::Mat black_and_white;

    cv::threshold(gray_image, black_and_white, 128, 255, cv::THRESH_BINARY);

    for (int i_rect = 0; i_rect < rectangles[i_page].size(); i_rect += 1) {

      // start extracting features

      cv::Mat cur_rect = black_and_white(rectangles[i_page][i_rect]);

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

      #ifdef DEBUG
        std::cout << "page number: " << i_page << " " << "rectangle number: " << i_rect << std::endl;
        std::cout << "x_min: " << rectangles[i_page][i_rect].x << std::endl;
        std::cout << "width: " << width << std::endl;
        std::cout << "y_min: " << rectangles[i_page][i_rect].y << std::endl;
        std::cout << "height: " << height << std::endl;
        std::cout << "delta_x: " << delta_x << std::endl;
        std::cout << "delta_x / dx: " << static_cast<double>(delta_x) / width << std::endl;
        std::cout << "TH: " << TH << std::endl;
        std::cout << "TV: " << TV << std::endl;
        std::cout << "TH_X: " << TH_X << std::endl;
        std::cout << "TV_X: " << TV_X << std::endl;
        std::cout << "N: " << N << std::endl;
        std::cout << "D: " << D << std::endl;
      #endif

      if (c1 * MeanBlocksHeight < height && height < c2 * MeanBlocksHeight) {
        rectangles_types[i_page][i_rect] = Labels::text;
      } else if (height < c1 * MeanBlocksHeight && ch1 < TH_X && TH_X < ch2) {
        rectangles_types[i_page][i_rect] = Labels::text;
      } else if (TH_X < ch3 && R > cr && c3 < TV_X && TV_X < c4) {
        rectangles_types[i_page][i_rect] = Labels::horizontal_line;
      } else if (TH_X > 1 / static_cast<double>(ch3) && R < 1 / static_cast<double>(cr) && 
                  c3 < TH_Y && TH_Y < c4) {
        rectangles_types[i_page][i_rect] = Labels::vertical_line;
      } else if (height > c2 * MeanBlocksHeight && ch1 < TH_X && TH_X < ch2 && cv1 < TV_X && TV_X < cv2) {
        rectangles_types[i_page][i_rect] = Labels::text;
      } else if (D < c5) {
        rectangles_types[i_page][i_rect] = Labels::graphic;
      } else {
        rectangles_types[i_page][i_rect] = Labels::picture;
      }

      #ifdef DEBUG
        std::cout << rectangles_types[i_page][i_rect] << std::endl;
        std::cout << "===============================================================================" << std::endl;
      #endif
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