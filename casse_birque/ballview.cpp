#include "ballview.h"
#include "qwindowdefs.h"


BallView::BallView(const BallModel * m)
    :itsColor(255,0,0), itsModel(m)
{}

void BallView::draw(QPainter * painter)
{
    // On vérifie que la baalle existe
    if (itsModel != nullptr && painter != nullptr) {
        painter->setBrush(itsColor);
        // On dessine la balle en fonction du rectangle
        painter->drawEllipse(itsModel->getItsHitBox());
    }
}
