#include "Timer.h"
#include <QDebug>

Timer::Timer(int interval,QObject* parent) : QThread(parent) , _interval(interval)
{
    _timer = nullptr;
}

void Timer::setInterval(const int interval)
{
    connect(this,SIGNAL(sig_startTimer(int)),_timer,SLOT(start(int)),Qt::UniqueConnection);
    connect(this,SIGNAL(sig_stopTimer()),_timer,SLOT(stop()),Qt::UniqueConnection);
    connect(_timer,SIGNAL(timeout()),this,SIGNAL(sig_timeout()),Qt::UniqueConnection);
    _interval = interval ;
}

void Timer::startTimer()
{
    emit sig_startTimer(_interval);
}

void Timer::startTimer(const int interval)
{
    _interval = interval;
    emit sig_startTimer(_interval);
}

void Timer::stopTimer()
{
    emit sig_stopTimer();
}

void Timer::run()
{
    if(_timer == nullptr)
    {
        _timer = new QTimer;
    }
    _timer->setInterval(_interval);
    exec();
}
