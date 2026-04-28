//
// Created by jmvil on 28/04/2026.
//

#include <stdio.h>
#include <string.h>
#include "tVertice.h"

void asignarVertice(tVertice* e1, tVertice e2) {
    strcpy(e1,e2);
}
void crearVertice(char ciudad[MAX_CIU], tVertice* e) {
    strcpy(e,ciudad);
}
int igualVertice(tVertice uno, tVertice dos) {
    return strcmp(uno,dos);
}
void mostraVertice (tVertice t) {
    printf("Ciudad ");
    puts(t);
    printf("\n");
}