#include "menucontroler.h"

MenuControler::MenuControler(QObject *parent) : QObject(parent)
{
    // Au départ, la vue n'existe pas
    itsview = nullptr;
}

QWidget* MenuControler::createView()
{
    // On ne crée la vue que si elle n'existe pas déjà
    if (itsview == nullptr) {
        itsview = new MenuView();

        // On fait "suivre" les signaux de la vue à travers le contrôleur
        connect(itsview, &MenuView::GameRequested, this, &MenuControler::GameRequested);
        connect(itsview, &MenuView::QuitRequested, this, &MenuControler::QuitRequested);
        connect(itsview, &MenuView::ScoreRequested, this, &MenuControler::ScoreRequested);
    }

    return itsview;
}

void MenuControler::destroyView()
{
    // On libère la mémoire proprement si la vue existe
    if (itsview != nullptr) {
        delete itsview;
        itsview = nullptr;
    }
}