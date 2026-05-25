#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "ballmodel.h"
#include "brickmodel.h"
#include "raquettemodel.h"
#include <QObject>

class GameModel : public QObject
{
    Q_OBJECT

private:
    RaquetteModel * raquette;
    BallModel * ball;
    QList<BrickModel*> * bricks;
    int itsHP;
    int itsScore;

public:
    GameModel();
    void update();
    const RaquetteModel* getItsRaquette() const;
    const BallModel* getItsball() const;
    const QList<BrickModel*>* getItsBricks() const;
    int getItsHP() const;
    int getItsScore() const;
    void loadLevel(int level);

signals:
    void GameOver(int score);

public slots:
    void setMovementLeft(bool sw);
    void setMovementRight(bool sw);
    void RemoveDeadBrick(BrickModel * brick);
    void onLifeLost();
};

#endif // GAMEMODEL_H
