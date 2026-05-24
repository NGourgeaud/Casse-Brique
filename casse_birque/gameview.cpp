#include "gameview.h"
#include "config.h"
#include <QPainter>
#include "gamemodel.h"

GameView::GameView(const GameModel * GameModel)
{
    itsGameModel = GameModel;
    raquette = new RaquetteView(itsGameModel->getItsRaquette());
    balle = new BallView(itsGameModel->getItsball());
    brick = new BrickView();
    setFixedSize(windowWidth,windowHeight);

    // Permet de lire les touches
    setFocusPolicy(Qt::StrongFocus);
}


void GameView::refresh()
{
    update();
}



void GameView::drawBackGround(QPainter * p)
{
    p->setPen(Qt::black);
    p->setBrush(Qt::black);
    p->drawRect(0, 0, windowWidth, windowHeight);
}

void GameView::paintEvent(QPaintEvent*)
{
    QPainter p(this);

    drawBackGround(&p);

    raquette->draw(&p);
    balle->draw(&p);

    QList<BrickModel *> brickList = *itsGameModel->getItsBricks();
    for (BrickModel* b : brickList) {
        brick->draw(&p, b);
    }
}

void GameView::keyPressEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat()) {
        emit keyPressed(event->key());
    }
}

void GameView::keyReleaseEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat()) {
        emit keyReleased(event->key());
    }
}

