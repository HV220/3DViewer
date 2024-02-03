#include "../headers/visualization3d.h"

namespace s21 {
Visualization3D::Visualization3D(QWidget *parent) : QOpenGLWidget(parent) {
  connect(&gl_timer_, SIGNAL(timeout()), this, SLOT(update()));
  gl_timer_.start(50);
}

Visualization3D::~Visualization3D() {
  this->f_vector_.clear();
  this->v_vector_.clear();
}

void Visualization3D::initializeGL() { glEnable(GL_DEPTH_TEST); }

void Visualization3D::paintGL() {
  glClearColor(
      this->controller_->GetColorAction("red_background_color").begin()->second,
      this->controller_->GetColorAction("green_background_color")
          .begin()
          ->second,
      this->controller_->GetColorAction("blue_background_color")
          .begin()
          ->second,
      1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (this->controller_->GetSettingAction("type_of_projection")
          .begin()
          ->second == 0) {
    glOrtho(-max_, max_, -max_, max_, max_, 5 * max_);
  } else {
    glFrustum(-max_, max_, -max_, max_, max_, 5 * max_);
  }

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glScaled(this->controller_->GetSettingAction("x_scale").begin()->second,
           this->controller_->GetSettingAction("y_scale").begin()->second,
           this->controller_->GetSettingAction("z_scale").begin()->second);
  glTranslated(
      this->controller_->GetSettingAction("x_shift").begin()->second,
      this->controller_->GetSettingAction("y_shift").begin()->second,
      (-1) * this->controller_->GetSettingAction("z_shift").begin()->second -
          2.8 * this->max_);
  if (this->controller_->GetSettingAction("type_of_rotate").begin()->second ==
      1) {
    this->controller_->SetSettingAction("x_rotate", xRot_);
    this->controller_->SetSettingAction("y_rotate", yRot_);
    this->controller_->SetSettingAction("z_rotate", zRot_);
  } else {
    xRot_ = this->controller_->GetSettingAction("x_rotate").begin()->second;
    yRot_ = this->controller_->GetSettingAction("y_rotate").begin()->second;
    zRot_ = this->controller_->GetSettingAction("z_rotate").begin()->second;
  }
  glRotated(xRot_, 1, 0, 0);
  glRotated(yRot_, 0, 1, 0);
  glRotated(zRot_, 0, 0, 1);

  if (!this->controller_->GetPathAction().begin()->second.empty()) {
    Draw();
  }
}

void Visualization3D::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void Visualization3D::mousePressEvent(QMouseEvent *mo) {
  if (this->controller_->GetSettingAction("type_of_rotate").begin()->second ==
      1) {
    mPos_ = mo->pos();
  }
}

void Visualization3D::mouseMoveEvent(QMouseEvent *mo) {
  if (this->controller_->GetSettingAction("type_of_rotate").begin()->second ==
      1) {
    xRot_ += 1 / M_PI * (mo->pos().y() - mPos_.y());
    yRot_ += 1 / M_PI * (mo->pos().x() - mPos_.x());
    mPos_ = mo->pos();
    update();
  }
}

void Visualization3D::Draw() {
  glVertexPointer(3, GL_DOUBLE, 0, this->v_vector_.data());
  glEnableClientState(GL_VERTEX_ARRAY);

  if (this->controller_->GetSettingAction("type_of_vertexes").begin()->second) {
    glEnable(GL_POINT_SMOOTH);
  }
  glColor3d(
      this->controller_->GetColorAction("red_vertex_color").begin()->second,
      this->controller_->GetColorAction("green_vertex_color").begin()->second,
      this->controller_->GetColorAction("blue_vertex_color").begin()->second);
  glDrawArrays(GL_POINTS, 0, this->v_vector_.size() / 3);
  glPointSize(
      this->controller_->GetSettingAction("size_of_vertexes").begin()->second);
  glDisable(GL_POINT_SMOOTH);

  if (this->controller_->GetSettingAction("type_of_edges").begin()->second) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0X00FF);
  }
  glColor3d(
      this->controller_->GetColorAction("red_line_color").begin()->second,
      this->controller_->GetColorAction("green_line_color").begin()->second,
      this->controller_->GetColorAction("blue_line_color").begin()->second);
  for (size_t i = 0; i < this->f_vector_.size(); ++i) {
    glDrawElements(GL_LINE_LOOP, this->f_vector_[i].size(), GL_UNSIGNED_INT,
                   this->f_vector_[i].data());
  }
  glLineWidth(this->controller_->GetSettingAction("thickness_of_edges")
                  .begin()
                  ->second);
  glDisable(GL_LINE_STIPPLE);

  glDisableClientState(GL_VERTEX_ARRAY);
}

void Visualization3D::SetController(MainController *controller) {
  this->controller_ = controller;
}

void Visualization3D::TestDrawer() {
  this->v_vector_.clear();
  this->f_vector_.clear();
  this->v_vector_ = this->controller_->GetNormalaizeVertexes();
  this->f_vector_ = this->controller_->GetNormalaizeFasets();
  this->max_ = this->controller_->GetNormalaizeMaxCoordinate().begin()->second;
  xRot_ = this->controller_->GetSettingAction("x_rotate").begin()->second;
  yRot_ = this->controller_->GetSettingAction("y_rotate").begin()->second;
  zRot_ = this->controller_->GetSettingAction("z_rotate").begin()->second;
}

}  // namespace s21
