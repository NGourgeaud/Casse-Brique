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

    // updates score and health
    int health = itsGameModel->getItsHP();
    QString hptext = "Hp : " + QString::number(health);
    itsHP->setText(hptext);

    int score = itsGameModel->getItsScore();
    QString scoretext = "Score : " + QString::number(score);
    itsScore->setText(scoretext);


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

