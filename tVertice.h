//
// Created by jmvil on 28/04/2026.
//

#ifndef PRACTICA_TVERTICE_H
#define PRACTICA_TVERTICE_H

#define MAX_CIU 50

typedef char tVertice[MAX_CIU];

void asignarVertice(tVertice* e1, tVertice e2);
void crearVertice(char ciudad[MAX_CIU], tVertice* e); //TElemento crearElemento(int num);
int igualVertice(tVertice uno, tVertice dos);
void mostraVertice (tVertice t);

#endif //PRACTICA_TVERTICE_H