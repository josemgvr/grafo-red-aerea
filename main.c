#include <stdio.h>
#include <string.h>
#include "tGrafo.h"
#include "tVertice.h"
#include "tPeso.h"
#include "tListaAdyacencia.h"

void quitarCaracteresFinales_Ciudades(char cadena[MAX_CIU]);
void quitarCaracteresFinales_Compañia(char cadena[MAX_COM]);
int main(void) {
    int seleccion;
    int fcontrol = 1;
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
            insertarArista(&g, v1, v2, peso);
        }


       do {
           printf("Seleciona que opcion desea realizar: \n");
           printf("1- Consultar las destinos de una ciudad \n");
           printf("2- Comprobar que el grafo es conexo \n");
           printf("3- Consultar los destinos de una ciudad haciendo una escala \n");
           printf("4- Comprobar si es posible ir a dos ciudades sin hacer escala \n");
           printf("5- Analizar si existe alguna ciudad fuente y/o sumidero \n");
           printf("6- Identificar el trayecto con un número mayor de compañias \n");
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
                   break;
               case 3:
                   break;
               case 4:
                   break;
               case 5:
                   break;
               case 6:
                   break;
               case 7:
                   break;
               case 8:
                   break;
               case 0:
                   printf("Hasta pronto! \n");
                   break;
                   default: printf("Error: no has seleccionado una operacion valida. Intentelo de nuevo \n");
           }

           scanf(" %d", &seleccion);

       } while (seleccion != 0);



   } else {
       printf("Error al abrir el archivo");
   }

    if (fclose(pFichero) != 0) {
        printf("Error al cerrar el fichero");
    }





}

void quitarCaracteresFinales_Compañia(char cadena[MAX_COM]) {
    cadena[strlen(cadena)-1] = '\0';
}

void quitarCaracteresFinales_Ciudades(char cadena[MAX_CIU]) {
    cadena[strlen(cadena)-1] = '\0';
}