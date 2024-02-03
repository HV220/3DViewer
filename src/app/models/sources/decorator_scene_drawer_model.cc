#include "../headers/main_model.h"

namespace s21 {
bool DecoratorSceneDrawer::LoadScene(const Scene &scene) {
  try {
    this->sceneDrawer_->LoadScene(scene);
  } catch (...) {
    throw;
  }
  return true;
};

BaseSettings &DecoratorSceneDrawer::GetSettings() {
  try {
    return this->sceneDrawer_->GetSettings();
  } catch (...) {
    throw;
  }
};

const BaseNormalizationParameter &
DecoratorSceneDrawer::GetNormalaizeParamsScene() {
  try {
    return this->sceneDrawer_->GetNormalaizeParamsScene();
  } catch (...) {
    throw;
  }
};

Scene DecoratorSceneDrawer::ReadFile(const std::string &path) {
  try {
    return this->sceneDrawer_->ReadFile(path);
  } catch (...) {
    throw;
  }
};

void DecoratorSceneDrawer::SaveSetting() {
  try {
    this->sceneDrawer_->SaveSetting();
  } catch (...) {
    throw;
  }
};

void DecoratorSceneDrawer::LoadSetting() {
  try {
    this->sceneDrawer_->LoadSetting();
  } catch (...) {
    throw;
  }
};

};  // namespace s21
