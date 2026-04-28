//
// Created by jmvil on 27/04/2026.
//

#ifndef PRACTICA_TLISTAADYACENCIA_H
#define PRACTICA_TLISTAADYACENCIA_H

#include "tPeso.h"
#include "tVertice.h"
typedef  struct NodoAdy {
    tVertice ciudad;
    tPeso info;
    struct NodoAdy *sig;
};

typedef struct NodoAdy* tListaAdy;

void CrearListaVacia(tListaAdy *l);
int EsListaVacia(tListaAdy l);
void insertarArista_lady(tListaAdy *l,tVertice ,tPeso peso);

void obtenerPrimeroLista(tListaAdy l, tVertice* v, tPeso *peso);;
void obtenerultimoLista(tListaAdy l, tVertice* v, tPeso *peso);

int longitudLista (tListaAdy l);
int perteneceLista (tVertice v, tPeso peso, tListaAdy l);

void eliminarElementoLista(tListaAdy *l,  tVertice v, tPeso peso);

int igualLista (tListaAdy l1, tListaAdy l2);
void asignarLista (tListaAdy original, tListaAdy *copia);
void destruirLista(tListaAdy *l);
void mostrarLista(tListaAdy l);

#endif //PRACTICA_TLISTAADYACENCIA_H
