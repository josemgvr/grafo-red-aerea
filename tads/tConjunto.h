/*********************************************************************************
Módulo:         tConjunto
Fichero:        ( ) Programa  (x) Espec. TAD  ( ) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          29/04/2026
Descripción:
    Este fichero define la especificación del TAD tConjunto, que representa un
    conjunto dinámico de vértices (tVertice) sin elementos repetidos, implementado
    mediante una lista enlazada. El conjunto se utiliza como estructura auxiliar
    en el recorrido en anchura (BFS) para registrar los nodos ya visitados y
    evitar ciclos. Se proporcionan las operaciones de creación, comprobación de
    vacío, pertenencia, inserción, eliminación, obtención del primero, asignación,
    comparación de igualdad y visualización.
**********************************************************************************/

#ifndef TCONJUNTO_H
#define TCONJUNTO_H

#include "tVertice.h"

typedef struct NodoConjunto {
    tVertice info;
    struct NodoConjunto *sig;
} tNodoConjunto;

typedef tNodoConjunto * tConjunto;

void CrearConjuntoVacio(tConjunto *c);
int EsConjuntoVacio(tConjunto c);
void asignarConjunto(tConjunto c1, tConjunto *c2);
int pertenece(tConjunto c, tVertice v);
void poner(tConjunto *c, tVertice v);
void Quitar(tConjunto *c, tVertice v);
void obtenerPrimeroConjunto(tConjunto *c, tVertice *v);
void mostrarConjunto(tConjunto c);


#endif //TCONJUNTO_H
