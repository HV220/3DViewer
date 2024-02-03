#include "../headers/main_model.h"

namespace s21 {

FacadeOperationsResult Facade::LoadScene(const std::string &path) {
  try {
    this->scene_.clear();
    this->scene_ = this->sceneDrawer_->ReadFile(path);
    this->sceneDrawer_->LoadScene(this->scene_);
  } catch (std::exception &e) {
    return CreateErrorReport(e.what(), false);
  }
  return CreateErrorReport("", true);
};

FacadeOperationsResult Facade::SaveSetting() {
  try {
    this->sceneDrawer_->SaveSetting();
  } catch (std::exception &e) {
    return CreateErrorReport(e.what(), false);
  }
  return CreateErrorReport("", true);
};

FacadeOperationsResult Facade::LoadSetting() {
  try {
    this->sceneDrawer_->LoadSetting();
  } catch (std::exception &e) {
    return CreateErrorReport(e.what(), false);
  }
  return CreateErrorReport("", true);
};

FacadeOperationsResult Facade::SetPath(const std::string &path) {
  try {
    this->sceneDrawer_->GetSettings().SetPath(path);
  } catch (std::exception &e) {
    return CreateErrorReport(e.what(), false);
  }
  return CreateErrorReport("", true);
};
FacadeOperationsResult Facade::SetSetting(const std::string &method_name,
                                          const double &value) {
  try {
    this->sceneDrawer_->GetSettings().SetSetting(method_name, value);
  } catch (std::exception &e) {
    return CreateErrorReport(e.what(), false);
  }
  return CreateErrorReport("", true);
};

FacadeOperationsResult Facade::SetColor(const std::string &method_name,
                                        const float &red_color,
                                        const float &green_color,
                                        const float &blue_color) {
  try {
    this->sceneDrawer_->GetSettings().SetColor(method_name, red_color,
                                               green_color, blue_color);
  } catch (std::exception &e) {
    return CreateErrorReport(e.what(), false);
  }
  return CreateErrorReport("", true);
};

std::string Facade::GetPath() {
  try {
    return this->sceneDrawer_->GetSettings().GetPath();
  } catch (...) {
    throw;
  }
};

double Facade::GetSetting(const std::string &method_name) {
  try {
    return this->sceneDrawer_->GetSettings().GetSetting(method_name);
  } catch (...) {
    throw;
  }
};

float Facade::GetColor(const std::string &method_name) {
  try {
    return this->sceneDrawer_->GetSettings().GetColor(method_name);
  } catch (...) {
    throw;
  }
};

std::any Facade::GetFacets() {
  try {
    return this->sceneDrawer_->GetNormalaizeParamsScene().GetFacets();
  } catch (...) {
    throw;
  }
};

std::any Facade::GetVertexes() {
  try {
    return this->sceneDrawer_->GetNormalaizeParamsScene().GetVertexes();
  } catch (...) {
    throw;
  }
};

std::any Facade::GetMaxCoordinate() {
  try {
    return this->sceneDrawer_->GetNormalaizeParamsScene().GetMaxCoordinate();
  } catch (...) {
    throw;
  }
};

FacadeOperationsResult Facade::CreateErrorReport(const std::string &error,
                                                 bool is_succes) {
  FacadeOperationsResult result(error, is_succes);
  return result;
}

}  // namespace s21
