#include "pomodoro.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;

// Constructor initializes Pomodoro settings
Pomodoro::Pomodoro(int workMins)
    : workDuration(workMins * 60),
      shortBreak(workMins * 0.2 * 60),  // Short break = 20% of work time
      longBreak(workMins * 0.6 * 60),   // Long break = 60% of work time
      sessionCount(0) {}

void Pomodoro::startSession() {
    for (int i = 1; i <= 4; i++) {
        countdown(workDuration, "🔵 Trabalho");

        if (i < 4) {
            countdown(shortBreak, "🟢 Pausa Curta");
        } else {
            countdown(longBreak, "🔴 Pausa Longa");
        }
        sessionCount++;
    }
    cout << "\n🎉 Ciclo Pomodoro Completo! 🎉\n";
}

void Pomodoro::countdown(int sec, const string &message) {
    while (sec > 0) {
        cout << "\r" << message << " Restante: " 
             << sec / 60 << "m " << sec % 60 << "s   " << flush;
        this_thread::sleep_for(chrono::seconds(1));  // ✅ Fixed here
        sec--;
    }
    cout << "\r" << message << " Finalizado!                    " << endl;
}
