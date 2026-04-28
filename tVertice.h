/********************************************************************************
Módulo:         tVertice
Fichero:        ( ) Programa  (x) Espec. TAD  ( ) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          28/04/2026
Descripción:
    Este fichero define la especificación del TAD tVertice, que representa un
    vértice del grafo de la red aérea, es decir, una ciudad europea. Un vértice
    se almacena como una cadena de caracteres con el nombre de la ciudad. Se
    proporcionan las operaciones básicas de creación, asignación, comparación
    y visualización del TAD.
*********************************************************************************/

#ifndef PRACTICA_TVERTICE_H
#define PRACTICA_TVERTICE_H

#define MAX_CIU 50

typedef char tVertice[MAX_CIU];

void asignarVertice(tVertice* e1, tVertice e2);
void crearVertice(char ciudad[MAX_CIU], tVertice* e); //TElemento crearElemento(int num);
int igualVertice(tVertice uno, tVertice dos);
void mostraVertice (tVertice t);

#endif //PRACTICA_TVERTICE_H