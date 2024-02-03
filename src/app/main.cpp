#include "views/headers/mainwindow.h"
#include "models/headers/main_model.h"
#include "controllers/headers/main_controller.h"
#include <QApplication>
#include <QDebug>

using namespace s21;

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    QtSceneDrawer qt_drawer;
    DecoratorSceneDrawer decorator_scene_drawer(&qt_drawer);

    Facade model(&decorator_scene_drawer);

    MainController controller(&model);

    MainWindow w(&controller);

    w.show();

    return a.exec();
}
