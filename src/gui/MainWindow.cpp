#include "MainWindow.h"

MainWindow::MainWindow(ApplicationController * parentApplication, 
                       QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowClass())
{
  this->parentApplication = parentApplication;
  this->gridSize =  24; // pixels
  this->margin   =  30; // pixels
  this->imgSize  = 380; // pixels
	ui->setupUi(this);
	connectSignalsSlots();
	initComponents();
}

MainWindow::~MainWindow()
{
  if (ui != 0)
    delete ui;
  
  ui = 0;
}

void MainWindow::connectSignalsSlots()
{
  connect(ui->newProblemInputAction, SIGNAL(triggered()), this,
          SLOT(newProblemInput()));
  
  
}

void MainWindow::initComponents()
{
//  QWidget * centralWidget = ui->centralwidget;
//  imageViewer = new ImageViewer(new QImage(), ui->centralwidget);
}

void MainWindow::newProblemInput()
{
  QString fileName = QFileDialog::getOpenFileName(this, tr("Abrir archivo"),
                                                  "data/input/",
                                                  tr("Texto (*.txt)"));
  if (!fileName.isEmpty()) {
    bool succes = parentApplication->loadNewProblem(fileName);
    if (succes){
      cout << "MainWindow::44 - ok" << endl;
//      paintRegion(parentApplication->getParametersSet()->getRegionSize());
      setUpScene(parentApplication->getParametersSet()->getRegionSize(),
                 parentApplication->getParametersSet()->getTownsNumbers(),
                 parentApplication->getParametersSet()->getTownsCoordinates());
    }
    else{
      QMessageBox::critical(this, tr("Error en el formato de archivo"),
                            tr("Ha ocurrido un error al tratar de leer"
                               "el archivo \n %1 \n\n"
                               "Por favor verifique que el formato sea "
                               "correcto").arg(fileName),
                               QMessageBox::Ok);
    }
  }
  else {
    cout << "MainWindow::56 - vacío" << endl;
  }
}

void MainWindow::setUpScene(const int & regionSize,
                            const QList<int> & townsNumbers,
                            const QList<QPointF> & townsCoordinates)
{
  paintRegion(regionSize);
  paintTowns(townsNumbers, townsCoordinates);
  paintGraphLabels(regionSize);
}

void MainWindow::paintRegion(const int & regionSize)
{
//  ui->imageLabel->resize(imgSize, imgSize);
  imgSize = 380;
  int nLines = regionSize + 1;
  int areaSize = imgSize - (margin * 2);
  gridSize = 24;
  int newGridSize = static_cast<int> (areaSize / regionSize);
  
  if (newGridSize < 20) {
    areaSize = gridSize * regionSize;
    imgSize  = areaSize + (margin * 2);
    ui->imageLabel->resize(imgSize, imgSize);
  }
  else
    gridSize = newGridSize;
  
  QImage * image = new QImage(imgSize, imgSize, QImage::Format_RGB32);
  QRgb backgroundColor = qRgb(255, 255, 255);
  image->fill(backgroundColor);
  
  QPainter * painter = new QPainter(image);
  painter->setPen(QColor(190, 190, 190));
  int x1, x2, y1, y2 = 0;
  
  painter->translate(margin, margin);
  
  for (int i = 0; i < nLines; ++i) {
    // Vertical lines
    x1 = gridSize * i;
    x2 = x1;
    y1 = 0;
    y2 = gridSize * regionSize;

    painter->drawLine(x1, y1, x2, y2);
    
    // Horizontal lines
    x1 = 0;
    x2 = gridSize * regionSize;
    y1 = gridSize * i;
    y2 = y1;

    painter->drawLine(x1, y1, x2, y2);
  }
  ui->imageLabel->setPixmap(QPixmap::fromImage(*image));
  delete painter;
  delete image;
}

void MainWindow::paintTowns(const QList<int> & townsNumbers,
                            const QList<QPointF> & townsCoordinates)
{
  QPixmap * pixmap  = new QPixmap(*(ui->imageLabel->pixmap()));
  QPainter * painter = new QPainter(pixmap);
  QPen pen(QColor(20, 20, 20));
  painter->setPen(pen);
//  painter->setBrush(Qt::darkBlue);
  
  painter->translate(margin, margin);
  
  int areaSize = imgSize - (margin * 2);
          
  double yCoordinate = 0.0;
  double xCoordinate = 0.0;
//  QPixmap town(":/icons/city_24");
//  QPixmap town(":/icons/city_32");
  QPixmap town(":/icons/school_24");
  int halfIconSize = town.width() / 2;
  pen = QPen(QColor(Qt::blue));
  painter->setPen(pen);
  painter->setFont(QFont(QString("Arial"), 9, QFont::Bold));
  painter->setLayoutDirection(Qt::LeftToRight);
  
  for (int i = 0; i < townsCoordinates.count(); ++i) {
    QPointF point = townsCoordinates.at(i);
    yCoordinate = areaSize - (point.y() * gridSize) - halfIconSize;
    xCoordinate = (point.x() * gridSize) - halfIconSize;
    QPointF currentPoint(xCoordinate, yCoordinate);
    painter->drawPixmap(currentPoint, town);
    
    xCoordinate -= 6;
    yCoordinate += 3;
    currentPoint = QPointF(xCoordinate, yCoordinate);
    painter->drawText(currentPoint, QString().setNum(townsNumbers.at(i)));
  }
  
  ui->imageLabel->setPixmap(*pixmap);
  delete painter;
}

void MainWindow::paintGraphLabels(const int & regionSize)
{
  QPixmap * pixmap  = new QPixmap(*(ui->imageLabel->pixmap()));
  QPainter * painter = new QPainter(pixmap);
  QPen pen(QColor(20, 20, 20));
  painter->setPen(pen);
  
  double xCoordinate = margin / 2;
//  double xCoordinate = 0.0;
  double yCoordinate = imgSize - (margin / 2);
//  double yCoordinate = (margin / 1.2);
  
//  painter->translate(xCoordinate, yCoordinate);
  painter->setFont(QFont(QString("Arial"), 8, QFont::Normal));
  painter->setLayoutDirection(Qt::LeftToRight);
  int nLines = regionSize + 1;
  
  painter->drawText(QPointF(xCoordinate, yCoordinate), "0");
  
  double displacement = 0.0;
  
  for (int i = 1; i < nLines; ++i) {
    if (i >= 10) 
       displacement = 3.0;
    xCoordinate = (gridSize * i) + (margin / 1.1) - displacement;
    yCoordinate = imgSize - (margin / 2);
    painter->drawText(QPointF(xCoordinate, yCoordinate), QString().setNum(i));
    xCoordinate = (margin / 2) - displacement;
    yCoordinate = imgSize - ((gridSize * i) + (margin * 0.9));
    painter->drawText(QPointF(xCoordinate, yCoordinate), QString().setNum(i));
//    painter->drawRect(QRectF(xCoordinate, yCoordinate, xCoordinate + 2, yCoordinate + 2));
  }
  
  
  ui->imageLabel->setPixmap(*pixmap);
  delete painter;
  delete pixmap;
}







