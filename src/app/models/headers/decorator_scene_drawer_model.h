#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_DECORATOR_SCENE_DRAWER_MODEL_H
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_DECORATOR_SCENE_DRAWER_MODEL_H

#include "base_scene_drawer_model.h"
namespace s21 {

class DecoratorSceneDrawer : public BaseSceneDrawer {
 public:
  DecoratorSceneDrawer(BaseSceneDrawer *drawer) : sceneDrawer_(drawer) {}

  Scene ReadFile(const std::string &path) override;
  bool LoadScene(const Scene &scene) override;
  void SaveSetting() override;
  void LoadSetting() override;
  BaseSettings &GetSettings() override;
  const BaseNormalizationParameter &GetNormalaizeParamsScene() override;

 private:
  BaseSceneDrawer *sceneDrawer_;
};

};  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_DECORATOR_SCENE_DRAWER_MODEL_H
