#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_FACADE_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_FACADE_MODEL_H_

#include <memory>

#include "decorator_scene_drawer_model.h"
#include "facade_operations_result_model.h"

namespace s21 {
class Facade {
 public:
  Facade(DecoratorSceneDrawer *other_scene_drawer)
      : sceneDrawer_(other_scene_drawer) {}

  FacadeOperationsResult LoadScene(const std::string &path);
  FacadeOperationsResult SaveSetting();
  FacadeOperationsResult LoadSetting();
  FacadeOperationsResult SetPath(const std::string &path);
  FacadeOperationsResult SetSetting(const std::string &method_name,
                                    const double &value);
  FacadeOperationsResult SetColor(const std::string &method_name,
                                  const float &red_color,
                                  const float &green_color,
                                  const float &blue_color);
  std::string GetPath();
  double GetSetting(const std::string &method_name);
  float GetColor(const std::string &method_name);
  std::any GetFacets();
  std::any GetVertexes();
  std::any GetMaxCoordinate();

 private:
  FacadeOperationsResult CreateErrorReport(const std::string &error,
                                           bool is_succes);
  Scene scene_;
  DecoratorSceneDrawer *sceneDrawer_;
};
}  // namespace s21
#endif  //  CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_FACADE_MODEL_H_
