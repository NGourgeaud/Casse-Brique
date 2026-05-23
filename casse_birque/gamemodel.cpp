#include "gamemodel.h"
#include "config.h"

void GameModel::Testlevel()
{
    BrickModel * brick1 = new BrickModel(30,10,1);
    BrickModel * brick2 = new BrickModel(50 + (windowWidth*0.2), 10, 2);
    BrickModel * brick3 = new BrickModel(70 + (windowWidth*0.2)*2, 10, 3);
    BrickModel * brick4 = new BrickModel(90 + (windowWidth*0.2)*3, 10, 1);
    BrickModel * brick5 = new BrickModel(30, 30 + (windowHeight*0.1), 1);
    bricks->append(brick1);
    bricks->append(brick2);
    bricks->append(brick3);
    bricks->append(brick4);
    bricks->append(brick5);

    for (BrickModel* b : *bricks) {
        connect(b, &BrickModel::OnDeath, this, &GameModel::RemoveDeadBrick);
    }
}

GameModel::GameModel() {
    ball = new BallModel;
    raquette = new RaquetteModel;
    bricks = new QList<BrickModel *>;
    itsHP = 3;
    itsScore = 0;

    Testlevel();
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

void GameModel::setMovementLeft(bool sw)
{

}

void GameModel::setMovementRight(bool sw)
{

}

void GameModel::RemoveDeadBrick(BrickModel brick)
{
    disconnect(&brick);
    bricks->remove(bricks->indexOf(&brick));
}


