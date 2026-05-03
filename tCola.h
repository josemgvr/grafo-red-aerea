//
// Created by Usuario on 03/05/2026.
//

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
