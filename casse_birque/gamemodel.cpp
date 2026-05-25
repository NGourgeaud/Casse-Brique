#include "gamemodel.h"
#include "config.h"

GameModel::GameModel() {
    ball = new BallModel(windowWidth/2 - 10, windowHeight - 70);
    raquette = new RaquetteModel(windowWidth/2 - 50, windowHeight - 50);
    bricks = new QList<BrickModel *>;
    itsHP = 3;
    itsScore = 0;

    loadLevel(1);

    connect(ball, &BallModel::lifeLost, this, &GameModel::onLifeLost);
}

void GameModel::update(){
    ball->move(*bricks,raquette);
    raquette->move();
}

const RaquetteModel *GameModel::getItsRaquette() const
{
    return raquette;
}

const BallModel *GameModel::getItsball() const
{
    return ball;
}

const QList<BrickModel *> *GameModel::getItsBricks() const
{
    return bricks;
}

int GameModel::getItsHP() const
{
    return itsHP;
}

int GameModel::getItsScore() const
{
    return itsScore;
}

void GameModel::setMovementLeft(bool sw)
{
    raquette->setItsMoveLeft(sw);
}

void GameModel::setMovementRight(bool sw)
{
    raquette->setItsMoveRight(sw);
}

void GameModel::RemoveDeadBrick(BrickModel * brick)
{
    disconnect(brick);
    bricks->remove(bricks->indexOf(brick));
    delete brick;
    itsScore+=10;

}

void GameModel::onLifeLost()
{
    itsHP-=1;
    raquette->resetPos();
    if (itsHP == 0)
        GameOver(itsScore);
}

void GameModel::loadLevel(int level)
{
    // 1. Initialisation des variables selon le niveau
    int ballSpeed = 5;
    int raquetteSpeed = 10;
    int totalBricks = 10;
    int doubleLifeBricks = 5;

    switch (level) {
    case 1: // Niveau 1 - Noyau
        ballSpeed = 5; raquetteSpeed = 10; totalBricks = 10; doubleLifeBricks = 5;
        break;
    case 2: // Niveau 2 - Manteau
        ballSpeed = 6; raquetteSpeed = 9; totalBricks = 15; doubleLifeBricks = 10;
        break;
    case 3: // Niveau 3 - Surface
        ballSpeed = 7; raquetteSpeed = 8; totalBricks = 20; doubleLifeBricks = 15;
        break;
    }

    // 2. Application des vitesses
    ball->setItsSpeedX(ballSpeed);
    ball->setItsSpeedY(ballSpeed);
    raquette->setItsSpeed(raquetteSpeed);

    // 3. Nettoyage de l'ancien niveau
    for(BrickModel* b : *bricks) {
        disconnect(b, &BrickModel::OnDeath, this, &GameModel::RemoveDeadBrick);
        delete b;
    }
    bricks->clear();

    // 4. Génération des briques
    int briquesParLigne = 5; // Car windowWidth * 0.2 = 5 briques max
    int currentDoubleLife = 0;
    int gap = 10;

    // On calcule la largeur et hauteur théoriques
    float cellWidth = windowWidth * 0.2;
    float cellHeight = windowHeight * 0.1;

    int brickWidth = cellWidth - gap;
    int brickHeight = cellHeight - gap;

    for (int i = 0; i < totalBricks; i++) {
        // Calcul de la ligne et de la colonne pour placer la brique
        int row = i / briquesParLigne;
        int col = i % briquesParLigne;

        // Calcule des positions
        int x = (col * cellWidth) + (gap / 2);
        int y = 50 + (row * cellHeight) + (gap / 2);

        // Détermine si la brique a 1 ou 2 HP
        int hp = 1;
        if (currentDoubleLife < doubleLifeBricks) {
            hp = 2;
            currentDoubleLife++;
        }

        BrickModel * brick = new BrickModel(x, y, brickWidth, brickHeight, hp);
        bricks->append(brick);
        connect(brick, &BrickModel::OnDeath, this, &GameModel::RemoveDeadBrick);
    }
}
