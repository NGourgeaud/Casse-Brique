#ifndef GAMEWONVIEW_H
#define GAMEWONVIEW_H

#include "qlabel.h"
#include "qpushbutton.h"
#include <QWidget>

class GameWonView : public QWidget
{
    Q_OBJECT
private:
    QLabel * texte;
    QLabel * scoreText;
    QPushButton * menu;
public:
    explicit GameWonView(int score,QWidget *parent = nullptr);
signals:
    void menuRequested();
};

#endif // GAMEWONVIEW_H
