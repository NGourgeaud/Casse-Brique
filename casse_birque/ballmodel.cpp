#include "ballmodel.h"

BallModel::BallModel(float startPosX, float startPosY) {
    itsPosX = startPosX;
    itsPosY = startPosY;
    itsRadius = 10;
    itsSpeedX = 5;
    itsSpeedY = 5;
    itsDamage = 1;
    itsOnTheGround = false;
}

void BallModel::move(){
    // Faire en sorte que si la balle ne touche rien on ajoute au coordonnée

    //Si la balle touche/en collision elle va dans sans oppose ou symetrique
    //Regarder dans le mario MVC
}
