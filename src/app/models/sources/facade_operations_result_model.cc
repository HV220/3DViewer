#include "../headers/main_model.h"

namespace s21 {
const std::string &FacadeOperationsResult::GetErrorMessage() {
  return this->errorMessage_;
}
void FacadeOperationsResult::SetErrorMessage(const std::string &error) {
  this->errorMessage_ = error;
}
bool FacadeOperationsResult::IsSucces() { return this->isSucces_; }

}  // namespace s21
