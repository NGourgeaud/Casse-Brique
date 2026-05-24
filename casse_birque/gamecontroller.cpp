#include "gamecontroller.h"

GameController::GameController(QObject *parent)
    : QObject(parent)
{
    itsTimer = new QTimer(this);
}

GameController::~GameController()
{
    itsTimer->stop();

    disconnect(itsGameModel);
    disconnect(itsGameView);

    itsGameModel->deleteLater();
    itsGameView->deleteLater();
    itsGameModel = nullptr;
    itsGameView = nullptr;
}

QWidget *GameController::createView()
{
    itsGameModel = new GameModel();
    itsGameView  = new GameView(itsGameModel);

    connect(itsTimer, &QTimer::timeout, this, &GameController::onTick);


    connect(itsGameView, &GameView::keyPressed,  this, &GameController::onKeyPressed);
    connect(itsGameView, &GameView::keyReleased, this, &GameController::onKeyReleased);

    connect(itsGameModel, &GameModel::GameOver, this, &GameController::GameOver);

    itsTimer->start(16);
    return itsGameView;
}

void GameController::destroyView()
{
    itsTimer->stop();

    disconnect(itsGameModel);
    disconnect(itsGameView);

    itsGameModel->deleteLater();
    itsGameView->deleteLater();
    itsGameModel = nullptr;
    itsGameView = nullptr;
}

// ---------------------------------------------------------------------------
// Slots
// ---------------------------------------------------------------------------

void GameController::onTick()
{
    // 1. Avancer la simulation
    itsGameModel->update();
    // 2. Demander un repaint
    if (itsGameView)
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
