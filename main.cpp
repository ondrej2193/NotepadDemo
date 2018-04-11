#include "notepaddemo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NotepadDemo w;
    w.show();

    return a.exec();
}
