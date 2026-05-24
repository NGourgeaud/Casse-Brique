#ifndef APPCONTROLER_H
#define APPCONTROLER_H

#include <QObject>
#include "mainwindow.h"
#include "menucontroler.h"
#include "gamecontroller.h"

class AppControler : public QObject
{
    Q_OBJECT

private:
    // Attributs : l'AppControler possède la fenêtre et les sous-contrôleurs
    MainWindow* itsMainWindow;
    MenuControler* itsMenuControler;
    GameController* itsGameControler;

public:
    explicit AppControler(QObject *parent = nullptr);
    ~AppControler();

public slots:
    // Les slots de ton diagramme pour réagir aux changements d'état
    void onMenuRequested();
    void onGameRequested();
    void onScoreRequested();
    void onGameOver(int score);
};

#endif // APPCONTROLER_H
