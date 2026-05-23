#include "gamemodel.h"
#include "config.h"

void GameModel::level1()
{
    BrickModel * brick1 = new BrickModel(10,10,1);
    BrickModel * brick2 = new BrickModel(20 + (windowWidth*0.1), 10, 2);
    BrickModel * brick3 = new BrickModel(30 + (windowWidth*0.1)*2, 10, 3);
    BrickModel * brick4 = new BrickModel(40 + (windowWidth*0.1)*3, 10, 1);
    BrickModel * brick5 = new BrickModel(50 + (windowWidth*0.1)*4, 10, 1);
    bricks->append(brick1);
    bricks->append(brick2);
    bricks->append(brick3);
    bricks->append(brick4);
    bricks->append(brick5);
}

GameModel::GameModel() {
    ball = new BallModel;
    raquette = new RaquetteModel;
    bricks = new QList<BrickModel *>;
    itsHP = 3;
    itsScore = 0;

    level1();
}

const RaquetteModel *GameModel::getItsRaquette() const
{
    return raquette;
}

const BallModel *GameModel::getItsball() const
{
    return ball;
}

const QList<BrickModel *> *GameModel::getItsBricks() const
{
    return bricks;
}

int GameModel::getItsHP() const
{
    return itsHP;
}

int GameModel::getItsScore() const
{
    return itsScore;
}


