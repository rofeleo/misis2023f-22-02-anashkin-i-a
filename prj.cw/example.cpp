#include "classify_blocks/classify_blocks.hpp"

#include <iostream>
#include <opencv2/opencv.hpp>
#include <filesystem>
#include <vector>

/*!
    \defgroup test_app Тестовый модуль.
    @{
*/

/*!
    \param[in] argc[1] путь до каталога с изображениями.
*/
int main(int argv, char* argc[]){

  std::string document_path = argc[1]; // Use full path!
  cv::Mat srcImage;
  std::vector<cv::Mat> srcImages;
  std::filesystem::path my_path(document_path);
  for (auto& file : std::filesystem::directory_iterator(my_path)) {
      if (file.path().string().find(".jpg") != std::string::npos) {
          srcImage = cv::imread(file.path().string());
          srcImages.push_back(srcImage);

      }
  }

  CutRectangles rectangles(srcImages);

  ClassifyRectangles clf(srcImages, rectangles);

  for (int i = 0; i < srcImages.size(); ++i) {
    clf.PrintPageWithClassifiedRect(i);
  }
}

/*!
    @}
*/