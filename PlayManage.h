#ifndef PLAYEMANAGE_H
#define PLAYEMANAGE_H

#include <QObject>
#include <QStringList>
#include <QString>

class PlayManage : public QObject
{
    Q_OBJECT
    explicit PlayManage(QObject *parent = nullptr);
public:
    static PlayManage * getSingleton ()
    {
        static PlayManage inst ;
        return & inst ;
    }

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
