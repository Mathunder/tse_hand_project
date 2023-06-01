#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Hand Game");
    QIcon icon("../ressources/imgs/hand_pixel_art.png");
    w.setWindowIcon(icon);
    w.show();
    return a.exec();
}
