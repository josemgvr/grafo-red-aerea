/********************************************************************************
Módulo:         Main
Fichero:        (x) Programa  ( ) Espec. TAD  ( ) Impl. TAD
Autor:          Jose Miguel Villora
Fecha:          27/04/2026
Descripción:
    Programa principal de la práctica de grafos. Lee el fichero vuelos.txt y
    construye el grafo de la red aérea europea insertando los vértices (ciudades)
    y las aristas (vuelos) con su correspondiente peso (compañía, tiempo y precio).
    Una vez cargado el grafo, presenta al usuario un menú interactivo con el que
    puede realizar las siguientes consultas: destinos directos desde una ciudad,
    comprobación de conectividad del grafo, destinos con una escala, existencia
    de vuelo directo entre dos ciudades, ciudades fuente y sumidero, trayecto con
    mayor número de compañías, trayectos más caros/baratos y más lentos/rápidos.
*********************************************************************************/

#include <stdio.h>
#include <string.h>
#include "tGrafo.h"
#include "tVertice.h"
#include "tPeso.h"
#include "tListaAdyacencia.h"
#include "UsosGrafo.h"

void quitarCaracteresFinales_Ciudades(char cadena[MAX_CIU]);
void quitarCaracteresFinales_Compañia(char cadena[MAX_COM]);
int main(void) {
    int seleccion;
    int fcontrol = 1;
    int verdadero = 0;
    tGrafo g;
    tVertice v1, v2;;
    tPeso peso;

    char ciudad[MAX_CIU];
    char destino[MAX_CIU];
    char compañia[MAX_CIU];
    int tiempo, precio;

    FILE *pFichero;
    CrearGrafoVacio(&g);
    printf("Cargando: leyendo los datos...\n");

   if ( (pFichero = fopen("vuelos.txt","r")) != NULL) {

        while (fcontrol != EOF) {
            fcontrol = fscanf(pFichero," %s" , ciudad);
            fcontrol = fscanf(pFichero," %s" , destino);
            fcontrol = fscanf(pFichero," %s" , compañia);
            fcontrol = fscanf(pFichero," %d" , &tiempo);
            fcontrol = fscanf(pFichero," %d" , &precio);



            crearVertice(ciudad, &v1);
            crearVertice(destino,&v2);
            crearPeso(compañia,tiempo,precio,&peso);
            insertarVertice(&g, v1);
            insertarVertice(&g, v2);
            insertarArista(&g, v1, v2, peso);
        }


       do {
           printf("Seleciona que opcion desea realizar: \n");
           printf("1- Consultar las destinos de una ciudad \n");
           printf("2- Comprobar que el grafo es conexo \n");
           printf("3- Consultar los destinos de una ciudad haciendo una escala \n");
           printf("4- Comprobar si es posible ir a dos ciudades sin hacer escala \n");
           printf("5- Analizar si existe alguna ciudad fuente y/o sumidero \n");
           printf("6- Identificar el trayecto con un numero mayor de companias \n");
           printf("7- Identificar el trayecto mas caro y el mas barato \n");
           printf("8- Identificar el trayecto mas lento y el mas rapido\n");
           printf("0- Salir\n \n");
           fflush(stdin);
           scanf(" %d", &seleccion);

           switch (seleccion) {
               case 1:
                   printf("Ingrese la ciudad que desea visitar \n");
                   fflush(stdin);
                   gets(ciudad);
                   crearVertice(ciudad, &v1);
                   consultar_destinos(g, v1);
                   break;
               case 2:
                   Comprobar_Grafo_Conexo(g);
                   break;
               case 3:
                   printf("Ingrese la ciudad que desea comprobar a que ciudades puedes vistar haciendo una escala \n");
                   fflush(stdin);
                   gets(ciudad);
                   crearVertice(ciudad, &v1);
                   consultar_destinos_1escala(g, v1);


                   break;
               case 4:
                   fflush(stdin);
                   printf("Ingrese la ciudad de origen \n");
                   gets(ciudad);
                   asignarVertice(ciudad, &v1);

                   printf("Ingrese la ciudad de destino \n");
                   gets(destino);
                   asignarVertice(destino, &v2);
                   verdadero = consultar_trayecto_entre_ciudades(g,v1,v2);
                   if (verdadero) {
                       printf("Existe un trayecto entre las dos ciudades \n");
                   } else {
                       printf("NO hay un trayecto entre las dos ciudades \n");
                   }
                   break;
               case 5:
                   Consultar_ciudad_sumidero_y_fuente(g);
                   break;
               case 6:
                   Consular_Trayecto_mas_companyias(g);
                   break;
               case 7:
                   int caro = 0;

                   printf("Ingrese 0 si desea ver el mas barato o un 1 si desea el mas caro \n");
                   fflush(stdin);
                   scanf(" %d", &caro);

                   switch (caro) {
                       case 0: consultar_trayecto_mas_barato(g);
                           break;
                       case 1: consultar_trayecto_mas_caro(g);
                           break;
                       default: printf("Has ingresado un número incorrecto, intentelo de nuevo \n");
                   }

                   break;
               case 8:
                   int largo = 0;

                   printf("Ingrese 0 si desea ver el mas corto o un 1 si desea el mas largo \n");
                   fflush(stdin);
                   scanf(" %d", &largo);

                   switch (largo) {
                       case 0: consultar_trayecto_mas_corto(g);
                           break;
                       case 1: consultar_trayecto_mas_largo(g);
                           break;
                       default: printf("Has ingresado un número incorrecto, intentelo de nuevo \n");
                   }
                   break;
               case 0:
                   printf("Hasta pronto! \n");
                   break;
                   default: printf("Error: no has seleccionado una operacion valida. Intentelo de nuevo \n");
           }
           if (seleccion !=0) {
               printf("Introduzca cualquier valor para continuar \n");
               scanf(" %d", &seleccion);
               seleccion = 1; //para evitar que se seleccione el 0 y salga del programa
           }

       } while (seleccion != 0);

   } else {
       printf("Error al abrir el archivo");
   }

    if (fclose(pFichero) != 0) {
        printf("Error al cerrar el fichero");
    }
}

