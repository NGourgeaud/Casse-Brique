#include "ballview.h"
#include "qwindowdefs.h"

void BallView::setItsModel(BallModel *newItsModel)
{
    itsModel = newItsModel;
}

BallView::BallView()
    :itsColor(255,0,0), itsModel(nullptr)
{}

void BallView::draw(QPainter *painter)
{
    // On vérifie que la baalle existe
    if (itsModel != nullptr && painter != nullptr) {
        painter->setBrush(itsColor);
        // On dessine la balle en fonction du rectangle
        painter->drawEllipse(itsModel->getItsHitBox());
    }
}
