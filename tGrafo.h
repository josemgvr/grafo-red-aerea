//
// Created by jmvil on 27/04/2026.
//

#ifndef PRACTICA_TGRAFO_H
#define PRACTICA_TGRAFO_H
#include "tVertice.h"
#include "tListaAdyacencia.h"

typedef struct NodoLista {
    tVertice ciudad;
    struct Nodo *sig;
    struct NodoAdy *ady;
};

typedef struct NodoLista *tGrafo;

void CrearGrafoVacio(tGrafo *g);
void 
void insertarArista(tGrafo *g, tVertice v1, tVertice v2, tPeso peso);

#endif //PRACTICA_TGRAFO_H