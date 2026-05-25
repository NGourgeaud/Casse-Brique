#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void newGameRequested();
    void menuRequested();
    void scoresRequested();
    void gameOverRequested();
    void quitRequested();
};

#endif // MAINWINDOW_H
