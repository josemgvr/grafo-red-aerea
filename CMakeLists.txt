cmake_minimum_required(VERSION 3.5)
project(Practica C)

set(CMAKE_C_STANDARD 11)

add_executable(Practica
        main.c
        tGrafo.c
        tListaAdyacencia.c
        tVertice.c
        tPeso.c
        UsosGrafo.c
        UsosGrafo.h
        tConjunto.c
        tConjunto.h)

configure_file(vuelos.txt vuelos.txt COPYONLY)