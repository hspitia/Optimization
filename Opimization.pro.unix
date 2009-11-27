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
LIBS += -L/usr/lib/lpsolve \
    -llpsolve55 \
    -L/usr/lib \
    -lcolamd
RESOURCES += resources/resources.qrc
