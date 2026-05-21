#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "ballmodel.h"
#include "brickmodel.h"
#include "raquettemodel.h"
#include <QObject>

class GameModel
{
private:
    RaquetteModel raquette;
    BallModel ball;
    QList<BrickModel> bricks;
public:
    GameModel();
};

#endif // GAMEMODEL_H
