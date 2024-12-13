#include "Casilla.h"

Casilla::Casilla() {
    revelada = false;
    marcada = false;
    mina = false;
    minasAlrededor = 0;
    x = 0;
    y = 0;
}

Casilla::~Casilla() { }

// Getters
bool Casilla::getRevelada() { return revelada; }

bool Casilla::getMarcada() { return marcada; }

bool Casilla::getMina() { return mina; }

int Casilla::getMinasAlrededor() { return minasAlrededor; }

int Casilla::getX() { return x; }

int Casilla::getY() { return y; }

// Setters
void Casilla::setRevelada(bool _revelada) { revelada = _revelada; }

void Casilla::setMarcada(bool _marcada) { marcada = _marcada; }

void Casilla::setMina(bool _mina) { mina = _mina; }

void Casilla::setMinasAlrededor(int _minasAlrededor) { minasAlrededor = _minasAlrededor; }

void Casilla::setX(int _x) { x = _x; }

void Casilla::setY(int _y) { y = _y; }

