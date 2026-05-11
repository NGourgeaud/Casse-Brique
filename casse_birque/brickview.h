#ifndef BRICKVIEW_H
#define BRICKVIEW_H

#include "brickmodel.h"
#include <QPainter>

class BrickView
{
public:
    BrickView();
    void draw(QPainter p, BrickModel brick);
};

#endif // BRICKVIEW_H
