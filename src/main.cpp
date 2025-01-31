#include "pomodoro.h"
#include <iostream>

int main() {
    int workMinutes;

    std::cout << "Digite o tempo de trabalho (minutos): ";
    std::cin >> workMinutes;

    if (workMinutes <= 0) {
        std::cout << "O tempo deve ser maior que zero. Tente novamente.\n";
        return 1;
    }

    Pomodoro pomodoro(workMinutes);
    pomodoro.startSession();

    return 0;
}
