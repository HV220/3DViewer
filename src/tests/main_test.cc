#include <gtest/gtest.h>

#include "../app/controllers/headers/main_controller.h"

using namespace s21;

class SettingsTest : public ::testing::Test {
 public:
  void SetUp() override {
    QtSceneDrawer *q_scene_drawer = new QtSceneDrawer();
    DecoratorSceneDrawer *decorator_scene_drawer =
        new DecoratorSceneDrawer(q_scene_drawer);
    Facade *model = new Facade(decorator_scene_drawer);
    MainController *controller = new MainController(model);

    this->model = model;
    this->scene_drawer = q_scene_drawer;
    this->decorator_scene_drawer = decorator_scene_drawer;
    this->controller = controller;
  }

  void TearDown() override {
    delete this->scene_drawer;
    delete this->decorator_scene_drawer;
    delete this->model;
    delete this->controller;
  }
  BaseSceneDrawer *scene_drawer;
  DecoratorSceneDrawer *decorator_scene_drawer;
  Facade *model;
  MainController *controller;
  std::map<bool, std::string> res;
};

TEST_F(SettingsTest, SetPathAction_GetPathAction) {
  res = controller->SetPathAction("");

  EXPECT_EQ(controller->GetPathAction().begin()->second, "");
  EXPECT_EQ(res.begin()->first, true);
}

TEST_F(SettingsTest, LoadSceneAction) {
  res = controller->LoadSceneAction("saasfsdf");

  EXPECT_EQ(res.begin()->first, false);

  res = controller->LoadSceneAction("");

  EXPECT_EQ(res.begin()->first, false);

  res = controller->LoadSceneAction("object_files/cube.obj");

  EXPECT_EQ(res.begin()->first, true);

  res = controller->LoadSceneAction("object_files/cottage_obj.obj");

  EXPECT_EQ(res.begin()->first, true);

  res = controller->LoadSceneAction(
      "app/models/sources/qt_normalization_parameters_model.cc");

  EXPECT_EQ(res.begin()->first, false);
}

TEST_F(SettingsTest, SaveSettingsAction_LoadSettingsAction) {
  res = controller->SaveSettingsAction();

  std::string q_path = controller->GetPathAction().begin()->second;

  EXPECT_EQ(res.begin()->first, true);

  res = controller->LoadSettingsAction();

  std::string q1_path = controller->GetPathAction().begin()->second;

  EXPECT_EQ(res.begin()->first, true);
  EXPECT_EQ(q_path, q1_path);
}

TEST_F(SettingsTest, SetSettingAction_GetSettingAction) {
  res = controller->SetSettingAction("x_shift", 12);

  EXPECT_EQ(res.begin()->first, true);

  EXPECT_EQ(this->controller->GetSettingAction("x_shift").begin()->second, 12);

  res = controller->SetSettingAction("x_shift", std::nan(""));

  EXPECT_EQ(res.begin()->first, false);

  EXPECT_EQ(this->controller->GetSettingAction("test").begin()->first, false);
}

TEST_F(SettingsTest, SetColorAction_GetColorAction) {
  res = controller->SetColorAction("vertex_color", 1.0, 0.0, 0.0);

  EXPECT_EQ(res.begin()->first, true);

  EXPECT_EQ(
      this->controller->GetColorAction("red_vertex_color").begin()->second,
      1.0);

  res = controller->SetColorAction("vertex_color", std::nan(""), 0.0, 0.0);

  EXPECT_EQ(res.begin()->first, false);

  res = controller->SetColorAction("vertex_color", 1.0, std::nan(""), 0.0);

  EXPECT_EQ(res.begin()->first, false);

  res = controller->SetColorAction("vertex_color", 1.0, 0.0, std::nan(""));

  EXPECT_EQ(res.begin()->first, false);

  res = controller->SetColorAction("test", 1.0, 0.0, 0.0);

  EXPECT_EQ(res.begin()->first, false);

  res = controller->SetColorAction("", 1.0, 0.0, 0.0);

  EXPECT_EQ(res.begin()->first, false);

  EXPECT_EQ(this->controller->GetColorAction("test").begin()->first, false);
}

TEST_F(SettingsTest, GetNormalaizeFasets) {
  std::vector<std::vector<uint32_t>> faset =
      this->controller->GetNormalaizeFasets();

  EXPECT_EQ(faset.size(), 0);

  res = controller->LoadSceneAction("object_files/cube.obj");

  faset = this->controller->GetNormalaizeFasets();

  ASSERT_TRUE(faset.size() != 0);
}

TEST_F(SettingsTest, GetNormalaizeVertexes) {
  std::vector<double> vertex = this->controller->GetNormalaizeVertexes();

  EXPECT_EQ(vertex.size(), 0);

  res = controller->LoadSceneAction("object_files/cube.obj");

  vertex = this->controller->GetNormalaizeVertexes();

  ASSERT_TRUE(vertex.size() != 0);
}

TEST_F(SettingsTest, GetNormalaizeMaxCoordinate) {
  double max_coordinate =
      this->controller->GetNormalaizeMaxCoordinate().begin()->second;

  EXPECT_EQ(max_coordinate, 0.0);

  res = controller->LoadSceneAction("object_files/cube.obj");

  EXPECT_EQ(res.begin()->first, true);

  double max_coordinate_2 =
      this->controller->GetNormalaizeMaxCoordinate().begin()->second;

  ASSERT_TRUE(max_coordinate != max_coordinate_2);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
