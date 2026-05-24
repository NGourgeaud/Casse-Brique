#include "mainwindow.h"
#include "config.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->resize(windowWidth,windowHeight);
    this->setWindowTitle("Casse-Briques");
}

MainWindow::~MainWindow() {}

// Implémentation de la méthode du diagramme
void MainWindow::setCentralWidget(QWidget* widget)
{
    // On appelle simplement la fonction d'origine de Qt pour changer l'affichage
    QMainWindow::setCentralWidget(widget);
}
