#include "brickview.h"

BrickView::BrickView() {}

void BrickView::draw(QPainter * p, BrickModel * brick)
{
    int hp = brick->getItsHP();
    QBrush brush;
    if (hp == 1){
        p->setPen(QPen(Qt::yellow,2));
        p->setBrush(QBrush(Qt::yellow));
    }
    else if (hp == 2){
        p->setPen(QPen(Qt::yellow,2));
        brush = QBrush(Qt::yellow);
        p->setBrush(brush);
        p->drawRect(brick->getItsRect());

        brush.setStyle(Qt::CrossPattern);
        brush.setColor(QColor("#ffa500"));
        p->setBrush(brush);
    }
    else if (hp == 3){
        p->setPen(QPen(QColor("#ffa500"),2));
        brush = QBrush(QColor("#ffa500"));
        p->setBrush(brush);
        p->drawRect(brick->getItsRect());

        brush.setStyle(Qt::CrossPattern);
        brush.setColor(Qt::red);
        p->setBrush(brush);
    }
    p->drawRect(brick->getItsRect());
}
