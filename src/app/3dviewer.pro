macx {
    QT       += core gui openglwidgets
} else:win32 {
    QT       += core gui openglwidgets
    LIBS     += -lopengl32 -lglu32
} else {
    QT       += core gui opengl
    LIBS     += -lOpenGL -lGLU -lglut
}

include(models/gif_model/src/gifimage/qtgifimage.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controllers/sources/main_controller.cc \
    main.cpp \
    models/sources/decorator_scene_drawer_model.cc \
    models/sources/edge_model.cc \
    models/sources/facade_model.cc \
    models/sources/facade_operations_result_model.cc \
    models/sources/figure_model.cc \
    models/sources/qt_file_reader_model.cc \
    models/sources/qt_normalization_parameters_model.cc \
    models/sources/qt_scene_drawer_model.cc \
    models/sources/qt_settings_model.cc \
    models/sources/scene_model.cc \
    models/sources/vertex_model.cc \
    views/sources/mainwindow.cc \
    views/sources/visualization3d.cc

HEADERS += \
    controllers/headers/main_controller.h \
    models/headers/3dpoint_model.h \
    models/headers/base_file_reader_model.h \
    models/headers/base_normalization_parameters_model.h \
    models/headers/base_scene_drawer_model.h \
    models/headers/base_settings_model.h \
    models/headers/decorator_scene_drawer_model.h \
    models/headers/edge_model.h \
    models/headers/qt_file_reader_model.h \
    models/headers/qt_normalization_parameters_model.h \
    models/headers/qt_settings_model.h \
    models/headers/facade_model.h \
    models/headers/facade_operations_result_model.h \
    models/headers/figure_model.h \
    models/headers/main_model.h \
    models/headers/qt_scene_drawer_model.h \
    models/headers/scene_model.h \
    models/headers/vertex_model.h \
    views/headers/mainwindow.h \
    views/headers/visualization3d.h

FORMS += \
    views/uis/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
