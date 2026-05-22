#ifndef MENUCONTROLER_H
#define MENUCONTROLER_H

#include <QObject>
#include "menuview.h"

class MenuControler : public QObject
{
    Q_OBJECT

private:
    MenuView* itsview;

public:
    explicit MenuControler(QObject *parent = nullptr);
    QWidget* createView(); // On retourne un QWidget* comme attendu par Qt
    void destroyView();

signals:
    void GameRequested();
    void QuitRequested();
    void ScoreRequested();
};

#endif // MENUCONTROLER_H