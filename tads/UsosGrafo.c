/*********************************************************************************
Módulo:         UsosGrafo
Fichero:        ( ) Programa  ( ) Espec. TAD  (x) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          29/04/2026
Descripción:
    Este fichero implementa el módulo UsosGrafo, que contiene las funciones de
    consulta de alto nivel utilizadas desde el programa principal. Las funciones
    acceden directamente a la estructura interna del TAD tGrafo para realizar las
    siguientes operaciones: consulta de destinos directos desde una ciudad, destinos
    alcanzables con una escala, comprobación de vuelo directo entre dos ciudades,
    identificación de ciudades fuente y sumidero, búsqueda del trayecto con mayor
    número de compañías operando, y obtención de los trayectos más caros, baratos,
    rápidos y lentos. Además, implementa la comprobación de conectividad del grafo
    lanzando un BFS desde cada vértice y comparando el conjunto de nodos visitados
    con el conjunto total de ciudades.
**********************************************************************************/

#include "UsosGrafo.h"

#include <math.h>

#include "tGrafo.h"
#include "tListaAdyacencia.h"
#include "tConjunto.h"
#include "tVertice.h"
#include <stdio.h>

void consultar_destinos(tGrafo g, tVertice v) {
    struct NodoLista *aux = g;

    while (aux != NULL && !igualVertice(aux->ciudad, v)) {
        aux = aux->sig;
    }

    if (aux != NULL) {
        mostrarLista(aux->ady);
    } else {
        printf("No se ha encontrado la ciudad \n");
    }
}


void consultar_destinos_1escala(tGrafo g, tVertice v) {
    struct NodoLista *aux = g;

    while (aux != NULL && !igualVertice(aux->ciudad, v)) {
        aux = aux->sig;
    }

    if (aux != NULL) {
        tVertice v2;
        char nothing[MAX_CIU] = "nothing";
        tVertice nothing_v;
        tConjunto c_primer_destino, c_ultimo_destino;
        CrearConjuntoVacio(&c_primer_destino);
        CrearConjuntoVacio(&c_ultimo_destino);
        crearVertice(nothing, &nothing_v);
        guardar_vertices (aux->ady,&c_primer_destino);

        if (!EsConjuntoVacio(c_primer_destino)) {
            while (!igualVertice(nothing_v, v2)) {
                obtenerPrimeroConjunto(&c_primer_destino,&v2);
                aux = g;

                while (aux != NULL && !igualVertice(aux->ciudad, v2)) {
                    aux = aux->sig;
                }
                if (aux != NULL) {
                    guardar_vertices (aux->ady, &c_ultimo_destino);
                }
            }
            if (!EsConjuntoVacio(c_ultimo_destino)) {
                printf("Posibles destinos haciendo una escala: \n");
                mostrarConjunto(c_ultimo_destino);
            } else {
                printf("Puedes ir a otras ciudades, pero estas en estas no puedes hacer escala \n");
            }

        } else {
            printf("No hay posibles destinos en los que hacer la escala \n");
        }

    } else {
        printf("No hay posibles destinos haciendo una escala \n");
    }
}

int consultar_trayecto_entre_ciudades(tGrafo g, tVertice v1, tVertice v2) {
    struct NodoLista *aux = g;
    int pertenece = 0;


    while (aux != NULL && !igualVertice(aux->ciudad, v1)) {
        aux = aux->sig;
    }

    if (aux != NULL) {
      pertenece = perteneceLista_vertice(aux->ady, v2);

    } else {
        printf("No se ha encontrado la ciudad de origen, intentelo de nuevo \n");
    }

    return pertenece;

}





void consultar_trayecto_mas_barato(tGrafo g) {
    tGrafo g_copia;
    CrearGrafoVacio(&g_copia);
    asignarGrafo(&g_copia,g);

    struct NodoLista *aux = g_copia;

    if (aux != NULL) {
        tPeso peso1, peso2;
        int EsMenor = 0;

        getpeso_aristas(&aux->ady, &peso1);
        getpeso_aristas(&aux->ady, &peso2);

        if (!EsPesoVacio(peso1) && !EsPesoVacio(peso2)) {
            EsMenor = EsMenor_Primero_Dinero(peso1, peso2);

            //Suponemos que no hay precios que sean iguales
            if (!EsMenor) {
                asignarPeso(&peso1, peso2);
            }

            while (aux != NULL) {
                while (!EsListaVacia(aux->ady)) {
                    getpeso_aristas(&aux->ady, &peso2);

                    if (!EsPesoVacio(peso2)) {
                        //Suponemos que no hay precios que sean iguales
                        EsMenor = EsMenor_Primero_Dinero(peso1, peso2);
                        if (!EsMenor) {
                            asignarPeso(&peso1, peso2);
                        }
                    }
                }
                aux = aux->sig;

            }
        } else {
            tVertice v;
            asignarVertice(&v, aux->ciudad);
            EliminarVertice(&g_copia, v);
            consultar_trayecto_mas_barato(g_copia);
        }

        if (!EsPesoVacio(peso1)) {
            printf("El trayecto mas barato es el de: \n");
            mostraPeso(peso1);

        }


    } else {
        printf("No hay trayectos disponbles \n");
    }

}

//Para la opcion 7 y 8, es el mismo codigo pero cambia el nombre de algunas variables y la llamada de algunas funciones.
//Pero funciona todo practicamente igual

void consultar_trayecto_mas_caro(tGrafo g) {
    tGrafo g_copia;
    CrearGrafoVacio(&g_copia);
    asignarGrafo(&g_copia,g);

    struct NodoLista *aux = g_copia;

    if (aux != NULL) {
        tPeso peso1, peso2;
        int EsMayor = 0;

        getpeso_aristas(&aux->ady, &peso1);
        getpeso_aristas(&aux->ady, &peso2);

        if (!EsPesoVacio(peso1) && !EsPesoVacio(peso2)) {
            EsMayor = EsMayor_Primero_Dinero(peso1, peso2);

            //Suponemos que no hay precios que sean iguales
            if (!EsMayor) {
                asignarPeso(&peso1, peso2);
            }

            while (aux != NULL) {
                while (!EsListaVacia(aux->ady)) {
                    getpeso_aristas(&aux->ady, &peso2);

                    if (!EsPesoVacio(peso2)) {
                        //Suponemos que no hay precios que sean iguales
                        EsMayor = EsMayor_Primero_Dinero(peso1, peso2);
                        if (!EsMayor) {
                            asignarPeso(&peso1, peso2);
                        }
                    }
                }
                aux = aux->sig;

            }
        } else {
            tVertice v;
            asignarVertice(&v, aux->ciudad);
            EliminarVertice(&g_copia, v);
            consultar_trayecto_mas_caro(g_copia);
        }

        if (!EsPesoVacio(peso1)) {
            printf("El trayecto mas caro es el de: \n");
            mostraPeso(peso1);

        }


    } else {
        printf("No hay trayectos disponbles \n");
    }
}
void consultar_trayecto_mas_corto(tGrafo g) {
    tGrafo g_copia;
    CrearGrafoVacio(&g_copia);
    asignarGrafo(&g_copia,g);

    struct NodoLista *aux = g_copia;

    if (aux != NULL) {
        tPeso peso1, peso2;
        int EsCorto = 0;

        getpeso_aristas(&aux->ady, &peso1);
        getpeso_aristas(&aux->ady, &peso2);

        if (!EsPesoVacio(peso1) && !EsPesoVacio(peso2)) {
            EsCorto = EsMenor_Primero_Tiempo(peso1, peso2);

            //Suponemos que no hay precios que sean iguales
            if (!EsCorto) {
                asignarPeso(&peso1, peso2);
            }

            while (aux != NULL) {
                while (!EsListaVacia(aux->ady)) {
                    getpeso_aristas(&aux->ady, &peso2);

                    if (!EsPesoVacio(peso2)) {
                        //Suponemos que no hay precios que sean iguales
                        EsCorto = EsMenor_Primero_Tiempo(peso1, peso2);
                        if (!EsCorto) {
                            asignarPeso(&peso1, peso2);
                        }
                    }
                }
                aux = aux->sig;

            }
        } else {
            tVertice v;
            asignarVertice(&v, aux->ciudad);
            EliminarVertice(&g_copia, v);
            consultar_trayecto_mas_corto(g_copia);
        }

        if (!EsPesoVacio(peso1)) {
            printf("El trayecto mas corto es el de: \n");
            mostraPeso(peso1);

        }


    } else {
        printf("No hay trayectos disponbles \n");
    }
}

void consultar_trayecto_mas_largo(tGrafo g) {
    tGrafo g_copia;
    CrearGrafoVacio(&g_copia);
    asignarGrafo(&g_copia,g);

    struct NodoLista *aux = g_copia;

    if (aux != NULL) {
        tPeso peso1, peso2;
        int EsLargo = 0;

        getpeso_aristas(&aux->ady, &peso1);
        getpeso_aristas(&aux->ady, &peso2);

        if (!EsPesoVacio(peso1) && !EsPesoVacio(peso2)) {
            EsLargo = EsMayor_Primero_Tiempo(peso1, peso2);

            //Suponemos que no hay precios que sean iguales
            if (!EsLargo) {
                asignarPeso(&peso1, peso2);
            }

            while (aux != NULL) {
                while (!EsListaVacia(aux->ady)) {
                    getpeso_aristas(&aux->ady, &peso2);

                    if (!EsPesoVacio(peso2)) {
                        //Suponemos que no hay precios que sean iguales
                        EsLargo = EsMayor_Primero_Tiempo(peso1, peso2);
                        if (!EsLargo) {
                            asignarPeso(&peso1, peso2);
                        }
                    }
                }
                aux = aux->sig;

            }
        } else {
            tVertice v;
            asignarVertice(&v, aux->ciudad);
            EliminarVertice(&g_copia, v);
            consultar_trayecto_mas_largo(g_copia);
        }

        if (!EsPesoVacio(peso1)) {
            printf("El trayecto mas largo es el de: \n");
            buscarVertice_aristas(&g_copia);
            mostraPeso(peso1);

        }


    } else {
        printf("No hay trayectos disponbles \n");
    }
}

void Consular_Trayecto_mas_companyias(tGrafo g) {

    if (!EsGrafoVacio(g)) {
        struct NodoLista *act = g;
        struct NodoLista *mayor = NULL;
        int cantidad_guardada = 0, cantidad_actual = 0;
        int pos, longitud;
        tVertice v_actual, v_guardado;

        while (act != NULL) {
            longitud = longitudLista(act->ady);
            for (pos = 0; pos < longitud; pos++) {
                obtener_vertice_lista(act->ady, pos, &v_actual);
                cantidad_actual = obtener_numero_companias(act->ady, v_actual);
                if (cantidad_actual > cantidad_guardada) {
                        cantidad_guardada = cantidad_actual;
                        asignarVertice(&v_guardado, v_actual);
                        mayor = act;
                }
            }
            act = act->sig;
        }

        printf("El numero mayor de campanias es de %d entre: \n", cantidad_guardada);
        mostrarVertice(mayor->ciudad);
        printf(" hacia \n");
        mostrarVertice(v_guardado);;

    } else {
        printf("Error: no hay ningun trayecto guardado \n");
    }
}
void Consultar_ciudad_sumidero_y_fuente(tGrafo g) {
    struct NodoLista *aux = g;
    int longitud = 0;
    tVertice v;

    //Suponemos que es un grafo conexo
    printf("Las ciudades fuentes son: \n");
    while (aux != NULL) {
        longitud = longitudLista(aux->ady);
        if (longitud > 0) {
            mostrarVertice(aux->ciudad);
        }
        aux = aux->sig;
    }
    printf("\n");

    aux = g;
    printf("Las ciudades sumidero son: \n");
    while (aux != NULL) {
        longitud = longitudLista(aux->ady);
        if (longitud == 0) {
            mostrarVertice(aux->ciudad);
        }
        aux = aux->sig;
    }
    printf("\n");
}

void Comprobar_Grafo_Conexo(tGrafo g) {
    struct NodoLista *act = g;

    tConjunto ciudades;
    tConjunto NodosVisitados;
    tGrafo g_aux;
    tVertice v_act, v_prim;
    tListaAdy l_act, l_prim;
    int longitud = 0, EsConexo = 0;
    int i,j;

    CrearConjuntoVacio(&ciudades);
    CrearConjuntoVacio(&NodosVisitados);
    CrearListaVacia(&l_act);
    CrearListaVacia(&l_prim);

    while (act != NULL) {
        poner(&ciudades,act->ciudad);
        longitud++;
        act = act->sig;
    }

    asignarGrafo(&g_aux, g);
    act = g_aux;


    for (i = 0; i < longitud; i++) {
        act = g_aux;
        CrearConjuntoVacio(&NodosVisitados);
        CrearListaVacia(&l_act);
        CrearListaVacia(&l_prim);

        for (j = 0; j < i; j++) {
            act = act->sig;
        }

        asignarVertice(&v_prim, g_aux->ciudad);
        asignarVertice(&v_act, act->ciudad);

        asignarLista(g_aux->ady, &l_prim);
        asignarLista(act->ady, &l_act);

        asignarVertice(&g_aux->ciudad, v_act);
        asignarVertice(&act->ciudad, v_prim);

        asignarLista(l_act, &g_aux->ady);
        asignarLista(l_prim, &act->ady);

        RecorridoEnAnchura(g_aux,&NodosVisitados);

        if (EsIgualConjunto(NodosVisitados, ciudades)) {
            EsConexo++;
        }
    }
    if (EsConexo == longitud) {
        printf("Es fuertemente conexo \n");
    } else if (EsConexo > 0) {
        printf("Es debilemente conexo \n");
    } else {
        printf("No es conexo \n");
    }
}