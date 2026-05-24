#ifndef BALLMODEL_H
#define BALLMODEL_H

#include <QRect>
#include "brickmodel.h"
#include "raquettemodel.h"


class BallModel : public QObject
{
    Q_OBJECT

private :
    QRect itsHitBox;
    double itsSpeedX;
    double itsSpeedY;
    bool itsOnTheGround;
    int startPosX;
    int startPosY;
public:
    BallModel(double sPosX, double sPosY);
    void startPosition();
    void move(QList<BrickModel *> allBricks, RaquetteModel *laRaquette);
    void collisionRaquette(RaquetteModel *laRaquette);
    void collisionBrick(BrickModel *brick);
    void collisionWall();

    void setItsSpeedX(double newItsSpeedX);
    void setItsSpeedY(double newItsSpeedY);
    QRect getItsHitBox() const;
signals:
    void lifeLost();
};

#endif // BALLMODEL_H
