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
void asignarConjunto(tConjunto c1, tConjunto *c2) {
    CrearConjuntoVacio(c2);
    if (!EsConjuntoVacio(c1)) {
        tNodoConjunto *act = c1;
        tVertice v;
        while (act != NULL) {
            asignarVertice(&v, act->info);
            poner(c2, v);
            act = act->sig;
        }
    }


}
int pertenece(tConjunto c, tVertice v) {
    int pertenece = 0;

    if (!EsConjuntoVacio(c)) {
        tNodoConjunto * aux = c;
        while (aux != NULL && !igualVertice(aux->info, v)) {
            aux = aux->sig;
        }
        if (aux != NULL) {
            pertenece = 1;
        }
    }
    return pertenece;
}

void poner(tConjunto *c, tVertice v) {
    if (!pertenece(*c, v)) {
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
        while (act != NULL && !igualVertice(act->info, v)) {
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

void obtenerPrimeroConjunto(tConjunto *c, tVertice *v) {
    if (!EsConjuntoVacio(*c)) {
        tNodoConjunto *aux = *c;
        asignarVertice(v,aux->info);
        Quitar(c,*v);
    } else {
        tVertice v2;
        char nothing[MAX_CIU] = "nothing";
        crearVertice(nothing,&v2);
        asignarVertice(v,v2);
    }
}

void mostrarConjunto(tConjunto c) {
    tNodoConjunto *aux = c;
    while (aux != NULL) {
        mostrarVertice (aux->info);
        aux = aux->sig;
    }
}
