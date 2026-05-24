#ifndef BRICKMODEL_H
#define BRICKMODEL_H
#include <QObject>
#include <QRect>

class BrickModel : public QObject
{
    Q_OBJECT

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
    void takeDamage();
signals:
    void OnDeath(BrickModel* brick);
};

#endif // BRICKMODEL_H
