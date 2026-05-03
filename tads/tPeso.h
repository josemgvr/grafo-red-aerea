/********************************************************************************
Módulo:         tPeso
Fichero:        ( ) Programa  (x) Espec. TAD  ( ) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          27/04/2026
Descripción:
    Este fichero define la especificación del TAD tPeso, que representa el peso
    de una arista en el grafo de la red aérea. Un peso encapsula la información
    asociada a un vuelo concreto entre dos ciudades: la compañía aérea que opera
    el trayecto, la duración del vuelo en minutos y el precio del billete en euros.
    Se proporcionan las operaciones básicas de creación, asignación, comparación
    y visualización del TAD.
*********************************************************************************/

#ifndef PRACTICA_TPESO_H
#define PRACTICA_TPESO_H

#define MAX_COM 50

typedef struct {
    char compañia[MAX_COM];
    int tiempo;
    int precio;
} tPeso;

int EsPesoVacio(tPeso p);
void asignarPeso(tPeso* e1, tPeso e2);
void crearPeso(char compañia[MAX_COM], int tiempo, int precio, tPeso* e); //TElemento crearElemento(int num);
int igualPeso(tPeso uno, tPeso dos);
void mostraPeso(tPeso t);

int igualPeso_Compania(tPeso p1, tPeso p2);
int EsMayor_Primero_Tiempo(tPeso t1, tPeso t2);
int EsMenor_Primero_Tiempo(tPeso t1, tPeso t2);
int EsMayor_Primero_Dinero(tPeso t1, tPeso t2);
int EsMenor_Primero_Dinero(tPeso t1, tPeso t2);

#endif //PRACTICA_TPESO_H