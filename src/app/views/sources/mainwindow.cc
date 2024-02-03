#include "../headers/mainwindow.h"

#include "ui_mainwindow.h"

namespace s21 {
MainWindow::MainWindow(MainController *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller) {
  ui->setupUi(this);

  screen_ = new QImage;
  ui->opengl_widget->SetController(this->controller_);
  if (!this->controller_->GetPathAction().begin()->second.empty()) {
    DrawScene();
  }
  SetSettingOnWindow();

  connect(ui->x_shift, SIGNAL(valueChanged(double)), this,
          SLOT(SetSetting(double)));
  connect(ui->y_shift, SIGNAL(valueChanged(double)), this,
          SLOT(SetSetting(double)));
  connect(ui->z_shift, SIGNAL(valueChanged(double)), this,
          SLOT(SetSetting(double)));
  connect(ui->x_scale, SIGNAL(valueChanged(double)), this,
          SLOT(SetSetting(double)));
  connect(ui->y_scale, SIGNAL(valueChanged(double)), this,
          SLOT(SetSetting(double)));
  connect(ui->z_scale, SIGNAL(valueChanged(double)), this,
          SLOT(SetSetting(double)));
  connect(ui->x_rotate, SIGNAL(valueChanged(double)), this,
          SLOT(SetSetting(double)));
  connect(ui->y_rotate, SIGNAL(valueChanged(double)), this,
          SLOT(SetSetting(double)));
  connect(ui->z_rotate, SIGNAL(valueChanged(double)), this,
          SLOT(SetSetting(double)));
  connect(ui->thickness_of_edges, SIGNAL(valueChanged(double)), this,
          SLOT(SetSetting(double)));
  connect(ui->size_of_vertexes, SIGNAL(valueChanged(double)), this,
          SLOT(SetSetting(double)));
  connect(ui->type_of_rotate, SIGNAL(currentIndexChanged(int)), this,
          SLOT(SetType(int)));
  connect(ui->type_of_projection, SIGNAL(currentIndexChanged(int)), this,
          SLOT(SetType(int)));
  connect(ui->type_of_edges, SIGNAL(currentIndexChanged(int)), this,
          SLOT(SetType(int)));
  connect(ui->type_of_vertexes, SIGNAL(currentIndexChanged(int)), this,
          SLOT(SetType(int)));
}

MainWindow::~MainWindow() {
  this->controller_->SaveSettingsAction();
  delete this->gif_;
  delete this->screen_;
  delete this->gif_timer_;
  delete this->w;
  delete ui;
}

void MainWindow::on_open_file_clicked() {
  QString path = QFileDialog::getOpenFileName(
      this, "Выбрать файл объекта", "../object_files", tr("Objects (*.obj)"));
  if (!path.isEmpty()) {
    this->controller_->SetPathAction(path.toStdString());
    DrawScene();
    InfoAboutObject();
  }
}

void MainWindow::on_vertex_color_clicked() {
  QColor vertex_color =
      QColorDialog::getColor(Qt::white, this, "Choose a color");
  if (vertex_color.isValid()) {
    this->controller_->SetColorAction(
        ui->vertex_color->objectName().toStdString(), vertex_color.redF(),
        vertex_color.greenF(), vertex_color.blueF());
  }
}

void MainWindow::on_line_color_clicked() {
  QColor line_color = QColorDialog::getColor(Qt::white, this, "Choose a color");
  if (line_color.isValid()) {
    this->controller_->SetColorAction(
        ui->line_color->objectName().toStdString(), line_color.redF(),
        line_color.greenF(), line_color.blueF());
  }
}

void MainWindow::on_background_color_clicked() {
  QColor background_color =
      QColorDialog::getColor(Qt::white, this, "Choose a color");
  if (background_color.isValid()) {
    this->controller_->SetColorAction(
        ui->background_color->objectName().toStdString(),
        background_color.redF(), background_color.greenF(),
        background_color.blueF());
  }
}

void MainWindow::SetSetting(double value) {
  QDoubleSpinBox *object_name = (QDoubleSpinBox *)sender();

  this->controller_->SetSettingAction(object_name->objectName().toStdString(),
                                      value);
}

void MainWindow::SetType(int value) {
  QComboBox *object_name = (QComboBox *)sender();

  this->controller_->SetSettingAction(object_name->objectName().toStdString(),
                                      value);
  if (object_name->objectName() == "type_of_rotate" && value == 0) {
    ui->x_rotate->setValue(
        this->controller_->GetSettingAction("x_rotate").begin()->second);
    ui->y_rotate->setValue(
        this->controller_->GetSettingAction("y_rotate").begin()->second);
  }
}

void MainWindow::DrawScene() {
  this->controller_->LoadSceneAction(
      this->controller_->GetPathAction().begin()->second);
  ui->opengl_widget->TestDrawer();
}

void MainWindow::SetSettingOnWindow() {
  ui->x_shift->setValue(
      this->controller_->GetSettingAction("x_shift").begin()->second);
  ui->y_shift->setValue(
      this->controller_->GetSettingAction("y_shift").begin()->second);
  ui->z_shift->setValue(
      this->controller_->GetSettingAction("z_shift").begin()->second);
  ui->x_scale->setValue(
      this->controller_->GetSettingAction("x_scale").begin()->second);
  ui->y_scale->setValue(
      this->controller_->GetSettingAction("y_scale").begin()->second);
  ui->z_scale->setValue(
      this->controller_->GetSettingAction("z_scale").begin()->second);
  ui->x_rotate->setValue(
      this->controller_->GetSettingAction("x_rotate").begin()->second);
  ui->y_rotate->setValue(
      this->controller_->GetSettingAction("y_rotate").begin()->second);
  ui->z_rotate->setValue(
      this->controller_->GetSettingAction("z_rotate").begin()->second);
  ui->thickness_of_edges->setValue(
      this->controller_->GetSettingAction("thickness_of_edges")
          .begin()
          ->second);
  ui->size_of_vertexes->setValue(
      this->controller_->GetSettingAction("size_of_vertexes").begin()->second);
  ui->type_of_rotate->setCurrentIndex(
      this->controller_->GetSettingAction("type_of_rotate").begin()->second);
  ui->type_of_projection->setCurrentIndex(
      this->controller_->GetSettingAction("type_of_projection")
          .begin()
          ->second);
  ui->type_of_edges->setCurrentIndex(
      this->controller_->GetSettingAction("type_of_edges").begin()->second);
  ui->type_of_vertexes->setCurrentIndex(
      this->controller_->GetSettingAction("type_of_vertexes").begin()->second);
  InfoAboutObject();
}

void MainWindow::on_set_default_clicked() {
  ui->x_shift->setValue(0);
  ui->y_shift->setValue(0);
  ui->z_shift->setValue(0);
  ui->x_scale->setValue(1);
  ui->y_scale->setValue(1);
  ui->z_scale->setValue(1);
  ui->type_of_rotate->setCurrentIndex(0);
  ui->x_rotate->setValue(0);
  ui->y_rotate->setValue(0);
  ui->z_rotate->setValue(0);
  ui->thickness_of_edges->setValue(0);
  ui->size_of_vertexes->setValue(0);
  ui->type_of_projection->setCurrentIndex(0);
  ui->type_of_edges->setCurrentIndex(0);
  ui->type_of_vertexes->setCurrentIndex(0);
  ui->info_about_object->setText("Загрузите объект");

  this->controller_->SetPathAction("");
  this->controller_->SetColorAction("vertex_color", 1.0, 0.0, 0.0);
  this->controller_->SetColorAction("line_color", 0.596, 1.0, 0.133);
  this->controller_->SetColorAction("background_color", 0.255, 0.255, 1.0);
}

void MainWindow::InfoAboutObject() {
  QString name_of_object = QString::fromStdString(
      this->controller_->GetPathAction().begin()->second);
  if (name_of_object.isEmpty()) {
    this->ui->info_about_object->setText("Загрузите объект");
  } else {
    name_of_object.remove(0, (name_of_object.lastIndexOf('/') + 1));
    this->ui->info_about_object->setText(
        "Название:  " + name_of_object + "\nКол-во вершин:  " +
        QString::number(this->controller_->GetNormalaizeVertexes().size() / 3) +
        "\nКол-во полигонов:  " +
        QString::number(this->controller_->GetNormalaizeFasets().size()));
  }
}

void MainWindow::on_screenshot_clicked() {
  *screen_ = ui->opengl_widget->grabFramebuffer();
  QString file = QFileDialog::getSaveFileName(this, "Save as...",
                                              QDir::currentPath() + "/../save",
                                              "BMP (*.bmp);; JPEG (*.jpeg)");
  screen_->save(file);
}

void MainWindow::on_gif_clicked() {
  gif_ = new QGifImage(QSize(640, 480));
  gif_->setDefaultDelay(100);
  time_ = 0;
  gif_timer_ = new QTimer(this);
  connect(gif_timer_, SIGNAL(timeout()), this, SLOT(MakeGif()));
  gif_timer_->start(100);
}

void MainWindow::MakeGif() {
  ++time_;
  *screen_ = ui->opengl_widget->grabFramebuffer();
  *screen_ = screen_->scaled(640, 480, Qt::IgnoreAspectRatio,
                             Qt::SmoothTransformation);
  gif_->addFrame(*screen_, 100);
  if (time_ == 50) {
    gif_timer_->stop();
    QString path = QFileDialog::getSaveFileName(
        this, tr("Save screenshot"), QDir::currentPath() + "/../save",
        tr("GIF screenshot (*.gif)"));
    gif_->save(path);
    delete gif_;
  }
}

}  // namespace s21
