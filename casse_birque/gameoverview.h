#ifndef GAMEOVERVIEW_H
#define GAMEOVERVIEW_H

#include "qlabel.h"
#include "qpushbutton.h"
#include <QWidget>

class GameOverView : public QWidget
{
    Q_OBJECT
private:
    QLabel * texte;
    QLabel * scoreText;
    QPushButton * menu;
public:
    explicit GameOverView(int score,QWidget *parent = nullptr);
signals:
    void menuRequested();
};

#endif // GAMEOVERVIEW_H
