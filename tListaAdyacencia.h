//
// Created by jmvil on 27/04/2026.
//

#ifndef PRACTICA_TLISTAADYACENCIA_H
#define PRACTICA_TLISTAADYACENCIA_H

#include "tPeso.h"
#include "tVertice.h"
typedef  struct NodoAdy {
    tVertice Ciudad;
    tPeso info;
    struct NodoAdy *sig;
};

typedef struct NodoAdy* tListaAdy;

void insertarArista_lady(tListaAdy *l,tVertice v ,tPeso peso);

#endif //PRACTICA_TLISTAADYACENCIA_H