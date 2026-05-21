#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "ballmodel.h"
#include "brickmodel.h"
#include "raquettemodel.h"
#include <QObject>

class GameModel : public QObject
{
    Q_OBJECT

private:
    RaquetteModel * raquette;
    BallModel * ball;
    QList<BrickModel*> * bricks;
    int itsHP;
    int itsScore;
public:
    GameModel();
    const RaquetteModel* getItsRaquette();
    const BallModel* getItsball();
    const QList<BrickModel*>* getItsBricks();
    int getItsHP();
    int getItsScore();
signals:
    void GameOver(int score);
};

#endif // GAMEMODEL_H
