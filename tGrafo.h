//
// Created by jmvil on 27/04/2026.
//

#ifndef PRACTICA_TGRAFO_H
#define PRACTICA_TGRAFO_H
#include "tVertice.h"
#include "tListaAdyacencia.h"

struct NodoLista {
    tVertice ciudad;
    struct NodoLista *sig;
    struct NodoAdy *ady;
};

typedef struct NodoLista *tGrafo;

void CrearGrafoVacio(tGrafo *g);
int EsGrafoVacio(tGrafo g);
int perteneceGrafo (tGrafo g, tVertice v);
void insertarArista(tGrafo *g, tVertice v1, tVertice v2, tPeso peso);
void insertarVertice (tGrafo *g, tVertice v); //InsertarCiudad
void EliminarVertice (tGrafo *g, tVertice v); //EliminarCiudad
void MostrarGrafo(tGrafo g);
void RecorridoEnAnchura(tGrafo *g); //Aun falta implementarlo

//Funciones utilizadas en el main

void consultar_destinos(tGrafo g, tVertice v);

void consultar_trayecto_mas_barato(tGrafo g);
void consultar_trayecto_mas_caro(tGrafo g);
void consultar_trayecto_mas_corto(tGrafo g);
void consultar_trayecto_mas_largo(tGrafo g);


#endif //PRACTICA_TGRAFO_H