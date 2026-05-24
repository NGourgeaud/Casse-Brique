#include "raquetteview.h"

// Initialisation de la vue avec le modèle et une couleur par défaut
RaquetteView::RaquetteView(const RaquetteModel* m) {
    itsModel = m;
    itsColor = QColor(Qt::darkGray); // Tu peux choisir la couleur que tu souhaites
}

// Implémentation de la méthode draw
void RaquetteView::draw(QPainter *painter) {
    // Sécurité : on vérifie que le pointeur n'est pas nul avant de dessiner
    if (itsModel != nullptr && painter != nullptr) {

        // On configure la couleur de remplissage
        painter->setBrush(itsColor);
        painter->setPen(Qt::black); // Contour noir de la raquette

        // On dessine le rectangle en récupérant les données du modèle
        painter->drawRect(itsModel->getItsPosX(),itsModel->getItsPosY(),itsModel->getItsLargeur(),itsModel->getItsHauteur());
    }
}
