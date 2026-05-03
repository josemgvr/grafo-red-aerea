/*********************************************************************************
Módulo:         tConjunto
Fichero:        ( ) Programa  ( ) Espec. TAD  (x) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          29/04/2026
Descripción:
    Este fichero implementa el TAD tConjunto, que representa un conjunto dinámico
    de vértices (tVertice) sin elementos repetidos, basado en una lista enlazada.
    Se emplea como estructura auxiliar en el recorrido en anchura (BFS) del grafo
    para llevar el control de los nodos visitados. En este módulo se desarrollan
    las operaciones de creación, comprobación de vacío, pertenencia, inserción sin
    duplicados, eliminación, obtención del primer elemento, asignación (copia),
    comparación de igualdad entre conjuntos y visualización por pantalla,
    gestionando la memoria dinámica mediante malloc y free.
**********************************************************************************/

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

int EsIgualConjunto (tConjunto c1, tConjunto c2) {
    struct NodoConjunto *aux = c1;
    tVertice v;
    int igual = 1;

    while (aux != NULL) {
        asignarVertice(&v,aux->info);
        if (!pertenece(c2,v)) {
            igual = 0;
        }
        aux = aux->sig;
    }

    if (igual) {
        aux = c2;
        while (aux != NULL) {
            asignarVertice(&v,aux->info);
            if (!pertenece(c1,v)) {
                igual = 0;
            }
            aux = aux->sig;
        }
    }

return igual;
}
