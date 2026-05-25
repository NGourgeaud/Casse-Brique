#include "gamemodel.h"
#include "config.h"

GameModel::GameModel() {
    ball = new BallModel(windowWidth/2 - 10, windowHeight - 70);
    raquette = new RaquetteModel(windowWidth/2 - 50, windowHeight - 50);
    bricks = new QList<BrickModel *>;
    itsHP = 3;
    itsScore = 0;
    itsCurentLevel = 1;

    loadLevel(itsCurentLevel);

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
    if (bricks->empty())
    {
        itsCurentLevel++;
        ball->startPosition();
        raquette->resetPos();
        if (itsCurentLevel <4)
            loadLevel(itsCurentLevel);
    }
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
    // Initialisation des variables selon le niveau
    int ballSpeed;
    int raquetteSpeed;
    int totalBricks;
    int doubleLifeBricks;
    int tripleLifeBricks;

    switch (level) {
    case 1: // Niveau 1 - Noyau
        ballSpeed = 5; raquetteSpeed = 10; totalBricks = 10; doubleLifeBricks = 5; tripleLifeBricks = 0;
        break;
    case 2: // Niveau 2 - Manteau
        ballSpeed = 6; raquetteSpeed = 9; totalBricks = 15; doubleLifeBricks = 6; tripleLifeBricks = 4;
        break;
    case 3: // Niveau 3 - Surface
        ballSpeed = 7; raquetteSpeed = 8; totalBricks = 20; doubleLifeBricks = 10; tripleLifeBricks = 5;
        break;
    }

    // Application des vitesses
    ball->setItsSpeedX(ballSpeed);
    ball->setItsSpeedY(ballSpeed);
    raquette->setItsSpeed(raquetteSpeed);


    // Génération des briques
    int briquesParLigne = 5; // Car windowWidth * 0.2 = 5 briques max
    int currentDoubleLife = 0;
    int currentTripleLife = 0;
    int gap = 10;

    // On calcule la largeur et hauteur des briques
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
        if (currentTripleLife < tripleLifeBricks)
        {
            hp = 3;
            currentTripleLife++;
        }
        else if (currentDoubleLife < doubleLifeBricks) {
            hp = 2;
            currentDoubleLife++;
        }

        BrickModel * brick = new BrickModel(x, y, brickWidth, brickHeight, hp);
        bricks->append(brick);
        connect(brick, &BrickModel::OnDeath, this, &GameModel::RemoveDeadBrick);
    }
}
