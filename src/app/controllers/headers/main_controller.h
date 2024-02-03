#ifndef CPP4_3DVIEWER_V2_0_2_SRC_CONTROLLERS_HEADERS_MAIN_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_CONTROLLERS_HEADERS_MAIN_CONTROLLER_H_

#include <any>
#include <map>

#include "../../models/headers/main_model.h"

namespace s21 {
class MainController {
 public:
  MainController(Facade *other_model) : model_(other_model) {}
  std::map<bool, std::string> LoadSceneAction(const std::string &path);
  std::map<bool, std::string> SaveSettingsAction();
  std::map<bool, std::string> LoadSettingsAction();
  std::map<bool, std::string> SetPathAction(const std::string &path);
  std::map<bool, std::string> SetSettingAction(const std::string &method_name,
                                               const double &value);
  std::map<bool, std::string> SetColorAction(const std::string &method_name,
                                             const float &red_color,
                                             const float &green_color,
                                             const float &blue_color);

  std::map<bool, std::string> GetPathAction();
  std::map<bool, double> GetSettingAction(const std::string &method_name);
  std::map<bool, float> GetColorAction(const std::string &method_name);
  std::vector<std::vector<uint32_t>> GetNormalaizeFasets();
  std::vector<double> GetNormalaizeVertexes();
  std::map<bool, double> GetNormalaizeMaxCoordinate();

 private:
  Facade *model_;
};
}  // namespace s21
#endif  //  CPP4_3DVIEWER_V2_0_2_SRC_CONTROLLERS_HEADERS_MAIN_CONTROLLER_H_
