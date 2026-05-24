#include "brickmodel.h"
#include "config.h"

BrickModel::BrickModel(int x, int y, int hp) {
    itsHP = hp;
    itsX = x;
    itsY = y;
    itsRect = QRect(x, y, windowWidth*0.2, windowHeight*0.1);
}

int BrickModel::getItsX()
{
    return itsX;
}

int BrickModel::getItsY()
{
    return itsY;
}

int BrickModel::getItsHP()
{
    return itsHP;
}

QRect BrickModel::getItsRect()
{
    return itsRect;
}

void BrickModel::onHit()
{
    itsHP-=1;
    if (itsHP == 0)
        OnDeath(this);
}
