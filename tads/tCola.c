/********************************************************************************
Módulo:         tCola
Fichero:        ( ) Programa  ( ) Espec. TAD  (x) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          03/05/2026
Descripción:
    Este fichero implementa el TAD tCola, que representa una cola FIFO de vértices
    (tVertice) con punteros al primer y al último nodo. La cola se emplea como
    estructura auxiliar en el recorrido en anchura (BFS) del grafo de la red aérea.
    En este módulo se desarrollan las operaciones de creación, comprobación de
    vacío, inserción al final de la cola, consulta del primer elemento y
    eliminación del primero, gestionando la memoria dinámica mediante malloc y free.
*********************************************************************************/

#include "tCola.h"
#include <stdio.h>
#include <stdlib.h>

void CrearColaVacia(tCola *cola) {
    cola->primero = NULL;
    cola->ultimo = NULL;
}
int EsColaVacia(tCola cola) {
    return cola.primero == NULL && cola.ultimo == NULL;
}
void InsertarCola(tCola *cola, tVertice v) {
    tNodo_Cola *aux = cola->primero;
    tNodo_Cola *new = (tNodo_Cola*) malloc(sizeof(tNodo_Cola));

    asignarVertice(&new->info, v);

    if (aux != NULL) {
        new->sig = NULL;
        cola->ultimo->sig = new;
        cola->ultimo = new;
    } else {
        new->sig = NULL;
        cola->ultimo = new;
        cola->primero = new;
    }
}

void PrimeroCola(tCola cola, tVertice *v) {
    if (!EsColaVacia(cola)) {
        asignarVertice(v, cola.primero->info);
    }
}

void Eliminar_vertice_cola(tCola *cola) {
    if (!EsColaVacia(*cola)) {
        struct Nodo_Cola *aux = cola->primero;
        if (aux->sig != NULL) {
            cola->primero = aux->sig;
        } else {
           CrearColaVacia(cola);
        }
       free(aux);
    }
}
