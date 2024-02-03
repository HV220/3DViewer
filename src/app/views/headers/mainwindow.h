#ifndef CPP4_3DVIEWER_V2_0_2_SRC_APP_VIEWS_HEADERS_MAINWINDOW_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_APP_VIEWS_HEADERS_MAINWINDOW_H_

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QString>
#include <QWidget>
#include <string>

#include "../../controllers/headers/main_controller.h"
#include "../../models/gif_model/src/gifimage/qgifimage.h"
#include "visualization3d.h"

using namespace s21;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(MainController *controller, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_open_file_clicked();
  void on_vertex_color_clicked();
  void on_line_color_clicked();
  void on_background_color_clicked();
  void on_set_default_clicked();
  void on_screenshot_clicked();
  void on_gif_clicked();
  void SetSettingOnWindow();
  void SetSetting(double value);
  void SetType(int value);
  void MakeGif();
  void InfoAboutObject();
  void DrawScene();

 private:
  Ui::MainWindow *ui;
  QWidget *w;
  MainController *controller_;
  QTimer *gif_timer_;
  int time_{};
  QGifImage *gif_;
  QImage *screen_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_2_SRC_APP_VIEWS_HEADERS_MAINWINDOW_H_
