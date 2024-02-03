#ifndef CPP4_3DVIEWER_V2_0_2_SRC_MODELS_HEADERS_NORMALISATION_PARAMETERS_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_MODELS_HEADERS_NORMALISATION_PARAMETERS_MODEL_H_

#include <algorithm>
#include <cmath>
#include <vector>

#include "base_normalization_parameters_model.h"
#include "scene_model.h"

namespace s21 {
class QtNormalizationParameters : public BaseNormalizationParameter {
 public:
  void NormalaizeParametersScene(const Scene &scene) override;
  void NormalaizeVertexes(const Scene &scene) override;
  void NormalaizeFacets(const Scene &scene) override;
  std::any GetFacets() const override;
  std::any GetVertexes() const override;
  std::any GetMaxCoordinate() const override;
  void clearParams() override;

 private:
  std::vector<double> vertex_normal_;
  std::vector<std::vector<uint32_t>> facet_normal_;
  double max_coordinate_{};
};
}  // namespace s21
#endif  //  CPP4_3DVIEWER_V2_0_2_SRC_MODELS_HEADERS_NORMALISATION_PARAMETERS_MODEL_H_
