#include "pomodoro.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Pomodoro::Pomodoro(int work)
    : workDuration(work), sessionCount(0) {
    // Cálculo das pausas com base no tempo de trabalho
    shortBreak = workDuration * 0.2;  // 20% do tempo de trabalho
    longBreak = workDuration * 0.6;   // 60% do tempo de trabalho
}

void Pomodoro::printProgress(int sec, const string &message) {
    // Função para exibir o progresso com uma barra visual
    int progress = (workDuration - sec) * 50 / workDuration;  // Progresso da barra (escala de 0 a 50)
    cout << "\r" << message << " restante: "
         << sec / 60 << "m " << sec % 60 << "s | [";
    for (int i = 0; i < progress; i++) {
        cout << "=";  // Representação do progresso
    }
    for (int i = progress; i < 50; i++) {
        cout << " ";  // Espaços vazios para o restante da barra
    }
    cout << "]" << flush;
}

void Pomodoro::countdown(int sec, const string &message) {
    while (sec > 0) {
        printProgress(sec, message);
        
        this_thread::sleep_for(chrono::seconds(1));
        sec--;

        if (cin.peek() == 'q') {  // Se 'q' for digitado, interrompe
            cin.ignore();
            cout << "\nTimer interrompido!\n";
            exit(0);
        }
    }
    cout << "\r" << message << " finalizado!                    " << endl;
}

void Pomodoro::startSession() {
    for (int i = 1; i <= 4; i++) {
        countdown(workDuration, "Tempo de trabalho");

        if (i < 4) {
            countdown(shortBreak, "Pausa curta");
        } else {
            countdown(longBreak, "Pausa longa");
        }
    }
    cout << "\nCiclo Pomodoro completo!\n";
}
