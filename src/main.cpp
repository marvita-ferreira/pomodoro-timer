#include "pomodoro.h"
#include <iostream>

using namespace std;  // Adicionando isso para evitar o uso de std:: em todo o código

int main() {
    int workMinutes;

    cout << "Digite o tempo de trabalho (minutos): ";
    cin >> workMinutes;

    if (workMinutes <= 0) {
        cout << "O tempo de trabalho deve ser maior que zero. Tente novamente.\n";
        return 1;
    }

    Pomodoro pomodoro(workMinutes * 60);  // Convertendo para segundos
    pomodoro.startSession();

    return 0;
}
