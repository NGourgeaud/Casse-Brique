#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // On donne une taille par défaut à la fenêtre du jeu
    this->resize(800, 600);
    this->setWindowTitle("Mon Casse-Briques");
}

MainWindow::~MainWindow()
{
    // Rien de spécial à détruire manuellement ici
}

// Implémentation de la méthode du diagramme
void MainWindow::setCentralWidget(QWidget* widget)
{
    // On appelle simplement la fonction d'origine de Qt pour changer l'affichage
    QMainWindow::setCentralWidget(widget);
}