#include <iostream>
using namespace std;

char tablero[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char jugador_actual = 'X';

void mostrarTablero() {
    system("clear"); 
    cout << "\n";
    cout << "     Juego de Tres en Línea (X - O)\n\n";
    for (int i = 0; i < 3; i++) {
        cout << "     ";
        for (int j = 0; j < 3; j++) {
            cout << " " << tablero[i][j] << " ";
            if (j < 2) cout << "|";
        }
        if (i < 2) cout << "\n    ---+---+---\n";
    }
    cout << "\n\n";
}

bool hayGanador() {
    // Filas y columnas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador_actual && tablero[i][1] == jugador_actual && tablero[i][2] == jugador_actual)
            return true;
        if (tablero[0][i] == jugador_actual && tablero[1][i] == jugador_actual && tablero[2][i] == jugador_actual)
            return true;
    }
    // Diagonales
    if (tablero[0][0] == jugador_actual && tablero[1][1] == jugador_actual && tablero[2][2] == jugador_actual)
        return true;
    if (tablero[0][2] == jugador_actual && tablero[1][1] == jugador_actual && tablero[2][0] == jugador_actual)
        return true;
    return false;
}

bool esEmpate() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O')
                return false;
    return true;
}

void cambiarJugador() {
    jugador_actual = (jugador_actual == 'X') ? 'O' : 'X';
}

void jugar() {
    int casilla;
    while (true) {
        mostrarTablero();
        cout << "Jugador " << jugador_actual << ", elige una casilla (1-9): ";
        cin >> casilla;

        if (cin.fail() || casilla < 1 || casilla > 9) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "Entrada inválida. Intenta de nuevo.\n";
            continue;
        }

        int fila = (casilla - 1) / 3;
        int col = (casilla - 1) % 3;

        if (tablero[fila][col] == 'X' || tablero[fila][col] == 'O') {
            cout << "Casilla ocupada. Intenta otra.\n";
            continue;
        }

        tablero[fila][col] = jugador_actual;

        if (hayGanador()) {
            mostrarTablero();
            cout << "¡Jugador " << jugador_actual << " gana!\n";
            break;
        }

        if (esEmpate()) {
            mostrarTablero();
            cout << "¡Empate!\n";
            break;
        }

        cambiarJugador();
    }
}

int main() {
    jugar();
    return 0;
}
