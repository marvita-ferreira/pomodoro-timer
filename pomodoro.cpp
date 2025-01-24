#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void countdown(int minutes, const string &message) {
    int seconds = minutes * 60;

    while (seconds > 0) {
        int mins = seconds / 60;
        int secs = seconds % 60;
        cout << "\r" << message << " " 
             << mins << "m " << secs << "s restante..." << flush;
        this_thread::sleep_for(chrono::seconds(1));
        --seconds;
    }

    cout << "\r" << message << " concluÃ­do!                " << endl;
}

int main() {
    int work_duration = 25; // DuraÃ§Ã£o padrÃ£o do Pomodoro em minutos
    int short_break = 5;    // Pausa curta em minutos
    int long_break = 15;    // Pausa longa em minutos
    int sessions = 4;       // NÃºmero de ciclos de trabalho antes da pausa longa

    cout << "Bem-vindo ao Pomodoro Timer!" << endl;
    cout << "ConfiguraÃ§Ã£o padrÃ£o: " << work_duration << "m trabalho, " 
         << short_break << "m pausa curta, " << long_break << "m pausa longa." << endl;

    for (int i = 1; i <= sessions; ++i) {
        cout << "\nCiclo de trabalho " << i << " de " << sessions << endl;
        countdown(work_duration, "Trabalhando");
        
        if (i < sessions) {
            cout << "\nHora de uma pausa curta!" << endl;
            countdown(short_break, "Pausa curta");
        } else {
            cout << "\nCiclo finalizado! Aproveite uma pausa longa." << endl;
            countdown(long_break, "Pausa longa");
        }
    }

    cout << "\nParabÃ©ns! Todos os ciclos foram concluÃ­dos!" << endl;
    return 0;
}
