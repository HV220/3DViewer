#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_SCENE_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_SCENE_MODEL_H_
#include "figure_model.h"

namespace s21 {
class Scene {
 public:
  const Figure &GetFigure() const;
  Figure &GetFigure();
  void clear();

 private:
  Figure figure_;
};
}  // namespace s21
#endif  //  CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_SCENE_MODEL_H_
