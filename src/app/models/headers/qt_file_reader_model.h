#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_FILE_READER_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_FILE_READER_MODEL_H_

#include <stdint.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "base_file_reader_model.h"
#include "scene_model.h"
namespace s21 {
class QtFileReader : public BaseFileReader {
 public:
  Scene ReadFile(const std::string &path) override;

 private:
  bool LineParser(const std::string &line);
  int IsType(const std::string &line);
  bool VertexParser(const std::string &line);
  bool FasetParser(const std::string &line);
  bool VertexLineValidator(const std::string &line);
  bool FasetLineValidator(const std::string &line);
  double VertexToDouble(const std::string &line, size_t &begin_position);
  double FasetToDouble(const std::string &subline);
  std::vector<std::string> SplitStringBySpace(const std::string &str);

 private:
  Scene scene_;
};
}  // namespace s21
#endif  //  CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_FILE_READER_MODEL_H_
