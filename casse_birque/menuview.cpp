#include "menuview.h"

MenuView::MenuView(QWidget *parent) : QWidget(parent)
{
    // 1. Instanciation des éléments graphiques
    itsTitle = new QLabel("Earth Escape", this);
    itsTitle->setAlignment(Qt::AlignCenter); // Centre le texte

    itsPlayButton = new QPushButton("Jouer", this);
    itsScoreButton = new QPushButton("Scores", this);
    itsQuitButton = new QPushButton("Quitter", this);

    // 2. Rangement des éléments dans un Layout (mise en page verticale)
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(itsTitle);
    layout->addWidget(itsPlayButton);
    layout->addWidget(itsScoreButton);
    layout->addWidget(itsQuitButton);

    // 3. Connexion des clics de boutons aux signaux de la vue
    connect(itsPlayButton, &QPushButton::clicked, this, &MenuView::GameRequested);
    connect(itsScoreButton, &QPushButton::clicked, this, &MenuView::ScoreRequested);
    connect(itsQuitButton, &QPushButton::clicked, this, &MenuView::QuitRequested);
}