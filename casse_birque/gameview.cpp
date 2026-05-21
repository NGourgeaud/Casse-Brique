#include "gameview.h"
#include <QPainter>


GameView::GameView(const GameModel * GameModel)
{
    itsGameModel = GameModel;
    raquette = new RaquetteView();
    balle = new BallView();
    brick = new BrickView();
}


void GameView::refresh()
{
    update();
}



void GameView::paintEvent(QPaintEvent*)
{
    QPainter p(this);
}

