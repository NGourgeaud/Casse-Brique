#include "ballmodel.h"
#include "config.h"


void BallModel::setItsSpeedX(double newItsSpeedX)
{
    itsSpeedX = newItsSpeedX;
}

void BallModel::setItsSpeedY(double newItsSpeedY)
{
    itsSpeedY = newItsSpeedY;
}

QRect BallModel::getItsHitBox() const
{
    return itsHitBox;
}

BallModel::BallModel(double startPosX, double startPosY)
    : itsHitBox(startPosX, startPosY, 20, 20)
{
    itsSpeedX = 0;
    itsSpeedY = 0;
    itsOnTheGround = false;
}

void BallModel::move(QList<BrickModel*> allBricks, RaquetteModel * Raquette){
    // Faire en sorte que si la balle ne touche rien on ajoute au coordonnée

    // Déplacement de la bale
    itsHitBox.translate(itsSpeedX, itsSpeedY);

    // Vérification de la collision
    collisionRaquette(Raquette);
    for (BrickModel * brick : allBricks)
        collisionBrick(brick);
    collisionWall();

    // Empêche la balle de rebondir à l'infinie sur un axe
    if(itsSpeedX == 0){
        itsSpeedX = 1;
    }
    else if(itsSpeedY == 0) {
        itsSpeedY = 1;
    }
}

void BallModel::collisionRaquette(RaquetteModel * laRaquette){

    // On dessine la raquette virtuellement avec un QRect
    QRect Raquette(laRaquette->getItsPosX(),laRaquette->getItsPosY(),laRaquette->getItsLargeur(),laRaquette->getItsHauteur());

    // Contient la zone où les deux rectangles se touchent
    QRect inter = itsHitBox.intersected(Raquette);

    // Pas de collision
    if (inter.isEmpty())
        return ;

    // Si il y a une collision = rebond
    // CAS 1 : Colision en haut ou en bas de la raquette
    if (inter.width() > inter.height()) {
        if(itsHitBox.center().y() < Raquette.center().y()){
            itsHitBox.moveBottom(Raquette.top());
        }
        else{
            itsHitBox.moveTop(Raquette.bottom());
        }
        itsSpeedY = -itsSpeedY;
    }
    // CAS 2 : Colision sur les côtés de la raquette (gauche ou droit)
    else if (inter.height() > inter.width()) {
        if(itsHitBox.center().x() < Raquette.center().x()){
            itsHitBox.moveRight(Raquette.left());
        }
        else{
            itsHitBox.moveLeft(Raquette.right());
        }

        itsSpeedX = -itsSpeedX;
    }
    // CAS 3 : Colision pile sur un coin (largeur == hauteur)
    else {
        if(itsHitBox.center().y() < Raquette.center().y()){
            itsHitBox.moveBottom(Raquette.top());
        }
        else{
            itsHitBox.moveTop(Raquette.bottom());
        }

        if(itsHitBox.center().x() < Raquette.center().x()){
            itsHitBox.moveRight(Raquette.left());
        }
        else{
            itsHitBox.moveLeft(Raquette.right());
        }

        itsSpeedX = -itsSpeedX;
        itsSpeedY = -itsSpeedY;
    }
}

void BallModel::collisionBrick(BrickModel * brick){

    QRect brickRect = brick->getItsRect();

    // Contient la zone où les deux rectangles se touchent
    QRect inter = itsHitBox.intersected(brickRect);

    // Pas de collision
    if (inter.isEmpty())
        return;

    // Applique les dégâts à la brique
    brick->takeDamage();

    // Si il y a une collision = rebond
    // CAS 1 : Colision en haut ou en bas de la brique
    if (inter.width() > inter.height()) {
        if(itsHitBox.center().y() < brickRect.center().y()) {
            itsHitBox.moveBottom(brickRect.top());
        } else {
            itsHitBox.moveTop(brickRect.bottom());
        }
        itsSpeedY = -itsSpeedY;
    }
    // CAS 2 : Colision sur les côtés de la brique (gauche ou droit)
    else if (inter.height() > inter.width()) {
        if(itsHitBox.center().x() < brickRect.center().x()) {
            itsHitBox.moveRight(brickRect.left());
        } else {
            itsHitBox.moveLeft(brickRect.right());
        }
        itsSpeedX = -itsSpeedX;
    }
    // CAS 3 : Colision pile sur un coin (largeur == hauteur)
    else {
        if(itsHitBox.center().y() < brickRect.center().y()) {
            itsHitBox.moveBottom(brickRect.top());
        } else {
            itsHitBox.moveTop(brickRect.bottom());
        }

        if(itsHitBox.center().x() < brickRect.center().x()) {
            itsHitBox.moveRight(brickRect.left());
        } else {
            itsHitBox.moveLeft(brickRect.right());
        }

        itsSpeedX = -itsSpeedX;
        itsSpeedY = -itsSpeedY;
    }
}

void BallModel::collisionWall(){

    // Si le bord gauche du rectangle dépasse ou touche 0
    if (itsHitBox.left() <= 0) {
        itsHitBox.moveLeft(0);
        itsSpeedX = -itsSpeedX;
    }
    // Si le bord droit du rectangle dépasse la largeur de l'écran
    else if (itsHitBox.right() >= windowWidth) {
        itsHitBox.moveRight(windowWidth);
        itsSpeedX = -itsSpeedX;
    }

    // Si le bord haut dépasse ou touche 0
    if (itsHitBox.top() <= 0) {
        itsHitBox.moveTop(0);
        itsSpeedY = -itsSpeedY;
    }
    // Si le bord bas (sol) dépasse la hauteur de l'écran
    else if (itsHitBox.bottom() >= windowHeight) {
       itsOnTheGround = true;
    }
}
