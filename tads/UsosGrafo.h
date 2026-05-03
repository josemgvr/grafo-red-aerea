/*********************************************************************************
Módulo:         UsosGrafo
Fichero:        ( ) Programa  (x) Espec. TAD  ( ) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          29/04/2026
Descripción:
    Este fichero define la especificación del módulo UsosGrafo, que agrupa las
    funciones de consulta de alto nivel sobre el grafo de la red aérea. Estas
    funciones rompen intencionalmente el encapsulamiento del TAD tGrafo para
    acceder directamente a la estructura interna y dar soporte al menú del
    programa principal. Se incluyen consultas de destinos directos, destinos con
    una escala, trayectos directos entre dos ciudades, ciudades fuente y sumidero,
    trayecto con mayor número de compañías, y trayectos extremos en precio
    y duración. También se incluye la comprobación de conectividad del grafo
    mediante recorridos en anchura desde cada vértice.
**********************************************************************************/
 

#ifndef USOSGRAFO_H
#define USOSGRAFO_H

#include "tGrafo.h"

//Funciones utilizadas en el main

void consultar_destinos(tGrafo g, tVertice v);
void consultar_destinos_1escala(tGrafo g, tVertice v);

void Consular_Trayecto_mas_companyias(tGrafo g);

void consultar_trayecto_mas_barato(tGrafo g);
void consultar_trayecto_mas_caro(tGrafo g);
void consultar_trayecto_mas_corto(tGrafo g);
void consultar_trayecto_mas_largo(tGrafo g);
void Consultar_ciudad_sumidero_y_fuente(tGrafo g);
#endif //USOSGRAFO_H
