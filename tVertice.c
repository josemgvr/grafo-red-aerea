/********************************************************************************
Módulo:         tVertice
Fichero:        ( ) Programa  ( ) Espec. TAD  (x) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          28/04/2026
Descripción:
    Este fichero implementa el TAD tVertice, que representa un vértice del grafo
    de la red aérea, identificado por el nombre de una ciudad europea. En este
    módulo se desarrollan las operaciones de creación, asignación, comparación
    e impresión por pantalla de un tVertice, haciendo uso de las funciones de
    manejo de cadenas de la librería estándar de C.
*********************************************************************************/

#include <stdio.h>
#include <string.h>
#include "tVertice.h"

void asignarVertice(tVertice* e1, tVertice e2) {
    strcpy(*e1, e2);
}
void crearVertice(char ciudad[MAX_CIU], tVertice* e) {
    strcpy(*e,ciudad);
}
int igualVertice(tVertice uno, tVertice dos) {
    return strcmp(uno,dos) == 0;
}
void mostraVertice (tVertice t) {
    printf("Ciudad: ");
    puts(t);
}