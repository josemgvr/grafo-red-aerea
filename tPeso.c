//
// Created by jmvil on 27/04/2026.
//

#include <stdio.h>
#include "tPeso.h"
#include "string.h"

void asignarElemento(tPeso* e1, tPeso e2) {
    e1->precio = e2.precio;
    e1->tiempo = e2.tiempo;
    strcpy(e1->compañia, e2.compañia);
}

void crearElemento(char compañia[MAX_COM], int tiempo, int precio, tPeso* e) {
    e->precio = precio;
    e->tiempo = tiempo;
    strcpy(e->compañia, compañia);

}
int igualElemento(tPeso uno, tPeso dos) {
    return uno.precio == dos.precio && uno.tiempo == dos.tiempo && strcmp(uno.compañia, dos.compañia);
}
void mostrarElemento(tPeso t) {
    printf("Precio: %d \n", t.precio);
    printf("Tiempo: %d \n", t.tiempo);
    printf("Compañia: ");
    puts(t.compañia);
    printf("\n");
}