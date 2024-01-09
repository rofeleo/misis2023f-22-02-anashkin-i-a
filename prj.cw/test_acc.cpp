#ifndef TEST_ACCURACY_27_12
#define TEST_ACCURACY_27_12
#endif

#include <fstream>
#include <iostream>
#include <vector>

#include "nlohmann/json.hpp"

#include "classify_blocks/classify_blocks.hpp"
#include "pdf2img/pdf2img.h"

/*!
  \defgroup test_acc Модуль для вычисленяи процента правильных ответов.
  @{
*/

/*!
*   \param argc[1] json файл, содержащий правильные типы зон страниц, на которых считается точность, и номера этих страниц в курсовой.
*   \param argc[2] путь до pdf файла.
*   
*   
*/
int main(int argv, char* argc[]) {

  poppler::document* mypdf = poppler::document::load_from_file(argc[2]);

  const int DPI = 300;

  pdf2img images_from_pdf(mypdf, DPI);

  std::ifstream json_file_strm(argc[1]);

  nlohmann::json json_data = nlohmann::json::parse(json_file_strm);

  // std::ofstream out("./out.json");

  // out << std::setw(4) << json_data;

  // return 0;

  std::vector<cv::Mat> images;

  for (int i_page = 0; i_page < images_from_pdf.get_size(); i_page += 1) { 
    images.push_back(images_from_pdf[i_page]);
  }

  CutRectangles rect(images);

  ClassifyRectangles clf(images, rect);

  int cnt_false = 0;
  int cnt_true = 0;

  for (const auto& block : json_data) {
    
    int i_page = std::stoi(block["file_attributes"]["page_number"].get<std::string>());

    int i_rect = 0;

    for (const auto& region : block["regions"]) {

      if (i_page > images.size()) {
        throw(std::out_of_range("i page is wrong"));
      } 

      if (i_rect > rect[i_page].size()) {
        throw(std::out_of_range("i rect is wrong"));
        // std::cout << "rect wrong: " << i_page << " " << i_rect;
        // cv::imshow("wrong page", images[i_page]);
        // cv::waitKey(0);
        // return 0;
      }

      Label y = static_cast<Label>(std::stoi(region["region_attributes"]["type"].get<std::string>()));

      if (y != clf.at(i_page, i_rect)) {
        cnt_false += 1;
      } else {
        cnt_true += 1;
      }

      i_rect += 1;
      
    } 

  }
  
  std::cout << 100 - (static_cast<double>(cnt_false) / cnt_true) * 100;

  return 0;
}

/*!
  @}
*/