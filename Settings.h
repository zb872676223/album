#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings
{
    Settings();
    ~Settings();
public:
    static Settings * getSingleton ()
    {
        static Settings inst ;
        return & inst ;
    }

    void readParameter();
    void saveParameter();

    int timerInterval() const;
    void setTimerInterval(int timerInterval);

    int playMode() const;
    void setPlayMode(int playMode);

    int scaledMode() const;
    void setScaledMode(int scaledMode);

signals:

private:
    QString _filePath;
    int _timerInterval;
    int _playMode;
    int _scaledMode;

};

#endif // SETTINGS_H
