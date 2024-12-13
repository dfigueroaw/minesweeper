#include "Juego.h"
#include "JugadorHumano.h"
#include "JugadorAutomatico.h"
#include "ConsoleManager.h"
#include "HistorialManager.h"
#include <vector>

using namespace std;

void imprimirMenu(string display) {
    if (display == "menu") {
        cout << " ___  _ _  ___  ___  ___  __ __  _  _ _  ___  ___ \n"
                "| . ]| | |/ __]|  _]| . ||  \\  \\| || \\ || . |/ __]\n"
                "| . \\| | |\\__ \\| [__|   ||     || ||   ||   |\\__ \\\n"
                "|___/ \\__|[___/`___/|_|_||_|_|_||_||_\\_||_|_|[___/\n";
        cout << "--- BIENVENIDO A BUSCAMINAS (VERSION CONSOLA) ---" << endl;
        cout << "1. JUEGO NUEVO" << endl;
        cout << "2. JUEGO AUTOMATICO" << endl;
        cout << "3. HISTORIAL DE PARTIDAS" << endl;
        cout << "4. CONFIGURACIONES" << endl;
        cout << "5. SALIR DEL JUEGO" << endl;
        cout << "SELECCIONE UNA OPCION [1 - 5]: ";
    } else if (display == "tableros") {
        cout << "1. TABLERO FACIL" << endl;
        cout << "2. TABLERO INTERMEDIO" << endl;
        cout << "3. TABLERO DIFICIL" << endl;
        cout << "4. TABLERO PERSONALIZADO" << endl;
        cout << "5. REGRESAR" << endl;
        cout << "SELECCIONE UNA OPCION [1 - 5]: ";
    } else if (display == "config") {
        cout << "1. COLORES HABILITADOS: " << imprimirBooleano(permitirColores) << endl;
        cout << "2. LIMPIEZA DE PANTALLA HABILITADA: " << imprimirBooleano(permitirLimpiar) << endl;
        cout << "3. REGRESAR" << endl;
        cout << "SELECCIONE UNA OPCION [1 - 3]: ";
    } else if (display == "historial") {
        cout << "1. REGRESAR" << endl;
        cout << "SELEECIONE UNA OPCION [1]: ";
    }
}

Jugador* seleccionarJugador(vector<Jugador*> &jugadores) {

    string nombre;
    int opcion, idxJugador;

    if(jugadores.empty()) {
        cout << "INGRESE EL NOMBRE DEL JUGADOR NUEVO: ";
        cin >> nombre;
        limpiar();
        jugadores.emplace_back(new JugadorHumano(nombre));
        return jugadores[0];
    } else {
        do {
            cout << "1. SELECCIONAR JUGADOR EXISTENTE\n";
            cout << "2. CREAR JUGADOR NUEVO\n";
            cout << "SELECCIONE UNA OPCION [1 - 2]: ";
            cin >> opcion;
            limpiar();
            switch(opcion) {
                case 1:
                    do {
                        for (int i = 0; i < jugadores.size(); i++) {
                            cout << i + 1 << ". " << jugadores[i]->getNombre() << endl;
                        }
                        cout << "SELECCIONA UNA OPCION [1 - " << jugadores.size() << "]: ";
                        cin >> idxJugador;
                        limpiar();
                    } while (idxJugador <= 0 or idxJugador > jugadores.size());
                    return jugadores[idxJugador - 1];
                case 2:
                    cout << "INGRESE EL NOMBRE DEL JUGADOR NUEVO: ";
                    cin >> nombre;
                    limpiar();
                    jugadores.emplace_back(new JugadorHumano(nombre));
                    return jugadores[jugadores.size() - 1];
            }
        } while(opcion != 1 and opcion != 2);
    }
    return nullptr;
}

void juegoNuevo(string dificultad, Jugador* jugadorActivo) {

    Juego *juego = new Juego(jugadorActivo);

    if(dificultad == "facil") {
        juego->inicializarFacil();
    } else if (dificultad == "intermedio") {
        juego -> inicializarMedio();
    } else if (dificultad == "dificil") {
        juego -> inicializarDificil();
    } else if (dificultad == "personalizado") {
        juego -> inicializarPersonalizado();
    }

    juego->jugar();

    delete juego;
}

void juegoAutomaticoNuevo(string dificultad, JugadorAutomatico* jugadorAutomatico) {

    Juego *juego = new Juego(jugadorAutomatico);

    if(dificultad == "facil") {
        juego->inicializarFacil();
    } else if (dificultad == "intermedio") {
        juego -> inicializarMedio();
    } else if (dificultad == "dificil") {
        juego -> inicializarDificil();
    } else if (dificultad == "personalizado") {
        juego -> inicializarPersonalizado();
    }

    jugadorAutomatico->setTableroActual(juego->getTablero());

    juego->jugar();

    delete juego;
}

int main() {

    srand(time(nullptr));

    int opcionMenu, opcionMenuConfiguracion, opcionDificultadJuego, opcionHistorial;

    vector<Jugador*> jugadores;

    Jugador *jugadorActivo = nullptr;

    JugadorAutomatico *jugadorAutomatico = new JugadorAutomatico();

    inicializarJugadores(jugadores);

    do {
        imprimirMenu("menu");
        cin >> opcionMenu;
        limpiar();
        switch(opcionMenu) {
            case 1:
                do {
                    imprimirMenu("tableros");
                    cin >> opcionDificultadJuego;
                    limpiar();
                    switch(opcionDificultadJuego) {
                        case 1:
                            jugadorActivo = seleccionarJugador(jugadores);
                            juegoNuevo("facil", jugadorActivo);
                            break;
                        case 2:
                            jugadorActivo = seleccionarJugador(jugadores);
                            juegoNuevo("intermedio", jugadorActivo);
                            break;
                        case 3:
                            jugadorActivo = seleccionarJugador(jugadores);
                            juegoNuevo("dificil", jugadorActivo);
                            break;
                        case 4:
                            jugadorActivo = seleccionarJugador(jugadores);
                            juegoNuevo("personalizado", jugadorActivo);
                            break;
                    }
                } while(opcionDificultadJuego != 5);
                break;
            case 2:
                do {
                    imprimirMenu("tableros");
                    cin >> opcionDificultadJuego;
                    limpiar();
                    switch(opcionDificultadJuego) {
                        case 1:
                            juegoAutomaticoNuevo("facil", jugadorAutomatico);
                            break;
                        case 2:
                            juegoAutomaticoNuevo("intermedio", jugadorAutomatico);
                            break;
                        case 3:
                            juegoAutomaticoNuevo("dificil", jugadorAutomatico);
                            break;
                        case 4:
                            juegoAutomaticoNuevo("personalizado", jugadorAutomatico);
                            break;
                    }
                } while(opcionDificultadJuego != 5);
                break;
            case 3:
                do {
                    imprimirHistorialPartidas();
                    imprimirJugadores(jugadores);
                    imprimirMenu("historial");
                    cin >> opcionHistorial;
                    limpiar();
                } while (opcionHistorial != 1);

                break;
            case 4:
                do {
                    imprimirMenu("config");
                    cin >> opcionMenuConfiguracion;
                    limpiar();
                    switch(opcionMenuConfiguracion) {
                        case 1:
                            permitirColores = !permitirColores;
                            break;
                        case 2:
                            permitirLimpiar = !permitirLimpiar;
                            break;
                    }
                } while(opcionMenuConfiguracion != 3);
                break;
        }
    } while(opcionMenu != 5);

    for(auto jugador : jugadores) {
        delete jugador;
    }

    delete jugadorAutomatico;

    return 0;
}
