#include "gameview.h"
#include "config.h"
#include <QPainter>
#include "gamemodel.h"
#include <qboxlayout>

GameView::GameView(const GameModel * GameModel)
{
    itsGameModel = GameModel;
    raquette = new RaquetteView(itsGameModel->getItsRaquette());
    balle = new BallView(itsGameModel->getItsball());
    brick = new BrickView();
    setFixedSize(windowWidth,windowHeight);

    itsScore = new QLabel("Score : 0", this);
    itsHP = new QLabel("Hp : 3", this);

    itsScore->setStyleSheet("color: white; font-size: 20px; font-weight: bold; margin: 10px;");
    itsHP->setStyleSheet("color: white; font-size: 20px; font-weight: bold; margin: 10px;");

    QHBoxLayout * hud = new QHBoxLayout;
    hud->addWidget(itsScore);
    hud->addStretch();
    hud->addWidget(itsHP);

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(hud);
    mainLayout->addStretch();

    // Permet de lire les touches
    setFocusPolicy(Qt::StrongFocus);
}


void GameView::refresh()
{
    // Mise à jour des texte
    int health = itsGameModel->getItsHP();
    itsHP->setText("Hp : " + QString::number(health));

    int score = itsGameModel->getItsScore();
    itsScore->setText("Score : " + QString::number(score));

    // Appelle de paintEvent
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

