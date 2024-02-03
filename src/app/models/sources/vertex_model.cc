#include "../headers/vertex_model.h"

#include "../headers/main_model.h"

namespace s21 {
const Point3D &s21::Vertex::GetPosition() const { return this->position_; }

void Vertex::SetPosition(const double &x, const double &y, const double &z) {
  this->position_.x_ = x;
  this->position_.y_ = y;
  this->position_.z_ = z;
}

}  // namespace s21
