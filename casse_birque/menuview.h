#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout> // Pour aligner les boutons verticalement

class MenuView : public QWidget
{
    Q_OBJECT

private:
    QLabel* itsTitle;
    QPushButton* itsPlayButton;
    QPushButton* itsScoreButton;
    QPushButton* itsQuitButton;

public:
    explicit MenuView(QWidget *parent = nullptr);

signals:
    void GameRequested();
    void QuitRequested();
    void ScoreRequested();
};

#endif // MENUVIEW_H