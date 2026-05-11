#ifndef BALLMODEL_H
#define BALLMODEL_H

class BallModel
{
private :
    float itsPosX;
    float itsPosY;
    int itsRadius;
    float itsSpeedX;
    float itsSpeedY;
    int itsDamage;
    float itsGravity;
    bool itsOnTheGround;
public:
    BallModel(float startPosX, float startPosY);
    void move();
};

#endif // BALLMODEL_H
