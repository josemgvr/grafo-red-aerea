/********************************************************************************
Módulo:         tListaAdyacencia
Fichero:        ( ) Programa  (x) Espec. TAD  ( ) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          27/04/2026
Descripción:
    Este fichero define la especificación del TAD tListaAdyacencia, que representa
    la lista de adyacencia asociada a cada vértice del grafo de la red aérea. Cada
    nodo de la lista almacena una ciudad de destino (tVertice) y la información del
    vuelo que conecta con ella (tPeso). La lista es dinámica y enlazada. Se
    proporcionan las operaciones de creación, inserción, eliminación, consulta,
    recorrido y destrucción de la lista.
*********************************************************************************/

#ifndef PRACTICA_TLISTAADYACENCIA_H
#define PRACTICA_TLISTAADYACENCIA_H

#include "tPeso.h"
#include "tVertice.h"
struct NodoAdy {
    tVertice ciudad;
    tPeso info;
    struct NodoAdy *sig;
};

typedef struct NodoAdy* tListaAdy;

void CrearListaVacia(tListaAdy *l);
int EsListaVacia(tListaAdy l);
void insertarArista_lady(tListaAdy *l,tVertice v,tPeso peso);

void obtenerPrimeroLista(tListaAdy l, tVertice* v, tPeso *peso);;
void obtenerultimoLista(tListaAdy l, tVertice* v, tPeso *peso);

int longitudLista (tListaAdy l);
int perteneceLista (tVertice v, tPeso peso, tListaAdy l);

void eliminarElementoLista(tListaAdy *l,  tVertice v, tPeso peso);

int igualLista (tListaAdy l1, tListaAdy l2);
void asignarLista (tListaAdy original, tListaAdy *copia);
void destruirLista(tListaAdy *l);
void mostrarLista(tListaAdy l);

//Funciones necesarias para resolver el main
void mostrarLista_1escala(tListaAdy l);

#endif //PRACTICA_TLISTAADYACENCIA_H
