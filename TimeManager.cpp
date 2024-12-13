#include <iostream>
#include <ctime>

using namespace std;

//Añade un cero para el formato
string ceroPorDelante(int x) {
    if(x < 10) { return "0" + to_string(x); }
    return to_string(x);
}

//Toma el tiempo actual en segundos
int tomarTiempo() {
    time_t tiempoActual = time(nullptr);
    return static_cast<int>(tiempoActual);
}

string traducirTiempo(int tiempo, bool acortado) {
    string tiempoString;
    //time_t es esencialmente un int que cuenta los segundos desde 01/01/1970
    time_t tiempoConvertido = tiempo;
    tm* tiempoTraducido = localtime(&tiempoConvertido);
    //time_t tiene localtime(...), que retorna un puntero a std::tm con info detallada sobre la fecha
    //con std::tm, es posible obtener cada componente individual (años, meses, segundos)

    //Si acortado==true, mostrar solo hh:mm:ss
    if(acortado) {
        tiempoString = ceroPorDelante(tiempoTraducido->tm_hour-19) + ":"
                + ceroPorDelante(tiempoTraducido->tm_min) + ":"
                + ceroPorDelante(tiempoTraducido->tm_sec);
    }

    //Por otra parte, mostrar DD-MM-YYYY hh:mm:ss
    else {
        tiempoString = ceroPorDelante(tiempoTraducido->tm_mday) + "-"
        + ceroPorDelante(tiempoTraducido->tm_mon+1) + "-" //Los meses van del 0-11
        + ceroPorDelante(tiempoTraducido->tm_year+1900) + "   " //Los años inician de 0 = 1970
        + ceroPorDelante(tiempoTraducido->tm_hour) + ":"
        + ceroPorDelante(tiempoTraducido->tm_min) + ":"
        + ceroPorDelante(tiempoTraducido->tm_sec);
    }

    return tiempoString;
}