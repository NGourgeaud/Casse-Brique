#include "gameovercontroler.h"

GameOverControler::GameOverControler(QObject *parent)
    : QObject{parent}
{}

QWidget *GameOverControler::makeView(int score)
{
    itsView = new GameOverView(score);
    connect(this->itsView, &GameOverView::menuRequested, this, &GameOverControler::onMenuRequested);
    return itsView;
}

void GameOverControler::deleteView()
{
    disconnect(itsView);
    delete itsView;
}

void GameOverControler::onMenuRequested()
{
    deleteView();
    menuRequested();
}
