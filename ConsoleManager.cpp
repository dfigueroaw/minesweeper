#include "ConsoleManager.h"

using namespace std;

bool permitirColores = true;
bool permitirLimpiar = false;

void limpiar() {
    if(permitirLimpiar) {
        system("cls");
    }
}

void imprimirColor(Color color, string texto) {
    if(permitirColores) {
        cout << "\033[" << color << "m " << texto << "\033[0m";
    } else {
        cout << texto;
    }
}

void imprimirColorNumero(int numero){
    switch(numero) {
        case 1:
            imprimirColor(azul, "1");
            break;
        case 2:
            imprimirColor(verde, "2");
            break;
        case 3:
            imprimirColor(rojo, "3");
            break;
        case 4:
            imprimirColor(magenta, "4");
            break;
        case 5:
            imprimirColor(amarillo, "5");
            break;
        case 6:
            imprimirColor(cian, "6");
            break;
        case 7:
            imprimirColor(negro, "7");
            break;
        case 8:
            imprimirColor(blanco, "8");
            break;
    }
}

string imprimirBooleano(bool variable) {
    if(variable) {
        return "SI";
    } else {
        return "NO";
    }
}
