/********************************************************************************
Módulo:         tGrafo
Fichero:        ( ) Programa  (x) Espec. TAD  ( ) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          27/04/2026
Descripción:
    Este fichero define la especificación del TAD tGrafo, que representa un grafo
    dirigido y ponderado implementado mediante una lista enlazada de nodos. Cada
    nodo almacena una ciudad (tVertice) y su lista de adyacencia (tListaAdy), que
    contiene los vuelos que parten desde dicha ciudad. Se proporcionan las
    operaciones de creación, inserción y eliminación de vértices y aristas,
    pertenencia, visualización, asignación y recorrido en anchura del grafo.
*********************************************************************************/

#ifndef PRACTICA_TGRAFO_H
#define PRACTICA_TGRAFO_H
#include "tVertice.h"
#include "tListaAdyacencia.h"

struct NodoLista {
    tVertice ciudad;
    struct NodoLista *sig;
    struct NodoAdy *ady;
};

typedef struct NodoLista *tGrafo;

void CrearGrafoVacio(tGrafo *g);
int EsGrafoVacio(tGrafo g);
int perteneceGrafo (tGrafo g, tVertice v);
void insertarArista(tGrafo *g, tVertice v1, tVertice v2, tPeso peso);
void insertarVertice (tGrafo *g, tVertice v); //InsertarCiudad
void EliminarVertice (tGrafo *g, tVertice v); //EliminarCiudad
void MostrarGrafo(tGrafo g);
void asignarGrafo(tGrafo* g1, tGrafo g2);
void RecorridoEnAnchura(tGrafo g, tConjunto *visitados);

#endif //PRACTICA_TGRAFO_H