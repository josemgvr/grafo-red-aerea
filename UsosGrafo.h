//
// Created by jm.villora.2025 on 29/04/2026.
//

#ifndef USOSGRAFO_H
#define USOSGRAFO_H

#include "tGrafo.h"

//Funciones utilizadas en el main

void consultar_destinos(tGrafo g, tVertice v);
void consultar_destinos_1escala(tGrafo g, tVertice v);

void consultar_trayecto_mas_barato(tGrafo g);
void consultar_trayecto_mas_caro(tGrafo g);
void consultar_trayecto_mas_corto(tGrafo g);
void consultar_trayecto_mas_largo(tGrafo g);

#endif //USOSGRAFO_H
