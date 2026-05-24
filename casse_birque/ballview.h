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
    BallView(const BallModel * model);
    void draw(QPainter * painter);
    void setItsModel();
};

#endif // BALLVIEW_H
