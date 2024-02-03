#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_EDGE_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_EDGE_MODEL_H_

#include <stdint.h>

#include <vector>

#include "vertex_model.h"

namespace s21 {
class Edge {
 public:
  Edge() = default;
  ~Edge();
  const std::vector<int> &GetEdge() const;
  void SetEdge(const std::vector<int> &edge);

 private:
  std::vector<int> edge_{};
};
}  // namespace s21
#endif  //  CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_EDGE_MODEL_H_
