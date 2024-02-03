#include "../headers/scene_model.h"

#include "../headers/main_model.h"

namespace s21 {
const Figure &Scene::GetFigure() const { return this->figure_; }

Figure &Scene::GetFigure() { return this->figure_; }

void Scene::clear() { this->figure_.clearFigure(); };
}  // namespace s21
