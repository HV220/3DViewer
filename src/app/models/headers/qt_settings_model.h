#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_SETTINGS_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_SETTINGS_MODEL_H_

#include <iostream>
#include <map>
#include <string>

#include "base_settings_model.h"

namespace s21 {
class QtSettings : public BaseSettings {
 public:
  QtSettings();
  ~QtSettings();
  void SetPath(const std::string &path) override;
  void SetSetting(const std::string &method_name, const double &value) override;
  void SetColor(const std::string &method_name = "vertex_color",
                const float &red_color = 1.0, const float &green_color = 0.0,
                const float &blue_color = 0.0) override;
  std::string GetPath() const override;
  double GetSetting(const std::string &method_name) const override;
  float GetColor(const std::string &method_name) const override;
  void SaveSettings() const override;
  void LoadSettings() override;

 private:
  void checkMethodName(const std::string &method_name);
  void checkNumber(const float &value);
  void checkNumber(const double &value);
  std::string path_{};
  std::map<std::string, float> colors_{
      {"red_vertex_color", 1.0},       {"green_vertex_color", 0.0},
      {"blue_vertex_color", 0.0},      {"red_line_color", 0.596},
      {"green_line_color", 1.0},       {"blue_line_color", 0.133},
      {"red_background_color", 0.255}, {"green_background_color", 0.255},
      {"blue_background_color", 1.0},
  };
  std::map<std::string, double> settings_{{"x_shift", 0.0},
                                          {"y_shift", 0.0},
                                          {"z_shift", 0.0},
                                          {"x_scale", 1.0},
                                          {"y_scale", 1.0},
                                          {"z_scale", 1.0},
                                          {"x_rotate", 0.0},
                                          {"y_rotate", 0.0},
                                          {"z_rotate", 0.0},
                                          {"type_of_rotate", 0.0},
                                          {"type_of_projection", 0.0},
                                          {"type_of_edges", 0.0},
                                          {"thickness_of_edges", 0.0},
                                          {"type_of_vertexes", 0.0},
                                          {"size_of_vertexes", 0.0}};
};
}  // namespace s21
#endif  //  CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_SETTINGS_MODEL_H_
