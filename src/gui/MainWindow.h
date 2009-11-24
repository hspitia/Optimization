#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt
#include <QtGui/QMainWindow>
#include <QtGui/QFileDialog>
#include <QtCore/QString>
#include <QtGui/QWidget>
#include <QtGui/QImage>
#include <QtGui/QPainter>

// Project
#include "app/ApplicationController.h"
#include "gui/ImageViewer.h" 
#include "ui_MainWindow.h"


// Cyclic reference 
class ApplicationController;

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
    MainWindow(ApplicationController *parentApplication = 0, 
               QWidget * parent = 0);
    ~MainWindow();

    
  private:
    // Atributos
    Ui::MainWindowClass * ui;
    ApplicationController * parentApplication;
    int gridSize;
    int margin;
    int imgSize;

    void connectSignalsSlots();
    void initComponents();
    void setUpScene(const int & regionSize,
                    const QList<int> & townsNumbers,
                    const QList<QPointF> & townsCoordinates);
    void paintRegion(const int & regionSize);
    void paintTowns(const QList<int> & townsNumbers,
                    const QList<QPointF> & townsCoordinates);
  
  private slots:
    void newProblemInput();
    
};

#endif // MAINWINDOW_H
