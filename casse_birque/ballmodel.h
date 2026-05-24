#ifndef BALLMODEL_H
#define BALLMODEL_H

#include <QRect>
#include "brickmodel.h"
#include "raquettemodel.h"


class BallModel
{
private :
    QRect itsHitBox;
    double itsSpeedX;
    double itsSpeedY;
    bool itsOnTheGround;
public:
    BallModel(double startPosX, double startPosY);
    void move(QList<BrickModel *> allBricks, RaquetteModel *laRaquette);
    void collisionRaquette(RaquetteModel *laRaquette);
    void collisionBrick(BrickModel *brick);
    void collisionWall();

    void setItsSpeedX(double newItsSpeedX);
    void setItsSpeedY(double newItsSpeedY);
    QRect getItsHitBox() const;
};

#endif // BALLMODEL_H
