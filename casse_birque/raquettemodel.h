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
public:
    RaquetteModel(int posX, int posY, int largeur, int hateur, float speed);
    int getItsPosX() const;
    int getItsPosY() const;
    int getItsHauteur() const;
    int getItsLargeur() const;
    int getItsSpeed() const;

    void setPosX(int newX);
    void moveRight();
    void moveLeft();
    void move();
    void setItsMoveRight(bool newItsMoveRight);
    void setItsMoveLeft(bool newItsMoveLeft);
};

#endif // RAQUETTEMODEL_H
