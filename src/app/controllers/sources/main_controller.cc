#include "../headers/main_controller.h"

namespace s21 {

std::map<bool, std::string> MainController::LoadSceneAction(
    const std::string &path) {
  std::map<bool, std::string> res;
  FacadeOperationsResult report = this->model_->LoadScene(path);
  res.insert(std::pair<bool, std::string>(report.IsSucces(),
                                          report.GetErrorMessage()));
  return res;
}

std::map<bool, std::string> MainController::SaveSettingsAction() {
  std::map<bool, std::string> res;
  FacadeOperationsResult report = this->model_->SaveSetting();
  res.insert(std::pair<bool, std::string>(report.IsSucces(),
                                          report.GetErrorMessage()));
  return res;
}

std::map<bool, std::string> MainController::LoadSettingsAction() {
  std::map<bool, std::string> res;
  FacadeOperationsResult report = this->model_->LoadSetting();
  res.insert(std::pair<bool, std::string>(report.IsSucces(),
                                          report.GetErrorMessage()));
  return res;
}

std::map<bool, std::string> MainController::SetPathAction(
    const std::string &path) {
  std::map<bool, std::string> res;
  FacadeOperationsResult report = this->model_->SetPath(path);
  res.insert(std::pair<bool, std::string>(report.IsSucces(),
                                          report.GetErrorMessage()));
  return res;
}

std::map<bool, std::string> MainController::SetSettingAction(
    const std::string &method_name, const double &value) {
  std::map<bool, std::string> res;
  FacadeOperationsResult report = this->model_->SetSetting(method_name, value);
  res.insert(std::pair<bool, std::string>(report.IsSucces(),
                                          report.GetErrorMessage()));
  return res;
}

std::map<bool, std::string> MainController::SetColorAction(
    const std::string &method_name, const float &red_color,
    const float &green_color, const float &blue_color) {
  std::map<bool, std::string> res;
  FacadeOperationsResult report =
      this->model_->SetColor(method_name, red_color, green_color, blue_color);
  res.insert(std::pair<bool, std::string>(report.IsSucces(),
                                          report.GetErrorMessage()));
  return res;
}

std::map<bool, std::string> MainController::GetPathAction() {
  std::map<bool, std::string> res;
  try {
    res.insert(std::pair<bool, std::string>(true, this->model_->GetPath()));
    return res;
  } catch (std::exception &e) {
    res.insert(std::pair<bool, std::string>(false, e.what()));
    return res;
  }
}

std::map<bool, double> MainController::GetSettingAction(
    const std::string &method_name) {
  std::map<bool, double> res;
  try {
    res.insert(
        std::pair<bool, double>(true, this->model_->GetSetting(method_name)));
    return res;
  } catch (...) {
    res.insert(std::pair<bool, double>(false, -1.0));
    return res;
  }
}

std::map<bool, float> MainController::GetColorAction(
    const std::string &method_name) {
  std::map<bool, float> res;
  try {
    res.insert(
        std::pair<bool, float>(true, this->model_->GetColor(method_name)));
    return res;
  } catch (...) {
    res.insert(std::pair<bool, float>(false, -1.0f));
    return res;
  }
}

std::vector<std::vector<uint32_t>> MainController::GetNormalaizeFasets() {
  if (this->model_->GetFacets().type() ==
      typeid(std::vector<std::vector<uint32_t>>)) {
    auto facets = std::any_cast<std::vector<std::vector<uint32_t>>>(
        this->model_->GetFacets());
    return facets;
  }

  return std::vector<std::vector<uint32_t>>();
}

std::vector<double> MainController::GetNormalaizeVertexes() {
  if (this->model_->GetVertexes().type() == typeid(std::vector<double>)) {
    auto vertexes =
        std::any_cast<std::vector<double>>(this->model_->GetVertexes());
    return vertexes;
  }
  return std::vector<double>();
}

std::map<bool, double> MainController::GetNormalaizeMaxCoordinate() {
  std::map<bool, double> res;
  if (this->model_->GetMaxCoordinate().type() == typeid(double)) {
    auto max_coordinate =
        std::any_cast<double>(this->model_->GetMaxCoordinate());
    res.insert(std::pair<bool, double>(true, max_coordinate));
    return res;
  }
  res.insert(std::pair<bool, double>(false, -1.0));
  return res;
}

}  // namespace s21
