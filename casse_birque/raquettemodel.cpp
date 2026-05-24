#include "raquettemodel.h"
#include "config.h"


RaquetteModel::RaquetteModel(int posX, int posY){
    itsPosX = posX;
    itsPosY = posY;

    startPosX = posX;

    itsLargeur = windowWidth*0.1;
    itsHauteur = 10;

    itsMoveRight = false;
    itsMoveLeft = false;

    itsSpeed = 3;
}

// Getters

int RaquetteModel::getItsHauteur() const {
    return itsHauteur;
}

int RaquetteModel::getItsLargeur() const{
    return itsLargeur;
}

int RaquetteModel::getItsPosX() const {
    return itsPosX;
}

int RaquetteModel::getItsPosY() const{
    return itsPosY;
}

int RaquetteModel::getItsSpeed() const{
    return itsSpeed;
}
// Setter


void RaquetteModel::resetPos() {
    itsPosX = startPosX;
}

void RaquetteModel::setItsMoveRight(bool newItsMoveRight)
{
    itsMoveRight = newItsMoveRight;
}

void RaquetteModel::setItsMoveLeft(bool newItsMoveLeft)
{
    itsMoveLeft = newItsMoveLeft;
}

// Methode

void RaquetteModel::move(){

    // Déplacement droite/gauche
    if (itsMoveRight) {
        itsPosX += itsSpeed;
    }
    if (itsMoveLeft) {
        itsPosX -= itsSpeed;
    }

    // Collision avec le bord gauche
    if (itsPosX < 0) {
        itsPosX = 0;
    }
    // Collision avec le bord droit
    else if(itsPosX + itsLargeur > windowWidth) {
        itsPosX = windowWidth - itsLargeur;
    }
}
