/********************************************************************************
Módulo:         tListaAdyacencia
Fichero:        ( ) Programa  ( ) Espec. TAD  (x) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          27/04/2026
Descripción:
    Este fichero implementa el TAD tListaAdyacencia, que representa la lista
    dinámica de adyacencia asociada a cada ciudad del grafo de la red aérea.
    Cada nodo de la lista almacena un vértice de destino (tVertice) y el peso
    de la arista correspondiente (tPeso). En este módulo se desarrollan las
    operaciones de inserción al principio, eliminación, pertenencia, longitud,
    obtención de extremos, asignación, comparación, destrucción y visualización
    de la lista, gestionando la memoria dinámica mediante malloc y free.
*********************************************************************************/

#include <stdlib.h>
#include "tListaAdyacencia.h"
#include <stdio.h>
#include "tVertice.h"
#include "tGrafo.h"

void CrearListaVacia(tListaAdy *l) {
    *l = NULL;
}

int EsListaVacia(tListaAdy l) {
    return l == NULL;
}

void insertarArista_lady(tListaAdy *l,tVertice v ,tPeso peso) {
    struct NodoAdy *aux = *l;

    while (aux != NULL && !igualVertice(aux->ciudad, v)) {
        aux = aux->sig;
    }

    //Por comodidad lo insertarmos al principio
    if (aux == NULL) {
        struct NodoAdy *new = (struct NodoAdy*)malloc(sizeof(struct NodoAdy));
        asignarVertice( &(new->ciudad), v);
        asignarPeso(&(new->info), peso);
        new->sig = *l;
        *l = new;
    }
}


void obtenerPrimeroLista(tListaAdy l, tVertice* v, tPeso *peso) {
    if (!EsListaVacia(l)) {
        asignarVertice(v,l->ciudad);
        asignarPeso(peso,l->info);
    }
}


void obtenerultimoLista(tListaAdy l, tVertice* v, tPeso *peso) {
    struct NodoAdy *act = l;
    struct NodoAdy *ant = NULL;

    while (act != NULL) {
        ant = act;
        act = act->sig;
    }

    if (ant != NULL) {
        asignarVertice(v, ant->ciudad);
        asignarPeso(peso,ant->info);
    }
}

int longitudLista (tListaAdy l) {
    int longitud = 0;
    struct NodoAdy *aux = l;

    while (aux != NULL) {
        longitud++;
        aux = aux->sig;
    }

    return longitud;
}
int perteneceLista (tVertice v, tPeso peso, tListaAdy l) {
    int pertenece = 0;
    struct NodoAdy *aux = l;

    while (aux != NULL && !pertenece) {
        if (igualVertice(v, aux->ciudad) && igualPeso(peso, aux->info)) {
            pertenece = 1;
        }
        aux = aux->sig;
    }
    return pertenece;
}


void eliminarElementoLista(tListaAdy *l,  tVertice v, tPeso peso) {
    if (!EsListaVacia(*l) && perteneceLista(v, peso, *l)) {
        struct NodoAdy *act = *l;
        struct NodoAdy *ant = NULL;
        while (act != NULL && !igualVertice(v, act->ciudad) && !igualPeso(peso, act->info)) {
            ant = act;
            act = act->sig;
        }

        if (act != NULL) {
            if (ant != NULL) {
                ant->sig = act->sig;
            } else {
                *l = act->sig;
            }
            free(act);
        }
    }
}

int igualLista (tListaAdy l1, tListaAdy l2) {
    struct NodoAdy *aux1 = l1;
    struct NodoAdy *aux2 = l2;
    int igual = 1;

    while (aux1 != NULL && aux2 != NULL) {
        if (!igualVertice(aux1->ciudad, aux2->ciudad) && !igualPeso(aux1->info, aux2->info)) {
            igual = 0;
        }
        aux1 = aux1->sig;
        aux2 = aux2->sig;
    }

    if (aux1 != NULL || aux2 != NULL) {
        igual = 0;
    }
    return igual;
}


void asignarLista (tListaAdy original, tListaAdy *copia) {
    struct NodoAdy *aux = original;
    tListaAdy aux_lady;
    CrearListaVacia(&aux_lady);

    while (aux != NULL) {
        insertarArista_lady(&aux_lady, aux->ciudad, aux->info);
        aux = aux->sig;
    }
    aux = aux_lady;

    while (aux != NULL) {
        insertarArista_lady(copia, aux->ciudad, aux->info);
        aux = aux->sig;
    }
    destruirLista(&aux_lady);
}

void destruirLista(tListaAdy *l) {
    struct NodoAdy *aux = *l;
    while (aux != NULL) {
        struct NodoAdy *aux = *l;
        eliminarElementoLista(l, aux->ciudad, aux->info);
    }
}

void mostrarLista(tListaAdy l) {
    struct NodoAdy *aux = l;
    int i = 0;
    printf("Ciudades que se pueden visitar: \n");

    if (aux == NULL) {
        printf("No hay ciudades posibles a las que se pueda visitar desde esta ciudad \n");
    }
    while (aux != NULL) {
        printf("%d- \n", i+1);
        mostraVertice(aux->ciudad);
        mostraPeso(aux->info);
        i++;
        aux = aux->sig;
    }
}

