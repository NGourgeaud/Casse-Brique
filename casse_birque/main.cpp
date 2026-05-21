#include "gamemodel.h"
#include "gameview.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    GameModel m;
    GameView * v = new GameView(&m);
    w.setCentralWidget(v);
    w.show();
    v->refresh();
    return QCoreApplication::exec();
}
