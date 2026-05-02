/********************************************************************************
Módulo:         tListaAdyacencia
Fichero:        ( ) Programa  ( ) Espec. TAD  (x) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          27/04/2026
Descripción:
    Este fichero implementa el TAD tListaAdyacencia, que representa la lista
    dinámica de adyacencia asociada a cada ciudad del grafo de la red aérea.
    Cada nodo de la lista almacena un vértice de destino (tVertice) y el peso
    de la arista correspondiente (tPeso). En este módulo se desarrollan las
    operaciones de inserción al principio, eliminación, pertenencia, longitud,
    obtención de extremos, asignación, comparación, destrucción y visualización
    de la lista, gestionando la memoria dinámica mediante malloc y free.
*********************************************************************************/

#include <stdlib.h>
#include "tListaAdyacencia.h"
#include <stdio.h>
#include "tVertice.h"
#include "tGrafo.h"
#include "tConjunto.h"

void CrearListaVacia(tListaAdy *l) {
    *l = NULL;
}

int EsListaVacia(tListaAdy l) {
    return l == NULL;
}

void insertarArista_lady(tListaAdy *l,tVertice v ,tPeso peso) {
    //Por comodidad lo insertarmos al principio
        struct NodoAdy *new = (struct NodoAdy*)malloc(sizeof(struct NodoAdy));
        asignarVertice( &(new->ciudad), v);
        asignarPeso(&(new->info), peso);
        new->sig = *l;
        *l = new;

}


void obtenerPrimeroLista(tListaAdy l, tVertice* v, tPeso *peso) {
    if (!EsListaVacia(l)) {
        asignarVertice(v,l->ciudad);
        asignarPeso(peso,l->info);
    }
}


void obtenerultimoLista(tListaAdy l, tVertice* v, tPeso *peso) {
    struct NodoAdy *act = l;
    struct NodoAdy *ant = NULL;

    while (act != NULL) {
        ant = act;
        act = act->sig;
    }

    if (ant != NULL) {
        asignarVertice(v, ant->ciudad);
        asignarPeso(peso,ant->info);
    }
}

int longitudLista (tListaAdy l) {
    int longitud = 0;
    struct NodoAdy *aux = l;

    while (aux != NULL) {
        longitud++;
        aux = aux->sig;
    }

    return longitud;
}
int perteneceLista (tVertice v, tPeso peso, tListaAdy l) {
    int pertenece = 0;
    struct NodoAdy *aux = l;

    while (aux != NULL && !pertenece) {
        if (igualVertice(v, aux->ciudad) && igualPeso(peso, aux->info)) {
            pertenece = 1;
        }
        aux = aux->sig;
    }
    return pertenece;
}

int perteneceLista_vertice(tListaAdy l, tVertice v) {
    int pertenece = 0;
    struct NodoAdy *aux = l;

    while (aux != NULL && !pertenece) {
        if (igualVertice(v, aux->ciudad)) {
            pertenece = 1;
        }
        aux = aux->sig;
    }
    return pertenece;
}

void eliminarElementoLista(tListaAdy *l,  tVertice v, tPeso peso) {
    if (!EsListaVacia(*l) && perteneceLista(v, peso, *l)) {
        struct NodoAdy *act = *l;
        struct NodoAdy *ant = NULL;
        while (act != NULL && !igualVertice(v, act->ciudad) && !igualPeso(peso, act->info)) {
            ant = act;
            act = act->sig;
        }

        if (act != NULL) {
            if (ant != NULL) {
                ant->sig = act->sig;
            } else {
                *l = act->sig;
            }
            free(act);
        }
    }
}

int logitudLista (tListaAdy l) {
    struct NodoAdy *aux = l;
    int longitud = 0;
    while (aux != NULL) {
        longitud++;
        aux = aux->sig;
    }
    return longitud;
}

int igualLista (tListaAdy l1, tListaAdy l2) {
    struct NodoAdy *aux1 = l1;
    struct NodoAdy *aux2 = l2;
    int igual = 1;

    while (aux1 != NULL && aux2 != NULL) {
        if (!igualVertice(aux1->ciudad, aux2->ciudad) && !igualPeso(aux1->info, aux2->info)) {
            igual = 0;
        }
        aux1 = aux1->sig;
        aux2 = aux2->sig;
    }

    if (aux1 != NULL || aux2 != NULL) {
        igual = 0;
    }
    return igual;
}


void asignarLista (tListaAdy original, tListaAdy *copia) {
    struct NodoAdy *aux = original;
    tListaAdy aux_lady;
    CrearListaVacia(&aux_lady);

    while (aux != NULL) {
        insertarArista_lady(&aux_lady, aux->ciudad, aux->info);
        aux = aux->sig;
    }
    aux = aux_lady;

    while (aux != NULL) {
        insertarArista_lady(copia, aux->ciudad, aux->info);
        aux = aux->sig;
    }
    destruirLista(&aux_lady);
}

void destruirLista(tListaAdy *l) {
    struct NodoAdy *aux = *l;
    while (aux != NULL) {
        aux = *l;
        if (aux != NULL) {
            eliminarElementoLista(l, aux->ciudad, aux->info);
        }
    }
}

void mostrarLista(tListaAdy l) {
    struct NodoAdy *aux = l;
    int i = 0;
    printf("Ciudades que se pueden visitar: \n");

    if (aux == NULL) {
        printf("No hay ciudades posibles a las que se pueda visitar desde esta ciudad \n");
    }
    while (aux != NULL) {
        printf("%d- \n", i+1);
        printf("Ciudad: ");
        mostrarVertice(aux->ciudad);
        printf("\n");
        mostraPeso(aux->info);
        i++;
        aux = aux->sig;
    }
}

void guardar_vertices(tListaAdy l, tConjunto *c) {
    struct NodoAdy *aux = l;
    tVertice v;
    while (aux != NULL) {
        asignarVertice(&v, aux->ciudad);
        poner(c, v);
        aux = aux->sig;
    }
}

void getpeso_aristas (tListaAdy *l, tPeso* peso) {
    if (!EsListaVacia(*l)) {
        asignarPeso(peso,(*l)->info);
        eliminarElementoLista(l, (*l)->ciudad, (*l)->info);
    } else {
        crearPeso("nothing",0,0,peso);
    }

}

void buscarVertice_aristas(tListaAdy l, tPeso peso, tVertice *v) {
    struct NodoAdy *aux = l;
    while (aux != NULL && igualPeso(aux->info, peso)) {
        aux = aux->sig;
    }

    if (aux != NULL) {
        asignarVertice(v,aux->ciudad);
    }
}

void obtener_vertice_lista(tListaAdy l, int pos, tVertice *v) {
    int i;
    struct NodoAdy *aux = l;
    for (i = 0; i < pos; i++) {
        aux = aux->sig;
    }
    asignarVertice(v,aux->ciudad);
}

int obtener_numero_companias(tListaAdy l, tVertice v) {
    int cantidad = 0;
    if (!EsListaVacia(l)) {
        struct NodoAdy *aux = l;
        while (aux != NULL) {
            if (igualVertice(aux->ciudad, v)) {
                cantidad++;
            }
            aux = aux->sig;
        }
    }
    return cantidad;
}


/*
int obtener_numero_companyias(tListaAdy l) {
    int numero = 0;
    if (EsListaVacia(l)) {
        //Como solamente en este ejercio necesiamos un Conjunto para pesos, lo creare aqui
        typedef struct Nodo_Conjunto_Peso {
            tPeso info;
            struct Nodo_Conjunto_Peso *sig;
        } tNodo_Conjunto_Peso;

        typedef struct Nodo_Conjunto_Peso *tConjunto_Peso;

        struct NodoAdy *aux_l = l;
        tNodo_Conjunto_Peso *aux_p = NULL;
        tNodo_Conjunto_Peso *peso_new = (tNodo_Conjunto_Peso *)malloc(sizeof(tNodo_Conjunto_Peso));
        tConjunto_Peso conjunto = NULL;
        int pertenece = 0;

        asignarPeso(&peso_new->info,aux_l->info);
        peso_new->sig = conjunto;
        conjunto = peso_new;
        aux_p = conjunto;
        aux_l = aux_l->sig;
        numero++;

        while (aux_l != NULL) {
            pertenece = 0;
            tNodo_Conjunto_Peso *peso_new = (tNodo_Conjunto_Peso *)malloc(sizeof(tNodo_Conjunto_Peso));

            while (aux_p != NULL) {
                if (igualPeso_Compania(aux_p->info, aux_p->info)) {
                    pertenece = 1;
                }
                aux_p = aux_p->sig;
            }

            if (!pertenece) {
                asignarPeso(&peso_new->info,aux_l->info);
                peso_new->sig = conjunto;
                conjunto = peso_new;
                numero++;
            }
                aux_l = aux_l->sig;
        }
    }
    return numero;

}
*/