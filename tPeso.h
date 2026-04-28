//
// Created by jmvil on 27/04/2026.
//

#ifndef PRACTICA_TPESO_H
#define PRACTICA_TPESO_H

#define MAX_COM 50

typedef struct {
    char compañia[MAX_COM];
    int tiempo;
    int precio;
} tPeso;

void asignarPeso(tPeso* e1, tPeso e2);
void crearPeso(char compañia[MAX_COM], int tiempo, int precio, tPeso* e); //TElemento crearElemento(int num);
int igualPeso(tPeso uno, tPeso dos);
void mostraPeso(tPeso t);


#endif //PRACTICA_TPESO_H