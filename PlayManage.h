#ifndef PLAYEMANAGE_H
#define PLAYEMANAGE_H

#include <QObject>
#include <QStringList>
#include <QString>
#include "Singleton.h"

class PlayManage : public QObject, public Singleton<PlayManage>
{
    Q_OBJECT
public:
    explicit PlayManage(QObject *parent = nullptr);
    void init();
    void setPlayMode(int mode) {_playModel = mode;}
    QString getNextPicture();

private:
    QStringList _pictureList;
    int _playModel;

    QString playLoop();
    QString playInFulllyRandom();
};

#endif // PLAYEMANAGE_H
