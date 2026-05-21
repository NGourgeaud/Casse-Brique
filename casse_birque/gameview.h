#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "ballview.h"
#include "brickview.h"
#include "gamemodel.h"
#include "raquetteview.h"
#include <QWidget>


class GameView : QWidget
{
    Q_OBJECT

private:
    RaquetteView * raquette;
    BallView * balle;
    BrickView* brick;
    const GameModel * itsGameModel;
protected:
    void paintEvent(QPaintEvent* event)  override;
public:
    void refresh();
    GameView(const GameModel * GameModel);
signals:
    void keyPressed(int key);
    void keyReleased(int key);
};

#endif // GAMEVIEW_H
