#include "Tablero.h"
#include <iomanip>
#include <iostream>
#include <set>
#include "ConsoleManager.h"

using namespace std;

// Constructores
Tablero::Tablero() {
    filas = 0;
    columnas = 0;
    minas = 0;
    reveladas = 0;
    banderas = 0;
    gameState = 'p';
    casillas = nullptr;
};

Tablero::Tablero(int _filas, int _columnas, int _minas) {
    filas = _filas;
    columnas = _columnas;
    minas = _minas;
    reveladas = 0;
    banderas = 0;
    gameState = 'p';
    casillas = nullptr;
};

// Destructores
Tablero::~Tablero() {
    for (int i = 0; i < filas; i++) {
        delete[] casillas[i];
    }
    delete[] casillas;
}

// Getters
Casilla** Tablero::getCasillas() { return casillas; }

int Tablero::getFilas() { return filas; }

int Tablero::getColumnas() { return columnas; }

int Tablero::getMinas() { return minas; }

int Tablero::getBanderas() { return banderas; }

char Tablero::getGameState() { return gameState; }

Casilla& Tablero::getCasilla(int fila, int columna) {
    return casillas[fila][columna];
}

// Metodos
void Tablero::imprimirCasilla(int fila, int columna) {
    if(getCasilla(fila, columna).getRevelada()){
        if (getCasilla(fila, columna).getMina() == false) {
            if (getCasilla(fila, columna).getMinasAlrededor() == 0) {
                cout << ".";
            } else {
                imprimirColorNumero(getCasilla(fila, columna).getMinasAlrededor());
            }
        } else {
            cout << "*";
        }
    } else {
        if (getCasilla(fila, columna).getMarcada() == false) {
            cout << "#";
        } else {
            cout << "P";
        }

    }
}

void Tablero::imprimirTablero() {
    cout << setw(6);
    for (int i = 0; i < columnas; i++) {
        cout << i << setw(3);
    }
    cout << endl;
    for (int i = 0; i < filas; i++) {
        cout << setw(3) << i;
        for (int j = 0; j < columnas; j++) {
            cout << setw(3);
            imprimirCasilla(i,j);
        }
        cout << endl;
    }
}

void Tablero::inicializarTablero() {

    set<pair<int, int>> posiciones_minas;

    // Establecer posiciones de minas
    while (posiciones_minas.size() < minas) {
        int fila = rand() % filas;
        int columna = rand() % columnas;
        posiciones_minas.insert(make_pair(fila, columna));
    }

    casillas = new Casilla* [filas];

    // Inicializar tablero
    for (int i = 0; i < filas; i++) {
        casillas[i] = new Casilla[columnas];
        for (int j = 0; j < columnas; j++) {
            casillas[i][j].setX(i);
            casillas[i][j].setY(j);
        }
    }

    for (pair<int, int> p : posiciones_minas) {
        getCasilla(p.first, p.second).setMina(true);
    }

    int minasAlrededor = 0;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            minasAlrededor = 0;

            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (getCasilla(i, j).getX() + k >= 0 and
                        getCasilla(i, j).getX() + k < filas and
                        getCasilla(i, j).getY() + l >= 0 and
                        getCasilla(i, j).getY() + l < columnas and
                        getCasilla(i + k, j + l).getMina() == true) {
                        minasAlrededor++;
                    }
                }
            }

            getCasilla(i, j).setMinasAlrededor(minasAlrededor);
        }
    }
}

void Tablero::revelarCasilla(int fila, int columna) {
    if (getCasilla(fila, columna).getRevelada() == false) {

        getCasilla(fila, columna).setRevelada(true);
        getCasilla(fila, columna).setMarcada(false);
        reveladas++;

        if (getCasilla(fila, columna).getMina() == false) {
            if (getCasilla(fila, columna).getMinasAlrededor() == 0) {
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (getCasilla(fila, columna).getX() + i >= 0 and
                            getCasilla(fila, columna).getX() + i < filas and
                            getCasilla(fila, columna).getY() + j >= 0 and
                            getCasilla(fila, columna).getY() + j < columnas) {
                            revelarCasilla(getCasilla(fila, columna).getX() + i,
                                           getCasilla(fila, columna).getY() + j);
                        }
                    }
                }
            }
            if (filas * columnas - reveladas == minas) {
                gameState = 'w';
            }
        } else {
            gameState = 'l';
        }
    }
}

void Tablero::marcarCasilla(int fila, int columna) {
    if (getCasilla(fila, columna).getMarcada() == false) {
        getCasilla(fila, columna).setMarcada(true);
        banderas++;
    }
}

void Tablero::desmarcarCasilla(int fila, int columna) {
    if (getCasilla(fila, columna).getMarcada() == true) {
        getCasilla(fila, columna).setMarcada(false);
        banderas--;
    }
}

// Se envia una posición y retorna las casillas reveladas alrededor
int Tablero::getSinRevelarAlrededor(int fila, int columna) {

    int sinRevelarAlrededor = 0;

    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (getCasilla(fila, columna).getX() + k >= 0 and
                getCasilla(fila, columna).getX() + k < filas and
                getCasilla(fila, columna).getY() + l >= 0 and
                getCasilla(fila, columna).getY() + l < columnas and
                getCasilla(fila + k, columna + l).getRevelada() == false) {
                sinRevelarAlrededor++;
            }
        }
    }

    return sinRevelarAlrededor;

}

int Tablero::getMarcadasAlrededor(int fila, int columna) {

    int marcadasAlrededor = 0;

    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (getCasilla(fila, columna).getX() + k >= 0 and
                getCasilla(fila, columna).getX() + k < filas and
                getCasilla(fila, columna).getY() + l >= 0 and
                getCasilla(fila, columna).getY() + l < columnas and
                getCasilla(fila + k, columna + l).getMarcada() == true) {
                marcadasAlrededor++;
            }
        }
    }

    return marcadasAlrededor;

}