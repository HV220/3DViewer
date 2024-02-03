#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_FIGURE_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_FIGURE_MODEL_H_

#include <stdint.h>

#include <vector>

#include "edge_model.h"
#include "vertex_model.h"

namespace s21 {
class Figure {
 public:
  Figure() = default;
  ~Figure();
  const std::vector<Vertex> &GetVertexes() const;
  const std::vector<Edge> &GetEdges() const;
  void PushVertex(const double &x, const double &y, const double &z);
  void PushEdge(const std::vector<int> &other);
  void clearFigure();

 private:
  std::vector<Vertex> vertexes_{};
  std::vector<Edge> edges_{};
};
}  // namespace s21
#endif  //  CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_FIGURE_MODEL_H_
