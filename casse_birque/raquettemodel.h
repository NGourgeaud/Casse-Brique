#ifndef RAQUETTEMODEL_H
#define RAQUETTEMODEL_H

class RaquetteModel
{
private:
    int itsPosX;
    int itsPosY;
    int itsHauteur;
    int itsLargeur;
    float itsSpeed;
    bool itsMoveRight;
    bool itsMoveLeft;

    int startPosX;
public:
    RaquetteModel(int posX, int posY);
    int getItsPosX() const;
    int getItsPosY() const;
    int getItsHauteur() const;
    int getItsLargeur() const;
    int getItsSpeed() const;

    void resetPos();
    void moveRight();
    void moveLeft();
    void move();
    void setItsMoveRight(bool newItsMoveRight);
    void setItsMoveLeft(bool newItsMoveLeft);
};

#endif // RAQUETTEMODEL_H
