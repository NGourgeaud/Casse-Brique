#include "gamemodel.h"

GameModel::GameModel() {
    ball = new BallModel;
    raquette = new RaquetteModel;
    bricks = new QList<BrickModel *>;
    itsHP = 3;
    itsScore = 0;
}

const RaquetteModel *GameModel::getItsRaquette()
{
    return raquette;
}

const BallModel *GameModel::getItsball()
{
    return ball;
}

const QList<BrickModel *> *GameModel::getItsBricks()
{
    return bricks;
}

int GameModel::getItsHP()
{
    return itsHP;
}

int GameModel::getItsScore()
{
    return itsScore;
}


