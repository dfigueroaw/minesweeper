#ifndef MINESWEEPER_CONSOLEMANAGER_H
#define MINESWEEPER_CONSOLEMANAGER_H

#include <cstdlib>
#include <iostream>

using namespace std;

extern bool permitirColores;
extern bool permitirLimpiar;

enum Color {
    // A la palabra de tipo Color se le asigna un valor
    azul = 94,
    verde = 92,
    rojo = 91,
    magenta = 95,
    amarillo = 93,
    cian = 96,
    negro = 90,
    blanco = 97,
    predeterminado = 0,
};

void limpiar();
void imprimirColor(Color color, string texto);
void imprimirColorNumero(int numero);
string imprimirBooleano(bool variable);

#endif //MINESWEEPER_CONSOLEMANAGER_H

