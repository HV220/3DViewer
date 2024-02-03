#include "../headers/main_model.h"

namespace s21 {

void QtSettings::SetPath(const std::string &path) { this->path_ = path; };

std::string QtSettings::GetPath() const { return this->path_; };

QtSettings::QtSettings() { LoadSettings(); }

QtSettings::~QtSettings() { SaveSettings(); }

void QtSettings::SetSetting(const std::string &method_name,
                            const double &value) {
  this->checkMethodName(method_name);

  this->checkNumber(value);

  settings_[method_name] = value;
}

double QtSettings::GetSetting(const std::string &method_name) const {
  if (settings_.find(method_name) == settings_.end()) {
    throw std::runtime_error("Invalid method name");
  }

  return settings_.at(method_name);
}

void QtSettings::SetColor(const std::string &method_name,
                          const float &red_color, const float &green_color,
                          const float &blue_color) {
  if (method_name != "vertex_color" && method_name != "line_color" &&
      method_name != "background_color")
    throw std::runtime_error("Invalid method name");

  this->checkNumber(red_color);
  this->checkNumber(green_color);
  this->checkNumber(blue_color);

  this->colors_["red_" + method_name] = red_color;
  this->colors_["green_" + method_name] = green_color;
  this->colors_["blue_" + method_name] = blue_color;
}

float QtSettings::GetColor(const std::string &method_name) const {
  if (colors_.find(method_name) == colors_.end()) {
    throw std::runtime_error("Invalid method name");
  }

  return this->colors_.find(method_name)->second;
}

void QtSettings::SaveSettings() const {
  std::ofstream out;
  out.open("settings.txt");
  if (out.is_open()) {
    out << "path_=" << this->path_ << std::endl;
    for (auto it = settings_.begin(); it != settings_.end(); ++it) {
      out << it->first << "=" << it->second << std::endl;
    }
    for (auto it = colors_.begin(); it != colors_.end(); ++it) {
      out << it->first << "=" << it->second << std::endl;
    }
  }
}

void QtSettings::LoadSettings() {
  std::ifstream file;
  std::string str_tmp;
  file.open("settings.txt");
  if (file.is_open()) {
    std::string key;
    std::string value;
    while (std::getline(file, str_tmp)) {
      value = str_tmp.substr(str_tmp.find("=") + 1);
      key = str_tmp.erase(str_tmp.find("="));
      if (key == "path_") {
        this->path_ = value;
      } else if (key.find("color") != std::string::npos) {
        this->colors_[key] = std::stof(value);
      } else {
        this->settings_[key] = std::stod(value);
      }
    }
  }
  file.close();
}

void QtSettings::checkMethodName(const std::string &method_name) {
  if (settings_.find(method_name) == settings_.end()) {
    throw std::runtime_error("Invalid method name");
  }
}

void QtSettings::checkNumber(const float &value) {
  if (value == 0.0) {
    return;
  } else if (value < -10000.000000 || value > 10000.000000 ||
             !std::isnormal(value)) {
    throw std::runtime_error("Invalid value");
  }
}

void QtSettings::checkNumber(const double &value) {
  if (value == 0.0) {
    return;
  }

  if (value < -10000.000000 || value > 10000.000000 || !std::isnormal(value)) {
    throw std::runtime_error("Invalid value");
  }
}

}  // namespace s21
