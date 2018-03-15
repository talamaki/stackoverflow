#include "controller.h"
#include "worker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller mainWindow;
    mainWindow.show();
    return a.exec();
}
