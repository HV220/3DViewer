#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_BASE_SETTINGS_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_BASE_SETTINGS_MODEL_H_

#include <string>

namespace s21 {
class BaseSettings {
 public:
  virtual void SetPath(const std::string &path) = 0;
  virtual void SetSetting(const std::string &method_name,
                          const double &value) = 0;
  virtual void SetColor(const std::string &method_name, const float &red_color,
                        const float &green_color, const float &blue_color) = 0;
  virtual std::string GetPath() const = 0;
  virtual double GetSetting(const std::string &method_name) const = 0;
  virtual float GetColor(const std::string &method_name) const = 0;
  virtual void SaveSettings() const = 0;
  virtual void LoadSettings() = 0;
};

};  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_APP_MODELS_HEADERS_BASE_SETTINGS_MODEL_H_
