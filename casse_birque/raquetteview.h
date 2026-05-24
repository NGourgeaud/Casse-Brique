#ifndef RAQUETTEVIEW_H
#define RAQUETTEVIEW_H

#include <QColor>
#include <QPainter>
#include "raquettemodel.h" // Inclusion nécessaire pour connaître le modèle

class RaquetteView
{
private:
    QColor itsColor;
    const RaquetteModel* itsModel; // Pointeur vers le modèle (lien indiqué par les pointillés/paramètres du diagramme)

public:
    // Constructeur conforme au diagramme : RaquetteView(m : RaquetteModel*)
    RaquetteView(const RaquetteModel* m);

    // Méthode de dessin avec QPainter (standard sous Qt)
    void draw(QPainter *painter);
};

#endif // RAQUETTEVIEW_H
