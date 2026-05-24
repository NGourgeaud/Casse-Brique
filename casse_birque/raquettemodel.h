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

public:
    RaquetteModel(int posX, int posY);
    int getItsPosX() const;
    int getItsPosY() const;
    int getItsHauteur() const;
    int getItsLargeur() const;
    int getItsSpeed() const;

    void setPosX(int newX);
    void moveRight();
    void moveLeft();
};

#endif // RAQUETTEMODEL_H
