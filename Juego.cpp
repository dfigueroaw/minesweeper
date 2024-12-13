#include "Juego.h"
#include <iostream>
#include <fstream>

using namespace std;

Juego::Juego(Jugador *_jugador) {
    tablero = nullptr;
    jugador = _jugador;
}

Juego::~Juego() {
    delete tablero;
}

void Juego::guardarHistorial(const int &tiempoInicial, const int &tiempoFinal) {
    // Crear un objeto HistorialPartida con la información de la partida
    HistorialPartida historial;
    historial.jugador = jugador->getNombre();
    historial.resultado = tablero->getGameState();
    historial.tiempoInicio = tiempoInicial;
    historial.duracion = tiempoFinal - tiempoInicial;

    // Abrir el archivo de historial (si no existe, se crea)
    ofstream archivo("historial.txt", ios::app);
    if (archivo.is_open()) {
        archivo << historial.toString() << endl; // Escribir la información en el archivo
        archivo.close(); // Cerrar el archivo después de escribir
    } else {
        cout << "ERROR AL PROCESAR EL ARCHIVO DEL HISTORIAL" << endl;
    }

}

void Juego::inicializarPersonalizado() {

    int filas, columnas, minas;

    do {
        cout << "Ingrese el numero de filas: ";
        cin >> filas;
        limpiar();
    } while (filas <= 0);

    do {
        cout << "Ingrese el numero de columnas: ";
        cin >> columnas;
        limpiar();
    } while (columnas <= 0);

    do {
        cout << "Ingrese el numero de minas: ";
        cin >> minas;
        limpiar();
    } while (minas <= 0 or minas >= filas * columnas);

    tablero = new TableroPersonalizado(filas, columnas, minas);
    tablero->inicializarTablero();

}

void Juego::inicializarFacil() {
    tablero = new TableroFacil();
    tablero->inicializarTablero();
}

void Juego::inicializarMedio() {
    tablero = new TableroMedio();
    tablero->inicializarTablero();
}

void Juego::inicializarDificil() {
    tablero = new TableroDificil();
    tablero->inicializarTablero();
}

void Juego::jugar() {
    int fila, columna, accion;

    int tiempoInicial = tomarTiempo();

    while (tablero->getGameState() == 'p') {

        cout << "Banderas colocadas: " << tablero->getBanderas() << endl;
        cout << "Banderas restantes: " << tablero->getMinas() - tablero->getBanderas() << endl;
        tablero->imprimirTablero();

        do {
            cout << "Ingrese las coordenadas de una celda: ";
            jugador->seleccionarCasilla(fila, columna);
        } while (fila < 0 or fila >= tablero->getFilas() or columna < 0 or
                 columna >= tablero->getColumnas());
        if (tablero->getCasilla(fila, columna).getRevelada() == false) {
            cout << "1. Revelar casilla" << endl;
            if (tablero->getCasilla(fila, columna).getMarcada() == false) {
                cout << "2. Marcar casilla" << endl;
            } else {
                cout << "2. Desmarcar casilla" << endl;
            }
            cout << "3. Regresar" << endl;
            cout << "Eliga una opcion [1 - 3]: ";
            do {
                jugador->seleccionarAccion(accion);
            } while (accion < 1 or accion > 3);

            limpiar();

            switch (accion) {
                case 1:
                    tablero->revelarCasilla(fila, columna);
                    break;
                case 2:
                    if (tablero->getCasilla(fila, columna).getMarcada() == false) {
                        tablero->marcarCasilla(fila, columna);
                    } else {
                        tablero->desmarcarCasilla(fila, columna);
                    }
                    break;
            }
        }
    }

    if (tablero->getGameState() == 'w') {
        tablero->imprimirTablero();
        cout << jugador->getNombre() << ", GANASTE" << endl;
        jugador->setPartidasJugadas(jugador->getPartidasJugadas() + 1);
        jugador->setVictorias(jugador->getVictorias() + 1);
    } else {
        for (int i = 0; i < tablero->getFilas(); i++) {
            for (int j = 0; j < tablero->getColumnas(); j++) {
                if (tablero->getCasilla(i, j).getRevelada() == false) {
                    tablero->getCasilla(i, j).setMarcada(false);
                    tablero->getCasilla(i, j).setRevelada(true);
                }
            }
        }
        tablero->imprimirTablero();
        cout << jugador->getNombre() << ", PERDISTE" << endl;
        jugador->setPartidasJugadas(jugador->getPartidasJugadas() + 1);
        jugador->setDerrotas(jugador->getDerrotas() + 1);
    }

    // LOGICA PARA GUARDAR AL HISTORIAL
    int tiempoFinal = tomarTiempo();
    guardarHistorial(tiempoInicial, tiempoFinal);

}

Tablero* Juego::getTablero() {
    return tablero;
}
