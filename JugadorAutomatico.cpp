#include "JugadorAutomatico.h"

JugadorAutomatico::JugadorAutomatico(): Jugador("Jugador Automatico") { decision = 0; }

JugadorAutomatico::~JugadorAutomatico() { }

// Funcion principal del jugador automatico
// ACLARACION IMPORTANTE: El booleano mina y el entero minasAlrededor NO deberían ser accesibles
// a menos que la casilla sea REVELADA.
void JugadorAutomatico::seleccionarCasilla (int &fila, int &columna) {

    int filas = tableroActual->getFilas();
    int columnas = tableroActual->getColumnas();

    // VERIFICAR SI YA HAY JUGADAS SEGURAS QUE FUERON VERIFICADAS PREVIAMENTE
    if (!casillasSeguras.empty()) {
        set<pair<int, int>>::iterator iteradorSeguras = casillasSeguras.begin();
        pair<int, int> coordenadas = *iteradorSeguras;
        fila = coordenadas.first;
        columna = coordenadas.second;
        casillasSeguras.erase(iteradorSeguras);
        decision = 1;
        cout << fila << " " << columna << "\n";
        return;
    } else if (!casillasConMinas.empty()) {
        set<pair<int, int>>::iterator iteradorConMinas = casillasConMinas.begin();
        pair<int, int> coordenadas = *iteradorConMinas;
        fila = coordenadas.first;
        columna = coordenadas.second;
        casillasConMinas.erase(iteradorConMinas);
        decision = 2;
        cout << fila << " " << columna << "\n";
        return;
    }

    for (int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            if(tableroActual->getCasilla(i, j).getRevelada()) {

                // COLOCAR BANDERAS CUANDO LA CANTIDAD DE CASILLAS SIN REVELAR ALREDEDOR DE UNA CASILLA ES IGUAL
                // AL NUMERO DE MINAS ALREDEDOR DE ESA CASILLA
                if (tableroActual->getSinRevelarAlrededor(i, j) ==
                    tableroActual->getCasilla(i, j).getMinasAlrededor()) {
                    for (int k = -1; k <= 1; k++) {
                        for (int l = -1; l <= 1; l++) {
                            if (i + k >= 0 and i + k < filas and j + l >= 0 and j + l < columnas
                            and tableroActual->getCasilla(i + k, j + l).getRevelada() == false
                            and tableroActual->getCasilla(i + k, j + l).getMarcada() == false) {
                                casillasConMinas.insert(make_pair(i + k, j + l));
                            }
                        }
                    }
                }

                // LIBERAR CASILLAS SIN BANDERAS SI LA CANTIDAD DE BANDERAS ALREDEDOR DE LA CASILLA ES IGUAL
                // A LA CANTIDAD DE MINAS ALREDEDOR DE LA CASILLA
                if (tableroActual->getMarcadasAlrededor(i, j) ==
                    tableroActual->getCasilla(i, j).getMinasAlrededor()) {
                    for (int k = -1; k <= 1; k++) {
                        for (int l = -1; l <= 1; l++) {
                            if (i + k >= 0 and i + k < filas and j + l >= 0 and j + l < columnas
                                and tableroActual->getCasilla(i + k, j + l).getRevelada() == false
                                and tableroActual->getCasilla(i + k, j + l).getMarcada() == false) {
                                casillasSeguras.insert(make_pair(i + k, j + l));
                            }
                        }
                    }
                }
            }
        }
    }

    // SELECCIONAR DESPUES DE HABER ANALIZADO EL TABLERO. EN CASO NO HAYA ENCONTRADO UNA JUGADA,
    // USAR DE ULTIMO RECURSO UNA JUGADA ALEATORIA
    if (!casillasSeguras.empty()) {
        set<pair<int, int>>::iterator iteradorSeguras = casillasSeguras.begin();
        pair<int, int> coordenadas = *iteradorSeguras;
        fila = coordenadas.first;
        columna = coordenadas.second;
        casillasSeguras.erase(iteradorSeguras);
        decision = 1;
        cout << fila << " " << columna << "\n";
    } else if (!casillasConMinas.empty()) {
        set<pair<int, int>>::iterator iteradorConMinas = casillasConMinas.begin();
        pair<int, int> coordenadas = *iteradorConMinas;
        fila = coordenadas.first;
        columna = coordenadas.second;
        casillasConMinas.erase(iteradorConMinas);
        decision = 2;
        cout << fila << " " << columna << "\n";
    } else {
        pair<int, int> coordenadas;
        do {
            coordenadas.first = rand() % tableroActual->getFilas();
            coordenadas.second = rand() % tableroActual->getColumnas();
        } while (tableroActual->getCasilla(coordenadas.first, coordenadas.second).getMarcada()
        or tableroActual->getCasilla(coordenadas.first, coordenadas.second).getRevelada());
        decision = 1;
        fila = coordenadas.first;
        columna = coordenadas.second;
        cout << fila << " " << columna << "\n";
    }
}

void JugadorAutomatico::seleccionarAccion(int &accion) {
    accion = decision;
    cout << accion << "\n";

    string delay;
    getline(cin, delay);
}

void JugadorAutomatico::setTableroActual(Tablero* _tableroActual) {
    tableroActual = _tableroActual;
}
