#include "brickmodel.h"
#include "config.h"

BrickModel::BrickModel(int hp, int x, int y) {
    itsHP = hp;
    itsX = x;
    itsY = y;
    itsRect = QRect(x, y, windowWidth*0.1, windowHeight*0.1);
}

int BrickModel::getItsX()
{
    return itsX;
}

int BrickModel::getItsY()
{
    return itsY;
}

QRect BrickModel::getItsRect()
{
    return itsRect;
}
