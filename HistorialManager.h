#ifndef MINESWEEPER_HISTORIALMANAGER_H
#define MINESWEEPER_HISTORIALMANAGER_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Jugador.h"
#include "TimeManager.h"
#include "JugadorHumano.h"
#include "JugadorAutomatico.h"

using namespace std;

struct HistorialPartida {
    string jugador;
    char resultado; // 'w' para ganado, 'l' para perdido
    int tiempoInicio;
    int duracion;

    // Método para convertir a formato de texto
    string toString() {
        stringstream ss;
        ss << jugador  << "|" << resultado << "|" << tiempoInicio << "|" << duracion;
        return ss.str();
    }

};

void imprimirHistorialPartidas();

void inicializarJugadores(vector<Jugador*> &jugadores);

void imprimirJugadores(const vector<Jugador*> &jugadores);

#endif //MINESWEEPER_HISTORIALMANAGER_H
