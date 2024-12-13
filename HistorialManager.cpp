#include "HistorialManager.h"

void imprimirHistorialPartidas() {

    ifstream archivo("historial.txt");
    string linea;

    if (archivo.is_open()) {

        cout << "--- HISTORIAL DE PARTIDAS ---" << endl;
        cout << setw(20) << "NOMBRE" << setw(30) << "TIEMPO DE INICIO" << setw(15) << "DURACION" << setw(15) << "RESULTADO" << endl;

        while (getline(archivo, linea)) {

            stringstream ss(linea);

            string jugador;
            char resultado;
            int tiempoInicio;
            int duracion;

            getline(ss, jugador, '|');
            ss >> resultado;
            ss.ignore();
            ss >> tiempoInicio;
            ss.ignore();
            ss >> duracion;

            cout << setw(20) << jugador << setw(30) << traducirTiempo(tiempoInicio, false) << setw(15) << traducirTiempo(duracion, true) << setw(15) << (resultado == 'w' ? "VICTORIA" : "DERROTA") << endl;

        }

        archivo.close(); // Cerrar el archivo

    } else {
        cout << "ERROR AL ABRIR EL HISTORIAL" << endl;
    }

}

void inicializarJugadores(vector<Jugador*> &jugadores) {

    ifstream archivo("historial.txt");
    string linea;

    if (archivo.is_open()) {

        while (getline(archivo, linea)) {

            bool jugadorInJugadores = false;

            stringstream ss(linea);

            string nombreJugador;
            char resultado;

            getline(ss, nombreJugador, '|');
            ss >> resultado;

            for(auto jugador : jugadores) {
                if(nombreJugador == jugador->getNombre()) {
                    jugadorInJugadores = true;
                    jugador->setPartidasJugadas(jugador->getPartidasJugadas() + 1);
                    if (resultado == 'w') {
                        jugador->setVictorias(jugador->getVictorias() + 1);
                    } else {
                        jugador->setDerrotas(jugador->getDerrotas() + 1);
                    }
                }
            }

            if(!jugadorInJugadores and nombreJugador != "Jugador Automatico") {
                Jugador *nuevoJugador = new JugadorHumano(nombreJugador);
                nuevoJugador->setPartidasJugadas(1);
                if(resultado == 'w') {
                    nuevoJugador->setVictorias(1);
                } else {
                    nuevoJugador->setDerrotas(1);
                }
                jugadores.emplace_back(nuevoJugador);
            }
        }

        archivo.close(); // Cerrar el archivo

    }

}

// SOBRECARGA AL OPERADOR << PARA IMPRIMIR LOS DATOS DE UN JUGADOR
ostream& operator<<(ostream &stream, Jugador* jugador) {
    stream << setw(20) << jugador->getNombre() << setw(20) << jugador->getPartidasJugadas() << setw(20) << jugador->getVictorias() << setw(20) << jugador->getDerrotas();
    return stream;
}

void imprimirJugadores(const vector<Jugador*> &jugadores) {
    if(!jugadores.empty()) {
        cout << "--- LISTA DE JUGADORES ---" << endl;
        cout << setw(20) << "NOMBRE" << setw(20) << "PARTIDAS JUGADAS" << setw(20) << "VICTORIAS" << setw(20) << "DERROTAS" << endl;
        for(int i = 0; i < jugadores.size(); i++) {
            cout << jugadores[i] << endl;
        }
    } else {
        cout << "NO SE ENCONTRARON JUGADORES" << endl;
    }
}