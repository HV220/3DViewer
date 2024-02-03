#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_VIEWS_HEADERS_VISUALIZATION3D_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_VIEWS_HEADERS_VISUALIZATION3D_H_

#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QTimer>

#include "../../controllers/headers/main_controller.h"

namespace s21 {
class Visualization3D : public QOpenGLWidget {
  Q_OBJECT
 public:
  explicit Visualization3D(QWidget *parent = nullptr);
  ~Visualization3D();
  void SetController(MainController *controller);
  void TestDrawer();

 private:
  void mousePressEvent(QMouseEvent *mo) override;
  void mouseMoveEvent(QMouseEvent *mo) override;
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void Draw();

  MainController *controller_{};
  QTimer gl_timer_;
  QPoint mPos_;
  double xRot_ = 0, yRot_ = 0, zRot_ = 0, max_ = 0;
  std::vector<double> v_vector_;
  std::vector<std::vector<uint32_t>> f_vector_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_2_SRC_APP_VIEWS_HEADERS_VISUALIZATION3D_H_
