#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_VERTEX_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_VERTEX_MODEL_H_

#include <vector>

#include "3dpoint_model.h"

namespace s21 {
class Vertex {
 public:
  const Point3D &GetPosition() const;

  void SetPosition(const double &x, const double &y, const double &z);

 private:
  Point3D position_;
};
}  // namespace s21
#endif  //  CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_VERTEX_MODEL_H_
