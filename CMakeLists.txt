cmake_minimum_required(VERSION 3.28)
project(minesweeper)

set(CMAKE_CXX_STANDARD 17)

add_executable(minesweeper main.cpp
        Casilla.cpp
        Casilla.h
        Tablero.cpp
        Tablero.h
        Juego.cpp
        Juego.h
        ConsoleManager.cpp
        ConsoleManager.h
        Jugador.cpp
        Jugador.h
        JugadorHumano.cpp
        JugadorHumano.h
        JugadorAutomatico.cpp
        JugadorAutomatico.h
        HistorialManager.cpp
        TimeManager.cpp
        TimeManager.h
        HistorialManager.h
)
