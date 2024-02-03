#ifndef CPP4_3DVIEWER_V2_0_2_SRC_MODELS_HEADERS_QT_SCENE_DRAWER_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_MODELS_HEADERS_QT_SCENE_DRAWER_MODEL_H_

#if !defined __APPLE__
#include <GL/glu.h>
#endif

#include "base_scene_drawer_model.h"
#include "qt_file_reader_model.h"
#include "qt_normalization_parameters_model.h"
#include "qt_settings_model.h"

namespace s21 {
class QtSceneDrawer : public BaseSceneDrawer {
 public:
  Scene ReadFile(const std::string &path) override;
  bool LoadScene(const Scene &scene) override;
  virtual void SaveSetting() override;
  virtual void LoadSetting() override;
  BaseSettings &GetSettings() override;
  const BaseNormalizationParameter &GetNormalaizeParamsScene() override;

 private:
  QtSettings settings_;
  QtNormalizationParameters norm_params_;
  QtFileReader file_reader_;
};
}  // namespace s21
#endif  //  CPP4_3DVIEWER_V2_0_2_SRC_MODELS_HEADERS_QT_SCENE_DRAWER_MODEL_H_
