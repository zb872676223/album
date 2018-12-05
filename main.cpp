#include <QApplication>
#include "Album.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Album album;
    album.init();

    return a.exec();
}
