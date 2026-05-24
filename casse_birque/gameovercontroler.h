#ifndef GAMEOVERCONTROLER_H
#define GAMEOVERCONTROLER_H

#include "gameoverview.h"
#include <QObject>

class GameOverControler : public QObject
{
    Q_OBJECT
private:
    GameOverView * itsView;
public:
    explicit GameOverControler(QObject *parent = nullptr);
    QWidget * makeView(int score);
    void deleteView();
signals:
    void menuRequested();
public slots:
    void onMenuRequested();
};

#endif // GAMEOVERCONTROLER_H
