//
// Created by jm.villora.2025 on 29/04/2026.
//

#include "UsosGrafo.h"
#include "tGrafo.h"
#include "tListaAdyacencia.h"
#include "tConjunto.h"
#include "tVertice.h"
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

    while (aux != NULL && !igualVertice(aux->ciudad, v)) {
        aux = aux->sig;
    }

    if (aux != NULL) {
        tVertice v2;
        char nothing[MAX_CIU] = "nothing";
        tVertice nothing_v;
        tConjunto c_primer_destino, c_ultimo_destino;
        CrearConjuntoVacio(&c_primer_destino);
        CrearConjuntoVacio(&c_ultimo_destino);
        crearVertice(nothing, &nothing_v);
        guardar_vertices (aux->ady,&c_primer_destino);

        if (!EsConjuntoVacio(c_primer_destino)) {
            while (!igualVertice(nothing_v, v2)) {
                obtenerPrimeroConjunto(&c_primer_destino,&v2);
                aux = g;

                while (aux != NULL && !igualVertice(aux->ciudad, v2)) {
                    aux = aux->sig;
                }
                if (aux != NULL) {
                    guardar_vertices (aux->ady, &c_ultimo_destino);
                }
            }
            if (!EsConjuntoVacio(c_ultimo_destino)) {
                printf("Posibles destinos haciendo una escala: \n");
                mostrarConjunto(c_ultimo_destino);
            } else {
                printf("Puedes ir a otras ciudades, pero estas en estas no puedes hacer escala \n");
            }

        } else {
            printf("No hay posibles destinos en los que hacer la escala \n");
        }

    } else {
        printf("No hay posibles destinos haciendo una escala \n");
    }
}

int consultar_trayecto_entre_ciudades(tGrafo g, tVertice v1, tVertice v2) {
    struct NodoLista *aux = g;
    int pertenece = 0;


    while (aux != NULL && !igualVertice(aux->ciudad, v1)) {
        aux = aux->sig;
    }

    if (aux != NULL) {
      pertenece = perteneceLista_vertice(aux->ady, v2);

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
