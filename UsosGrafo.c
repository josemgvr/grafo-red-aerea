//
// Created by jm.villora.2025 on 29/04/2026.
//

#include "UsosGrafo.h"
#include "tGrafo.h"
#include "tListaAdyacencia.h"
#include <stdio.h>

//Funciones utilizadas en el main, rompemos el encapsulado


void consultar_destinos(tGrafo g, tVertice v) {
    struct NodoLista *aux = g;

    while (aux != NULL && !igualVertice(aux->ciudad, v)) {
        aux = aux->sig;
    }

    if (aux != NULL) {
        mostrarLista(aux->ady);
    } else {
        printf("No se ha encontrado la ciudad \n");
    }
}


void consultar_destinos_1escala(tGrafo g, tVertice v) {
    struct NodoLista *aux = g;
    tVertice v2;

    while (aux != NULL && !igualVertice(aux->ciudad, v)) {
        aux = aux->sig;
    }

    if (aux != NULL) {
        struct NodoAdy *aux_lady = aux->ady;
        printf("Posibles destinos haciendo una escala: \n");
        while (aux_lady != NULL) {

            asignarVertice(&v2,aux_lady->ciudad);
            consultar_destinos(g,v);
            aux_lady = aux_lady->sig;
        }

    } else {
        printf("No hay posibles destinos haciendo una escala \n");
    }
}

int consultar_trayecto_entre_ciudades(tGrafo g, tVertice v1, tVertice v2) {
    struct NodoLista *aux = g;
    int pertenece = 0;
    tVertice v;

    while (aux != NULL && !igualVertice(aux->ciudad, v1)) {
        aux = aux->sig;
    }

    if (aux != NULL) {


    } else {
        printf("No se ha encontrado la ciudad de origen, intentelo de nuevo \n");
    }

    return pertenece;

}





void consultar_trayecto_mas_barato(tGrafo g) {
    struct NodoLista *aux = g;

    while (aux != NULL) {

    }

}



void consultar_trayecto_mas_caro(tGrafo g);
void consultar_trayecto_mas_corto(tGrafo g);
void consultar_trayecto_mas_largo(tGrafo g);
