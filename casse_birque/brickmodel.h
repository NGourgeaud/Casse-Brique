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
    int itsWidth;
    int itsHeight;
    QRect itsRect;
    int itsHP;
public:
    BrickModel(int x, int y, int width, int height, int hp = 1);
    int getItsX();
    int getItsY();
    int getItsHP();
    QRect getItsRect();
    void takeDamage();
    int getItsWidth() const;

    int getItsHeight() const;

signals:
    void OnDeath(BrickModel * model);
};

#endif // BRICKMODEL_H
