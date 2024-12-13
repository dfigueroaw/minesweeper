#ifndef MINESWEEPER_TABLERO_H
#define MINESWEEPER_TABLERO_H

#include "Casilla.h"

class Tablero {
protected:
    // Atributos
    Casilla** casillas;
    int filas;
    int columnas;
    int minas;
    int reveladas;
    int banderas;
    char gameState;

public:
    // Constructores
    Tablero();

    Tablero(int _filas, int _columnas, int _minas);

    // Destructores
    virtual ~Tablero();

    // Getters
    Casilla** getCasillas();
    int getFilas();
    int getColumnas();
    int getMinas();
    int getBanderas();
    char getGameState();
    Casilla& getCasilla(int fila, int columna);

    // Metodos
    void imprimirCasilla(int fila, int columna);
    void imprimirTablero();
    void inicializarTablero();
    void revelarCasilla(int fila, int columna);
    void marcarCasilla(int fila, int columna);
    void desmarcarCasilla(int fila, int columna);
    int getSinRevelarAlrededor(int filas, int columnas);
    int getMarcadasAlrededor(int fila, int columna);
    };

class TableroFacil : public Tablero {
public:
    TableroFacil() : Tablero(8, 8, 10) { }
    ~TableroFacil() { };
};

class TableroMedio : public Tablero {
public:
    TableroMedio() : Tablero(16, 16, 40) { }
    ~TableroMedio() { };
};

class TableroDificil : public Tablero {
public:
    TableroDificil() : Tablero(30, 16, 99) { }
    ~TableroDificil() { };
};

class TableroPersonalizado : public Tablero {
public:
    TableroPersonalizado(int _filas, int _columnas, int _minas) : Tablero(_filas, _columnas, _minas) { }
    ~TableroPersonalizado() { };
};

#endif //MINESWEEPER_TABLERO_H