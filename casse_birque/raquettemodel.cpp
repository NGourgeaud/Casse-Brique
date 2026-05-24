#include "raquettemodel.h"
#include "config.h"

RaquetteModel::RaquetteModel(int posX, int posY){
    itsPosX = posX;
    itsPosY = posY;

    itsLargeur = windowWidth*0.1;
    itsHauteur = 10;

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


void RaquetteModel::setPosX(int newX) {
    itsPosX = newX;
}

// Methode

void RaquetteModel::moveLeft(){
    itsPosX -= itsSpeed;
}

void RaquetteModel::moveRight(){
    itsPosX += itsSpeed;
}
