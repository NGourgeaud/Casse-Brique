#include "gameoverview.h"
#include "qboxlayout.h"



GameOverView::GameOverView(int score, QWidget *parent)
{
    texte = new QLabel("Game Over", this);
    QString textScore = "Score : " + QString::number(score);
    scoreText = new QLabel(textScore, this);
    menu = new QPushButton("Retourner au Menu", this);

    QVBoxLayout * main = new QVBoxLayout(this);
    main->addStretch();
    main->addWidget(texte);
    main->addWidget(scoreText);
    main->addWidget(menu);
    main->addStretch();

    connect(this->menu, &QPushButton::clicked, this, &GameOverView::menuRequested);
}

