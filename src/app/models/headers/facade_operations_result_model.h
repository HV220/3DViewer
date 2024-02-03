#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_FACADE_OPERATIONS_RESULT_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_FACADE_OPERATIONS_RESULT_MODEL_H_
#include <string>

namespace s21 {
class FacadeOperationsResult {
 public:
  FacadeOperationsResult() = default;
  FacadeOperationsResult(const std::string &message, bool status)
      : errorMessage_(message), isSucces_(status) {}
  const std::string &GetErrorMessage();
  void SetErrorMessage(const std::string &error);
  bool IsSucces();

 private:
  std::string errorMessage_;
  bool isSucces_;
};
}  // namespace s21
#endif  //  CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_FACADE_OPERATIONS_RESULT_MODEL_H_
