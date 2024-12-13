#ifndef MINESWEEPER_JUEGO_H
#define MINESWEEPER_JUEGO_H

#include "Tablero.h"
#include "Jugador.h"
#include "ConsoleManager.h"
#include "HistorialManager.h"
#include "TimeManager.h"

class Juego {
private:
    Tablero *tablero;
    Jugador *jugador;

public:
    Juego(Jugador *_jugador);
    ~Juego();

    void guardarHistorial(const int &tiempoInicial, const int &tiempoFinal);
    void inicializarPersonalizado();
    void inicializarFacil();
    void inicializarMedio();
    void inicializarDificil();
    void jugar();

    Tablero* getTablero();
};

#endif //MINESWEEPER_JUEGO_H

