cmake_minimum_required(VERSION 4.0)
project(Practica C)

set(CMAKE_C_STANDARD 11)

add_executable(Practica main.c
        tGrafo.c
        tGrafo.h
        tListaAdyacencia.c
        tListaAdyacencia.h
        tPeso.c
        tPeso.h
        tPeso.h
        tVertice.c
        tVertice.h)
