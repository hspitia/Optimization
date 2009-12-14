#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt
#include <QtGui/QMainWindow>
#include <QtGui/QFileDialog>
#include <QtCore/QString>
#include <QtGui/QWidget>
#include <QtGui/QImage>
#include <QtGui/QPainter>
#include <QMessageBox>

// Project
#include "app/ApplicationController.h"
#include "ui_MainWindow.h"

// Std
#include <cmath>

// Cyclic reference 
class ApplicationController;

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
    MainWindow(ApplicationController *parentApplication = 0, 
               QWidget * parent = 0);
    ~MainWindow();

    void setUpScene(const int & regionSize,
                    const QList<int> & townsNumbers,
                    const QList<QPointF> & townsCoordinates);
    void updateModelTab(const QString & text);
    void updateInputFileTab(const QString & text);
    void updateResultsTab(const QString & text);
    void paintSchool(const QPointF & schoolCoordinate);
    int getModelType();
    
  private:
    // Atributos
    Ui::MainWindowClass * ui;
    ApplicationController * parentApplication;
    int gridSize;
    int margin;
    int imgSize;
    int modelType;
    
    void connectSignalsSlots();
    void initComponents();
    void paintRegion(const int & regionSize);
    void paintTowns(const QList<int> & townsNumbers,
                    const QList<QPointF> & townsCoordinates);
    void paintGraphLabels(const int & regionSize);
    void updateActions(bool flag);
  
  private slots:
    void newProblemInput();
    void solveProblem();
    
};

#endif // MAINWINDOW_H
