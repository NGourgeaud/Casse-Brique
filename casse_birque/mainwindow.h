#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    // Constructeur et destructeur classiques
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Méthode demandée par ton diagramme pour changer l'écran affiché
    void setCentralWidget(QWidget* widget);

signals:
    // Signaux demandés par ton diagramme (qui seront écoutés par l'AppControler)
    void newGameRequested();
    void menuRequested();
    void scoresRequested();
    void gameOverRequested();
    void quitRequested();
};

#endif // MAINWINDOW_H