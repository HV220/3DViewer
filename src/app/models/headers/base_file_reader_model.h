#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_BASE_FILE_READER_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_BASE_FILE_READER_MODEL_H_

#include <string>
#include <vector>

#include "scene_model.h"

namespace s21 {
class BaseFileReader {
 public:
  virtual Scene ReadFile(const std::string &path) = 0;
};
}  // namespace s21
#endif  //  CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_BASE_FILE_READER_MODEL_H_
