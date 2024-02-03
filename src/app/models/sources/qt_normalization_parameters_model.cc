#include "../headers/main_model.h"

namespace s21 {

void QtNormalizationParameters::NormalaizeParametersScene(const Scene &scene) {
  NormalaizeVertexes(scene);
  NormalaizeFacets(scene);
}

void QtNormalizationParameters::NormalaizeVertexes(const Scene &scene) {
  if (!scene.GetFigure().GetVertexes().size())
    throw std::logic_error("scene is empty");

  double max_x, min_x;
  double max_y, min_y;
  double max_z, min_z;

  std::vector<Vertex> tmp_vertexes = scene.GetFigure().GetVertexes();

  auto init_it = tmp_vertexes.begin();
  max_x = min_x = init_it->GetPosition().x_;
  max_y = min_y = init_it->GetPosition().y_;
  max_z = min_z = init_it->GetPosition().z_;
  for (auto it = tmp_vertexes.begin(); it != tmp_vertexes.end(); ++it) {
    if (it->GetPosition().x_ > max_x) {
      max_x = it->GetPosition().x_;
    }
    if (it->GetPosition().y_ > max_y) {
      max_y = it->GetPosition().y_;
    }
    if (it->GetPosition().z_ > max_z) {
      max_z = it->GetPosition().z_;
    }
    if (it->GetPosition().x_ < min_x) {
      min_x = it->GetPosition().x_;
    }
    if (it->GetPosition().y_ < min_y) {
      min_y = it->GetPosition().y_;
    }
    if (it->GetPosition().z_ < min_z) {
      min_z = it->GetPosition().z_;
    }
  }
  double x_shift = (-1) * (max_x + min_x) / 2;
  double y_shift = (-1) * (max_y + min_y) / 2;
  double z_shift = (-1) * (max_z + min_z) / 2;
  this->max_coordinate_ = std::max(
      std::fabs(x_shift + max_x),
      std::max(std::fabs(y_shift + max_y), std::fabs(z_shift + max_z)));
  for (auto it = tmp_vertexes.begin(); it != tmp_vertexes.end(); ++it) {
    vertex_normal_.push_back(it->GetPosition().x_ + x_shift);
    vertex_normal_.push_back(it->GetPosition().y_ + y_shift);
    vertex_normal_.push_back(it->GetPosition().z_ + z_shift);
  }
}

void QtNormalizationParameters::NormalaizeFacets(const Scene &scene) {
  if (!scene.GetFigure().GetEdges().size())
    throw std::logic_error("scene is empty");

  std::vector<int> one_facet;
  std::vector<uint32_t> one_normal_facet;

  std::vector<Edge> tmp_facets = scene.GetFigure().GetEdges();
  int correct_value = vertex_normal_.size() / 3 + 1;

  for (size_t i{}; i < tmp_facets.size(); ++i) {
    for (size_t j{}; j < tmp_facets[i].GetEdge().size(); ++j) {
      one_facet.push_back(tmp_facets[i].GetEdge()[j] - 1);
      if (j != tmp_facets[i].GetEdge().size() - 1) {
        one_facet.push_back(tmp_facets[i].GetEdge()[j + 1] - 1);
      } else {
        one_facet.push_back(tmp_facets[i].GetEdge()[0] - 1);
      }
    }
    if (one_facet[0] < 0) {
      for (size_t j{}; j < one_facet.size(); ++j) {
        one_normal_facet.push_back(one_facet[j] + correct_value);
      }
    } else {
      for (size_t j{}; j < one_facet.size(); ++j) {
        one_normal_facet.push_back(one_facet[j]);
      }
    }
    facet_normal_.push_back(one_normal_facet);
    one_normal_facet.clear();
    one_facet.clear();
  }
}

std::any QtNormalizationParameters::GetVertexes() const {
  return this->vertex_normal_;
}

std::any QtNormalizationParameters::GetFacets() const {
  return this->facet_normal_;
}

std::any QtNormalizationParameters::GetMaxCoordinate() const {
  return this->max_coordinate_;
}

void QtNormalizationParameters::clearParams() {
  this->facet_normal_.clear();
  this->vertex_normal_.clear();
  this->max_coordinate_ = 0;
};
}  // namespace s21
