#ifndef BALLMODEL_H
#define BALLMODEL_H

#include <QRect>
#include <list>
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
    void move(const std::list<BrickModel*>& allBricks, const RaquetteModel &laRaquette);    void collisionRaquette(const RaquetteModel& laRaquette);
    void collisionBrick(const QRect &brick);
    void collisionWall();

    void setItsSpeedX(double newItsSpeedX);
    void setItsSpeedY(double newItsSpeedY);
    QRect getItsHitBox() const;
};

#endif // BALLMODEL_H
