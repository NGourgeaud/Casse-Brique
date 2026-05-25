#include "brickmodel.h"
#include "config.h"

int BrickModel::getItsWidth() const
{
    return itsWidth;
}

int BrickModel::getItsHeight() const
{
    return itsHeight;
}

BrickModel::BrickModel(int x, int y, int w, int h, int hp) {
    itsHP = hp;
    itsX = x;
    itsY = y;
    itsRect = QRect(x, y, w, h);
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

void BrickModel::takeDamage()
{
    itsHP-=1;
    if (itsHP == 0)
        OnDeath(this);
}
