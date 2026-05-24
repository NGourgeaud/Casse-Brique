#include "appcontroller.h"
#include <QApplication> // Utile si on veut fermer l'application proprement

AppControler::AppControler(QObject *parent) : QObject(parent)
{
    // 1. On crée dynamiquement la fenêtre et les sous-contrôleurs
    itsMainWindow = new MainWindow();
    itsMenuControler = new MenuControler();
    itsGameControler = new GameControler();

    // 2. CONNEXIONS : On écoute les signaux du MenuControler
    // Quand le menu dit "GameRequested", l'AppControler lance son slot "onGameRequested"
    connect(itsMenuControler, &MenuControler::GameRequested, this, &AppControler::onGameRequested);
    connect(itsMenuControler, &MenuControler::ScoreRequested, this, &AppControler::onScoreRequested);

    // Si le joueur clique sur Quitter dans le menu, on ferme l'application
    connect(itsMenuControler, &MenuControler::QuitRequested, qApp, &QApplication::quit);

    // 3. Au lancement, on charge le menu de base
    onMenuRequested();

    // 4. On affiche enfin la fenêtre à l'écran
    itsMainWindow->show();
}

AppControler::~AppControler()
{
    // On libère proprement la mémoire des objets créés avec "new"
    delete itsMainWindow;
    delete itsMenuControler;
    delete itsGameControler;
}

void AppControler::onMenuRequested()
{
    // Si le jeu était en cours, on détruit sa vue
    if (itsGameControler != nullptr) {
        // itsGameControler->destroyView();
    }

    // On demande au MenuControler de fabriquer sa vue (les boutons)
    QWidget* menuWidget = itsMenuControler->createView();

    // On injecte cette vue au centre de notre fenêtre
    itsMainWindow->setCentralWidget(menuWidget);
}

void AppControler::onGameRequested()
{
    // On détruit la vue du menu qui ne nous sert plus
    itsMenuControler->destroyView();

    // On demande au GameControler de fabriquer la vue du jeu (la zone avec la raquette)
    // QWidget* gameWidget = itsGameControler->createView();

    // On injecte la vue du jeu dans la fenêtre
    // itsMainWindow->setCentralWidget(gameWidget);
}

void AppControler::onScoreRequested()
{
    // À implémenter plus tard si tu crées un tableau des scores
}

void AppControler::onGameOver(int score)
{
    // Logique quand la partie est perdue
}