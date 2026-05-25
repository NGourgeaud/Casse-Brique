#include "mainwindow.h"
#include "config.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->resize(windowWidth,windowHeight);
    this->setWindowTitle("Earth Escape");
}

MainWindow::~MainWindow() {}

