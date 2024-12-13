#ifndef MINESWEEPER_JUGADORHUMANO_H
#define MINESWEEPER_JUGADORHUMANO_H

#include "Jugador.h"

class JugadorHumano : public Jugador {
public:
    JugadorHumano();

    JugadorHumano(string _nombre);

    ~JugadorHumano();

    void seleccionarCasilla(int &fila, int &columna) override;

    void seleccionarAccion(int &accion) override;
};


#endif //MINESWEEPER_JUGADORHUMANO_H
