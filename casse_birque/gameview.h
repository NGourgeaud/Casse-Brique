#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "ballview.h"
#include "brickview.h"
#include "gamemodel.h"
#include "qlabel.h"
#include "raquetteview.h"
#include <QWidget>
#include <QKeyEvent>


class GameView : public QWidget
{
    Q_OBJECT

private:
    RaquetteView * raquette;
    BallView * balle;
    BrickView* brick;
    const GameModel * itsGameModel;
    QLabel * itsScore;
    QLabel * itsHP;


    void drawBackGround(QPainter *p);

protected:
    void paintEvent(QPaintEvent* event)  override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

public:
    void refresh();
    GameView(const GameModel * GameModel);

signals:
    void keyPressed(int key);
    void keyReleased(int key);
};

#endif // GAMEVIEW_H
