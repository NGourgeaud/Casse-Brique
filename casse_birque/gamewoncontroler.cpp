#include "gamewoncontroler.h"

GameWonControler::GameWonControler(QObject *parent)
    : QObject{parent}
{}

QWidget *GameWonControler::makeView(int score)
{
    itsView = new GameWonView(score);
    connect(this->itsView, &GameWonView::menuRequested, this, &GameWonControler::onMenuRequested);
    return itsView;
}

void GameWonControler::deleteView()
{
    disconnect(itsView);
    delete itsView;
}

void GameWonControler::onMenuRequested()
{
    deleteView();
    menuRequested();
}
