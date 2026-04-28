/********************************************************************************
Módulo:         tPeso
Fichero:        ( ) Programa  ( ) Espec. TAD  (x) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          27/04/2026
Descripción:
    Este fichero implementa el TAD tPeso, que representa el peso asociado a cada
    arista del grafo de la red aérea. Cada peso almacena la compañía aérea, el
    tiempo de vuelo en minutos y el precio del billete en euros. En este módulo
    se desarrollan las operaciones de creación, asignación, comparación e
    impresión por pantalla de un tPeso.
*********************************************************************************/

#include <stdio.h>
#include "tPeso.h"
#include "string.h"

void asignarPeso(tPeso* e1, tPeso e2) {
    e1->precio = e2.precio;
    e1->tiempo = e2.tiempo;
    strcpy(e1->compañia, e2.compañia);
}

void crearPeso(char compañia[MAX_COM], int tiempo, int precio, tPeso* e) {
    e->precio = precio;
    e->tiempo = tiempo;
    strcpy(e->compañia, compañia);

}
int igualPeso(tPeso uno, tPeso dos) {
    return uno.precio == dos.precio && uno.tiempo == dos.tiempo && strcmp(uno.compañia, dos.compañia);
}
void mostraPeso(tPeso t) {
    printf("Precio: %d \n", t.precio);
    printf("Tiempo: %d \n", t.tiempo);
    printf("Compañia: ");
    puts(t.compañia);
    printf("\n");
}