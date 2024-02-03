#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_BASE_NORMALIZATION_PARAMETERS_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_BASE_NORMALIZATION_PARAMETERS_MODEL_H_
#include <any>

#include "scene_model.h"

namespace s21 {
class BaseNormalizationParameter {
 public:
  virtual void NormalaizeParametersScene(const Scene &scene) = 0;
  virtual void NormalaizeVertexes(const Scene &scene) = 0;
  virtual void NormalaizeFacets(const Scene &scene) = 0;
  virtual std::any GetFacets() const = 0;
  virtual std::any GetVertexes() const = 0;
  virtual std::any GetMaxCoordinate() const = 0;
  virtual void clearParams() = 0;
};
};  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_BASE_NORMALIZATION_PARAMETERS_MODEL_H_
