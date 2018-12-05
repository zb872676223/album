#include "Settings.h"
#include <QSettings>
#include <QApplication>
#include <QDebug>

Settings::Settings()
{
    _filePath = qApp->applicationDirPath();
    _filePath += "/setting.ini";
}

Settings::~Settings()
{
    saveParameter();
}

void Settings::readParameter()
{
    bool isOk;


    QSettings settings (_filePath, QSettings::IniFormat);
    settings.beginGroup("PlaySettings");

    _timerInterval = settings.value("PlaySettings/TimerInterval",3).toInt(&isOk);
    if(isOk == false)
        _timerInterval = 3 ;
    _playMode = settings.value("PlaySettings/PlayMode",0).toInt(&isOk);
    if(isOk == false)
        _playMode = 0 ;


    _scaledMode = settings.value("PlaySettings/ScaledMode",1).toInt(&isOk);
    if(isOk == false)
        _scaledMode = 1 ;

    settings.endGroup();
}

void Settings::saveParameter()
{
    QSettings settings (_filePath, QSettings::IniFormat);
    settings.beginGroup("PlaySettings");
    settings.setValue("PlaySettings/TimerInterval",_timerInterval);
    settings.setValue("PlaySettings/PlayMode",_playMode);
    settings.setValue("PlaySettings/ScaledMode",_scaledMode);
    settings.endGroup();
}

int Settings::timerInterval() const
{
    return _timerInterval;
}

void Settings::setTimerInterval(int timerInterval)
{
    _timerInterval = timerInterval;
}

int Settings::playMode() const
{
    return _playMode;
}

void Settings::setPlayMode(int playMode)
{
    _playMode = playMode;
}

int Settings::scaledMode() const
{
    return _scaledMode;
}

void Settings::setScaledMode(int scaledMode)
{
    _scaledMode = scaledMode;
}
