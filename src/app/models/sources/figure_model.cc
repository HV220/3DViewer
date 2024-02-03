#include "../headers/main_model.h"

namespace s21 {
const std::vector<Vertex> &Figure::GetVertexes() const {
  return this->vertexes_;
}

const std::vector<Edge> &Figure::GetEdges() const { return this->edges_; }

void Figure::PushEdge(const std::vector<int> &other) {
  Edge edge;
  edge.SetEdge(other);
  this->edges_.push_back(edge);
}

void Figure::PushVertex(const double &x, const double &y, const double &z) {
  Vertex vertex;
  vertex.SetPosition(x, y, z);
  this->vertexes_.push_back(vertex);
}

void Figure::clearFigure() {
  this->edges_.clear();
  this->vertexes_.clear();
}

Figure::~Figure() { this->clearFigure(); }
}  // namespace s21
