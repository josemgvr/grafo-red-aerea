//
// Created by jm.villora.2025 on 29/04/2026.
//

#include "tConjunto.h"
#include <stdio.h>
#include <stdlib.h>

void CrearConjuntoVacio(tConjunto *c) {
    *c = NULL;
}

int EsConjuntoVacio(tConjunto c) {
    return c == NULL;
}

int pertenece(tConjunto c, tVertice v) {
    int pertenece = 0;

    if (!EsConjuntoVacio(c)) {
        tNodoConjunto * aux = c;
        while (aux != NULL && igualVertice(aux->info, v)) {
            aux = aux->sig;
        }
        if (aux != NULL) {
            pertenece = 1;
        }
    }
    return pertenece;
}

void poner(tConjunto *c, tVertice v) {
    if (!EsConjuntoVacio(*c) && !pertenece(*c, v)) {
        tNodoConjunto *new = (tNodoConjunto*)malloc(sizeof(tNodoConjunto));
        asignarVertice(&new->info, v);
        new->sig = *c;
        *c = new;
    }
}

void Quitar(tConjunto *c, tVertice v) {
    if (!EsConjuntoVacio(*c) && pertenece(*c, v)) {
        tNodoConjunto *act = *c;
        tNodoConjunto *ant = NULL;
        while (act != NULL && igualVertice(act->info, v)) {
            ant = act;
            act = act->sig;
        }

        if (ant == NULL) {
            *c = act->sig;
        } else {
            ant->sig = act->sig;
        }
        free(act);
    }
}
