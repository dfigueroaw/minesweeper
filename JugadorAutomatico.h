#ifndef MINESWEEPER_JUGADORAUTOMATICO_H
#define MINESWEEPER_JUGADORAUTOMATICO_H

#include "Jugador.h"
#include "Tablero.h"
#include <set>

class JugadorAutomatico : public Jugador {
private:
    int decision;
    Tablero* tableroActual;
    set<pair<int, int>> casillasSeguras;
    set<pair<int, int>> casillasConMinas;

public:
    JugadorAutomatico();

    ~JugadorAutomatico();

    void seleccionarCasilla(int &fila, int &columna) override;

    void seleccionarAccion(int &accion) override;

    void setTableroActual(Tablero* _tableroActual);
};


#endif //MINESWEEPER_JUGADORAUTOMATICO_H

