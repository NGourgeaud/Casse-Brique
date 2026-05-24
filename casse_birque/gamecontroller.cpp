#include "gamecontroller.h"

GameController::GameController(QObject *parent)
    : QObject(parent)
{
    // Créer le modèle et la vue
    itsGameModel = new GameModel();
    itsGameView  = new GameView(itsGameModel);

    // Relayer les événements clavier de la vue vers ce contrôleur
    connect(itsGameView, &GameView::keyPressed,  this, &GameController::onKeyPressed);
    connect(itsGameView, &GameView::keyReleased, this, &GameController::onKeyReleased);

    // Boucle de jeu à ~60 fps (16 ms)
    itsTimer = new QTimer(this);
    connect(itsTimer, &QTimer::timeout, this, &GameController::onTick);
}

GameController::~GameController()
{
    delete itsGameModel;
    delete itsGameView;
}

QWidget *GameController::createView()
{
    itsTimer->start(16);
    return itsGameView;
}

void GameController::destroyView()
{

}

// ---------------------------------------------------------------------------
// Slots
// ---------------------------------------------------------------------------

void GameController::onTick()
{
    // 1. Avancer la simulation
    itsGameModel->update();
    // 2. Demander un repaint
    itsGameView->refresh();
}

void GameController::onKeyPressed(int key)
{
    switch (key) {
    case Qt::Key_Left:
    case Qt::Key_Q:
        itsGameModel->setMovementLeft(true);
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        itsGameModel->setMovementRight(true);
        break;
    default:
        break;
    }
}

void GameController::onKeyReleased(int key)
{
    switch (key) {
    case Qt::Key_Left:
    case Qt::Key_Q:
        itsGameModel->setMovementLeft(false);
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        itsGameModel->setMovementRight(false);
        break;
    default:
        break;
    }
}
