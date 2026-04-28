//
// Created by jmvil on 27/04/2026.
//
#include <stdlib.h>
#include "tGrafo.h"

#include <stdio.h>


void CrearGrafoVacio(tGrafo *g) {
    *g = NULL;
}

int EsGrafoVacio(tGrafo g) {
   return  g == NULL;
}

int perteneceGrafo (tGrafo g, tVertice v) {
    struct NodoLista *aux = g;

    while (aux != NULL && !igualVertice(aux->ciudad, v)) {
        aux = aux->sig;
    }

    return aux != NULL;
}


void insertarArista(tGrafo *g, tVertice v1, tVertice v2, tPeso peso) {
    //El vertice v1 es para buscar si se encuentra en el grafo la ciudad y v2 es el destino que deseas insertar
    struct NodoLista *aux = *g;

    while (aux != NULL && !igualVertice(aux->ciudad, v1)) {
        aux = aux->sig;
    }

    if (aux != NULL) {
        insertarArista_lady(aux->ady, v2, peso);
    }  else {
        printf("No se ha podido insertar el destino, debido a que no se ha registrado la ciudad de origen \n");
    }

}

void insertarVertice (tGrafo *g, tVertice v) { //InsertarCiudad
    if (!perteneceGrafo(*g,v)) {
        struct NodoLista *aux = (struct NodoLista *)malloc(sizeof(struct NodoLista));

        asignarVertice(&aux->ciudad, v);
        CrearListaVacia(&aux->ady);
        aux->sig = *g;
        *g = aux;

    }
}

void EliminarVertice (tGrafo *g, tVertice v) {
    struct NodoLista *act = *g;
    struct NodoLista *ant = NULL;

    while (act != NULL && !igualVertice(act->ciudad, v)) {
        ant = act;
        act = act->sig;
    }

    if (act != NULL) {
        if (ant ==NULL ) {
            *g = act->sig;
        } else {
            ant->sig = act->sig;
        }
        destruirLista(&act->ady);
        free(act);
    } else {
        printf("No se ha podido encontrar la ciudad que desea eliminar \n");
    }
}

void MostrarGrafo(tGrafo g) {
    printf("Los siguientes vuelos  \n");

}