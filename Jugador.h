#ifndef MINESWEEPER_JUGADOR_H
#define MINESWEEPER_JUGADOR_H
#include <iostream>

using namespace std;

class Jugador {
protected:
    string nombre;
    int victorias, derrotas, partidasJugadas;
public:
    Jugador();
    Jugador(string _nombre);
    virtual ~Jugador();
    void setNombre(string _nombre);
    void setVictorias(int _victorias);
    void setDerrotas(int _derrotas);
    void setPartidasJugadas(int _partidasJugadas);
    string getNombre();
    int getVictorias();
    int getDerrotas();
    int getPartidasJugadas();
    virtual void seleccionarCasilla(int &fila, int &columna) = 0;
    virtual void seleccionarAccion(int &accion) = 0;
};


#endif //MINESWEEPER_JUGADOR_H
