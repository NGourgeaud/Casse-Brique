#ifndef BRICKMODEL_H
#define BRICKMODEL_H
#include <QRect>

class BrickModel
{
private :
    int itsX;
    int itsY;
    QRect itsRect;
    int itsHP;
public:
    BrickModel(int x, int y, int hp);
    int getItsX();
    int getItsY();
    int getItsHP();
    QRect getItsRect();
public slots:
    void onHit();
signals:
    void OnDeath();
};

#endif // BRICKMODEL_H
