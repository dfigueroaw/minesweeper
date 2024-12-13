#include "Jugador.h"

// Constructores
Jugador::Jugador() {
    nombre = "Sin nombre";
    victorias = 0;
    derrotas = 0;
    partidasJugadas = 0;
}

Jugador::Jugador(string _nombre) {
    nombre = _nombre;
    victorias = 0;
    derrotas = 0;
    partidasJugadas = 0;
}

// Destructores
Jugador::~Jugador() { }

// Getters
string Jugador::getNombre() { return nombre; }

int Jugador::getVictorias() { return victorias; }

int Jugador::getDerrotas() { return derrotas; }

int Jugador::getPartidasJugadas() { return partidasJugadas; };

// Setters
void Jugador::setNombre(string _nombre) { nombre = _nombre; }

void Jugador::setVictorias(int _victorias) { victorias = _victorias; }

void Jugador::setDerrotas(int _derrotas) { derrotas = _derrotas; }

void Jugador::setPartidasJugadas(int _partidasJugadas) { partidasJugadas = _partidasJugadas; }
