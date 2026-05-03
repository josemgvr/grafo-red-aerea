/*********************************************************************************
Módulo:         tCola
Fichero:        ( ) Programa  (x) Espec. TAD  ( ) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          03/05/2026
Descripción:
    Este fichero define la especificación del TAD tCola, que implementa una cola
    FIFO de vértices (tVertice) mediante una lista enlazada con puntero al primero
    y al último. La cola se utiliza como estructura auxiliar en el recorrido en
    anchura (BFS) del grafo. Se proporcionan las operaciones de creación,
    comprobación de vacío, inserción al final, consulta del primero y eliminación
    del primero de la cola.
**********************************************************************************/

#ifndef PRACTICA_TCOLA_H
#define PRACTICA_TCOLA_H
#include "tVertice.h"

typedef struct Nodo_Cola {
    tVertice info;
    struct Nodo_Cola *sig;
} tNodo_Cola;

typedef struct {
    tNodo_Cola *primero;
    tNodo_Cola *ultimo;
} tCola;

void CrearColaVacia(tCola *cola);
int EsColaVacia(tCola cola);
void InsertarCola(tCola *cola, tVertice v);
void PrimeroCola(tCola cola, tVertice *v);
void Eliminar_vertice_cola(tCola *cola);



#endif //PRACTICA_TCOLA_H
