#include "Album.h"
#include <QDebug>
Album::Album(QObject *parent) : QObject(parent) { }

void Album::init()
{
    initSettings();
    initTimer();
    initPlayParameter();
    initWidget();
}

void Album::initSettings()
{
    Settings::getSingleton()->readParameter();
}

void Album::initTimer()
{
    _timer = new Timer(3000);
    _timer->start();
    _timer->wait(100);

    int timerInterval = Settings::getSingleton()->timerInterval();
    timerInterval = timerInterval * 1000;
    _timer->setInterval(timerInterval);
    connect(_timer,SIGNAL(sig_timeout()),this,SLOT(updatePicture()),Qt::UniqueConnection);

    _timer->startTimer();
}

void Album::initPlayParameter()
{
    PlayManage::getSingleton()->init();
    int playMode = Settings::getSingleton()->playMode();
    PlayManage::getSingleton()->setPlayMode(playMode);
}

void Album::initWidget()
{
    _pictureWidget = new PictureWidget;
    int scaledMode = Settings::getSingleton()->scaledMode();
    _pictureWidget->setScaledMode(scaledMode);
    _pictureWidget->showFullScreen();
    QString file = PlayManage::getSingleton()->getNextPicture();
    _pictureWidget->showPicture(file);
}

void Album::updatePicture()
{
    QString file = PlayManage::getSingleton()->getNextPicture();
    _pictureWidget->showPicture(file);
}
