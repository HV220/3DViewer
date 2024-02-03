#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_BASE_SCENE_DRAWER_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_BASE_SCENE_DRAWER_MODEL_H_
#include <string>

#include "base_normalization_parameters_model.h"
#include "base_settings_model.h"
#include "scene_model.h"

namespace s21 {
class BaseSceneDrawer {
 public:
  virtual Scene ReadFile(const std::string &path) = 0;
  virtual bool LoadScene(const Scene &scene) = 0;
  virtual void SaveSetting() = 0;
  virtual void LoadSetting() = 0;
  virtual BaseSettings &GetSettings() = 0;
  virtual const BaseNormalizationParameter &GetNormalaizeParamsScene() = 0;
  virtual ~BaseSceneDrawer() {}
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_BASE_SCENE_DRAWER_MODEL_H_
