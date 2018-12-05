#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include <QThread>


class Timer : public QThread
{
    Q_OBJECT
public:
    Timer(int interval = 1000, QObject *parent = nullptr);
    void setInterval(const int interval);
    void startTimer();
    void startTimer(const int interval);
    void stopTimer();

signals:
    void sig_timeout();

    void sig_startTimer(int interval);
    void sig_stopTimer();

protected:
    virtual void run();

private:
    QTimer* _timer;
    int _interval;

};

#endif // TIMER_H
