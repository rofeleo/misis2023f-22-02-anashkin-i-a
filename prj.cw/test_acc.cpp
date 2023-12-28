#ifndef TEST_ACCURACY_27_12
#define TEST_ACCURACY_27_12
#endif

#include <fstream>
#include <iostream>
#include <vector>

#include "classify_blocks/classify_blocks.hpp"
#include "nlohmann/json.hpp"

int main(int argv, char* argc[]) {

  std::ifstream json_file_strm(argc[1]);

  nlohmann::json json_data = nlohmann::json::parse(json_file_strm);

  // std::ofstream out("./out.json");

  // out << std::setw(4) << json_data;

  // return 0;

  std::vector<std::vector<Label>> y;

  std::vector<cv::Mat> images;

  int i_page_js = 0;

  for (const auto& block : json_data) {

    // std::cout << (argc[2] + std::string("/") + block["filename"].get<std::string>()) << std::endl;
    images.push_back(cv::imread(argc[2] + std::string("/") + block["filename"].get<std::string>()));

    for (const auto& region : block["regions"]) {
      y[i_page_js].push_back(static_cast<Label>(std::stoi(region["region_attributes"]["type"].get<std::string>())));
      // std::cout << y.back() << std::endl;
    }
    i_page_js += 1;
    // return 0;
  }
  
  // for (auto i : y) std::cout << i << std::endl;
  // for (auto i : images) {
  //     cv::imshow("dsad", i);
  //     cv::waitKey(0);
  // }

  CutRectangles rect(images);

  ClassifyRectangles clf(images, rect);
  for (int i_page = 0; i_page < images.size(); i_page += 1) {
    clf.PrintPageWithClassifiedRect(i_page);
    for (auto& i : y[i_page]) {
      std::cout << i << std::endl;
    }
  }


  int cnt_false = 0;
  int cnt_true = 0;

  // for (int i_page = 0; i_page < images.size(); i_page += 1) {
  //   for (int i_rect = 0; i_rect < rect[i_page].size(); i_rect += 1) {
  //     if (clf.at(i_page, i_rect) != y[i_page * i_rect]) cnt_false += 1;
  //     else cnt_true += 1;
  //   }
  // }

  std::cout << cnt_false << " " << cnt_true;

  // for (const auto& i : json_data["img3.jpg580109"]["regions"]) {
  //   static_cast<Label>(std::stoi(i["region_attributes"]["type"].get<std::string>())) << std::endl;
  // }

  // std::string my_path = argc[1];

  // int cnt_pages = 0;

  // for(auto& file: std::filesystem::directory_iterator(my_path)){
  //       if(file.path().string().find(".jpg") != std::string::npos){
  //           std::cout << file.path() << std::endl;
  //       }
  //   }

  return 0;
}