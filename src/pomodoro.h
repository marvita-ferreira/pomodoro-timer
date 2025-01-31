#ifndef POMODORO_H
#define POMODORO_H

#include <string>

class Pomodoro {
public:
    Pomodoro(int workMins);
    void startSession();

private:
    int workDuration;
    int shortBreak;
    int longBreak;
    int sessionCount;

    void countdown(int sec, const std::string &message);
};

#endif
