#include "mainQthread.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainQthread w;
    w.show();
    return a.exec();
}
