#include "PlayManage.h"
#include <QApplication>
#include <QDir>
#include <QRandomGenerator>
#include <QDebug>
#include <QTimer>

PlayManage::PlayManage(QObject *parent) : QObject(parent)
{
    _playModel = 0;
}

void PlayManage::init()
{
    QString currentDir = qApp->applicationDirPath();
    QString pictureDir = currentDir + "/Picture";

    QDir dir(pictureDir);
    if(dir.exists())
    {
        QStringList filter;
        filter << "*.jpg" << "*.bmp";
        QStringList list = dir.entryList(filter);
        foreach(QString fileName,list)
        {
            _pictureList.append(pictureDir + "/" + fileName);
        }
    }
}

QString PlayManage::getNextPicture()
{
    QString ret;

    switch(_playModel)
    {
    case 0:
        ret = playLoop();
        break;
    case 1:
        ret = playInFulllyRandom();
        break;
    default:
        ret = playLoop();
    }

    return ret;
}

QString PlayManage::playLoop()
{
    QString ret;
    static int index = 0;
    int size = _pictureList.size();
    if(index >=0 && index < size)
    {
        ret = _pictureList.at(index);
        index += 1;
        if(index == size)
            index = 0;
    }

    return ret;
}

QString PlayManage::playInFulllyRandom()
{
    QString ret;
    int size = _pictureList.size();
    if(size > 0)
    {
        int index = QRandomGenerator::global()->bounded(size);
        ret = _pictureList.at(index);
    }

    return ret;
}

