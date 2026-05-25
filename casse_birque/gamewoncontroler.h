#ifndef GAMEWONCONTROLER_H
#define GAMEWONCONTROLER_H

#include "gamewonview.h"
#include <QObject>

class GameWonControler : public QObject
{
    Q_OBJECT
private:
    GameWonView * itsView;
public:
    explicit GameWonControler(QObject *parent = nullptr);
    QWidget * makeView(int score);
    void deleteView();
signals:
    void menuRequested();
public slots:
    void onMenuRequested();
};

#endif // GAMEWONCONTROLER_H
