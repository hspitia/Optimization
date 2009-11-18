TEMPLATE = app

TARGET = app

QT += core \
    gui

HEADERS += src/gui/MainWindow.h

SOURCES += src/gui/MainWindow.cpp \
    src/app/main.cpp

FORMS += src/gui/MainWindow.ui

DEPENDPATH += . \
    src/ \
    src/app \
    src/gui \

INCLUDEPATH += . \
    src/ \
    src/app \
    src/gui

LIBS += -L/usr/lib/lpsolve \
    -llpsolve55 \
    -L/usr/lib \
    -lcolamd


RESOURCES += 
