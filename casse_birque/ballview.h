#ifndef BALLVIEW_H
#define BALLVIEW_H

#include "ballmodel.h"
#include "qcolor.h"
#include <QPainter>

class BallView
{
private:
    QColor itsColor;
    const BallModel * itsModel;
public:
    BallView(const BallModel *m);
    void draw(QPainter * painter);
};

#endif // BALLVIEW_H
