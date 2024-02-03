#include "../headers/main_model.h"

namespace s21 {

Edge::~Edge() { this->edge_.clear(); };

const std::vector<int> &Edge::GetEdge() const { return this->edge_; }

void Edge::SetEdge(const std::vector<int> &edge) {
  for (auto it = edge.begin(); it != edge.end(); it++) {
    this->edge_.push_back(*it);
  }
}

}  // namespace s21
