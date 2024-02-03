#include "../headers/main_model.h"

namespace s21 {

Scene QtSceneDrawer::ReadFile(const std::string &path) {
  try {
    return this->file_reader_.ReadFile(path);
  } catch (...) {
    throw std::logic_error("something wrong reading file");
  }
};

bool QtSceneDrawer::LoadScene(const Scene &scene) {
  try {
    this->norm_params_.clearParams();
    this->norm_params_.NormalaizeParametersScene(scene);
  } catch (...) {
    return false;
  }
  return true;
}

void QtSceneDrawer::SaveSetting() { this->settings_.SaveSettings(); };

void QtSceneDrawer::LoadSetting() { this->settings_.LoadSettings(); };

BaseSettings &QtSceneDrawer::GetSettings() { return this->settings_; };

const BaseNormalizationParameter &QtSceneDrawer::GetNormalaizeParamsScene() {
  return this->norm_params_;
};

}  // namespace s21
