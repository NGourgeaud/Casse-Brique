#include "raquettemodel.h"

RaquetteModel::RaquetteModel(int posX, int posY, int largeur, int hauteur, int speed){
    itsPosX = posX;
    itsPosY = posY;

    itsLargeur = largeur;
    itsHauteur = hauteur;

    itsSpeed = speed;
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

// Methode

void RaquetteModel::moveLeft(){
    itsPosX -= itsSpeed;
}

void RaquetteModel::moveRight(){
    itsPosX += itsSpeed;
}