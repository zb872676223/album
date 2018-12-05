#ifndef ALBUM_H
#define ALBUM_H

#include <QObject>
#include "Timer.h"
#include "PlayManage.h"
#include "PictureWidget.h"
#include "Settings.h"

class Album : public QObject
{
    Q_OBJECT
public:
    explicit Album(QObject *parent = nullptr);
    void init();
signals:

private:
    void initSettings();
    void initTimer();
    void initPlayParameter();
    void initWidget();

private:
    PictureWidget* _pictureWidget;
    Timer* _timer;

private slots:
    void updatePicture();
};

#endif // ALBUM_H
