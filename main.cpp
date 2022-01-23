#include "tasks.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tasks w;
    w.show();
    return a.exec();
}
