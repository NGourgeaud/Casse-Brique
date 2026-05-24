#include "gamemodel.h"
#include "gameview.h"
#include "mainwindow.h"


#include <QApplication>
#include "appcontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // On crée le contrôleur principal. C'est lui qui va ouvrir la fenêtre et gérer le menu.
    AppControler controler;

    return a.exec();
}

