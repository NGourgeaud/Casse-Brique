#ifndef BALLVIEW_H
#define BALLVIEW_H

#include "ballmodel.h"
#include "qcolor.h"
#include <QPainter>

class BallView
{
private:
    QColor itsColor;
    BallModel * itsModel;
public:
    BallView();
    void draw(QPainter * painter);
    void setItsModel(BallModel *newItsModel);
};

#endif // BALLVIEW_H
