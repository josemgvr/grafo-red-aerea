//
// Created by jm.villora.2025 on 29/04/2026.
//

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
int pertenece(tConjunto c, tVertice v);
void poner(tConjunto *c, tVertice v);

#endif //TCONJUNTO_H
