TEMPLATE = app
TARGET = app
QT += core \
    gui
HEADERS += src/parser/Modeler.h \
    src/utils/Utils.h \
    src/utils/Problem.h \
    src/utils/tree.h \
    src/parser/ParametersSet.h \
    src/app/ApplicationController.h \
    src/parser/FileParser.h \
    src/gui/MainWindow.h
SOURCES += src/parser/Modeler.cpp \
    src/bab/BranchAndBound.cpp \
    src/utils/Problem.cpp \
    src/parser/ParametersSet.cpp \
    src/app/ApplicationController.cpp \
    src/parser/FileParser.cpp \
    src/gui/MainWindow.cpp \
    src/app/main.cpp
FORMS += src/gui/MainWindow.ui
DEPENDPATH += . \
    src/
INCLUDEPATH += . \
    src/
unix::LIBS += -L/usr/lib/lpsolve \
    -llpsolve55 \
    -L/usr/lib \
    -lcolamd
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
