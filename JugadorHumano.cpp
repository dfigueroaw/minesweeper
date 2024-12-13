#include "JugadorHumano.h"

JugadorHumano::JugadorHumano() { }

JugadorHumano::JugadorHumano(string _nombre): Jugador(_nombre) { }

JugadorHumano::~JugadorHumano() { };

void JugadorHumano::seleccionarCasilla(int &fila, int &columna) {
    cin >> fila >> columna;
}

void JugadorHumano::seleccionarAccion(int &accion) {
    cin >> accion;
}

