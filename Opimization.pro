TEMPLATE = app
TARGET = app
QT += core \
    gui
HEADERS += src/app/ParametersSet.h \
    src/app/ApplicationController.h \
    src/app/FileParser.h \
    src/gui/MainWindow.h
SOURCES += src/app/ParametersSet.cpp \
    src/app/ApplicationController.cpp \
    src/app/FileParser.cpp \
    src/gui/MainWindow.cpp \
    src/app/main.cpp
FORMS += src/gui/MainWindow.ui
DEPENDPATH += . \
    src/ \
    src/app \
    src/gui 
INCLUDEPATH += . \
    src/ \
    src/app \
    src/gui 
unix {
  LIBS += -L/usr/lib/lpsolve \
      -llpsolve55 \
      -L/usr/lib \
      -lcolamd
}
win32 {
  DEPENDPATH += include \
     include/lpsolve
  INCLUDEPATH += include/ \
     include/lpsolve
  LIBS += -L"lib" \
      -llpsolve55
  CONFIG += console
} 
RESOURCES += resources/resources.qrc
