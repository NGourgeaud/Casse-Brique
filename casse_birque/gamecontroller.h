#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "gamemodel.h"
#include "gameview.h"

#include <QObject>
#include <QTimer>

class GameController : public QObject
{
    Q_OBJECT

private:
    QTimer * itsTimer;
    GameModel * itsGameModel;
    GameView * itsGameView;

public:
    GameController(QObject * parent);
    ~GameController();
    QWidget * createView();
    void destroyView();

signals:
    void GameOver(int score);
    void GameWon(int score);

private slots:
    void onTick();
    void onKeyPressed(int key);
    void onKeyReleased(int key);
};

#endif // GAMECONTROLLER_H
