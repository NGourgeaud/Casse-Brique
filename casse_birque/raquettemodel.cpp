#include "raquettemodel.h"
#include "config.h"

RaquetteModel::RaquetteModel(int posX, int posY, int largeur, int hauteur, float speed){
    itsPosX = posX;
    itsPosY = posY;

    itsLargeur = largeur;
    itsHauteur = hauteur;

    itsSpeed = speed;

    itsMoveRight = false;
    itsMoveLeft = false;
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


void RaquetteModel::setPosX(int newX) {
    itsPosX = newX;
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
