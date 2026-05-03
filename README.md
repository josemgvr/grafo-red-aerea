# ✈️ Red Aérea Europea — Práctica de Grafos 

> **Asignatura:** Estructura de Datos · Grado en Ingeniería Informática · URJC  
> **Lenguaje:** C  
> **Estructura principal:** Grafo dirigido y ponderado con listas de adyacencia

---

## 📋 Descripción

Modelado de una red aérea europea mediante un **grafo dinámico, dirigido y ponderado**. El programa carga la información de los vuelos desde un fichero de texto y permite al usuario realizar distintas consultas sobre la red a través de un menú interactivo.

Cada vuelo entre dos ciudades queda representado como una **arista del grafo** con tres pesos asociados:

| Campo    | Descripción                     |
|----------|---------------------------------|
| Compañía | Aerolínea que opera el trayecto |
| Tiempo   | Duración del vuelo (en minutos) |
| Precio   | Coste del billete (en euros)    |

Las **ciudades** son los vértices del grafo. Se trabaja con ciudades europeas como:
`Madrid`, `Londres`, `Roma`, `Atenas`, `Berlín`, `Ámsterdam` y `París`.

---

## 🗂️ Estructura del proyecto

```
grafos-red-aerea/
├── CMakeLists.txt
├── main.c                                      # Programa principal y menú
├── tads/
│   ├── tGrafo.c / tGrafo.h                    # TAD Grafo (lista enlazada de nodos)
│   ├── tListaAdyacencia.c / tListaAdyacencia.h # TAD Lista de adyacencia
│   ├── tVertice.c / tVertice.h                # TAD Vértice (ciudad)
│   ├── tPeso.c / tPeso.h                      # TAD Peso (vuelo: compañía, tiempo, precio)
│   ├── tCola.c / tCola.h                      # TAD Cola FIFO (auxiliar para BFS)
│   ├── tConjunto.c / tConjunto.h              # TAD Conjunto (auxiliar para BFS)
│   └── UsosGrafo.c / UsosGrafo.h             # Funciones de consulta de alto nivel
├── datos/
│   └── vuelos.txt                             # Fichero de entrada con los vuelos
└── README.md
```

---

## 📂 Formato del fichero de entrada

Cada vuelo ocupa **5 líneas consecutivas** en `vuelos.txt`:

```
Madrid
Paris
Iberia
120
150
```

Esto representa un vuelo de Madrid a París con Iberia, duración 120 min y precio 150 €.

---

## ⚙️ Funcionalidades implementadas

- **Carga desde fichero** — Lee `vuelos.txt` y construye el grafo automáticamente.
- **Destinos desde una ciudad** — Muestra todas las ciudades a las que se puede volar directamente.
- **Conectividad del grafo** — Determina si el grafo es fuertemente conexo, débilmente conexo o no conexo, lanzando un BFS desde cada vértice.
- **Rutas con una escala** — Dada una ciudad, lista todas las ciudades alcanzables haciendo exactamente una escala.
- **Vuelo directo** — Indica si existe conexión directa entre dos ciudades dadas.
- **Ciudades fuente y sumidero** — Detecta ciudades sin salidas (sumidero) o sin entradas (fuente).
- **Mayor número de aerolíneas** — Identifica el trayecto con más compañías distintas operando.
- **Trayecto más caro / más barato** — Búsqueda por precio entre todas las aristas.
- **Trayecto más lento / más rápido** — Búsqueda por tiempo entre todas las aristas.

---

## 🏗️ Implementación

El grafo se implementa como una **lista enlazada de nodos**, donde cada nodo representa una ciudad (vértice) y apunta a su **lista de adyacencia** — otra lista enlazada con todos los vuelos que salen de esa ciudad.

```
tGrafo → [Madrid] → [Paris, Iberia, 120, 150] → [Londres, British_Airways, 150, 180] → NULL
              ↓
         [Paris]  → [Londres, Air_France, 90, 130] → NULL
              ↓
          ...
```

Las estructuras principales son:

```c
// Vértice del grafo (ciudad)
typedef char tVertice[MAX_CIU];

// Peso de la arista (vuelo)
typedef struct {
    char compañia[MAX_COM];
    int tiempo;
    int precio;
} tPeso;

// Nodo de la lista de adyacencia
struct NodoAdy {
    tVertice ciudad;
    tPeso info;
    struct NodoAdy *sig;
};

// Nodo del grafo
struct NodoLista {
    tVertice ciudad;
    struct NodoLista *sig;
    struct NodoAdy *ady;
};

typedef struct NodoLista *tGrafo;
```

El recorrido en anchura (BFS) utiliza dos TADs auxiliares:
- **tCola** — cola FIFO para gestionar el orden de visita de los vértices.
- **tConjunto** — conjunto dinámico sin repetidos para registrar los nodos ya visitados y evitar ciclos.

---

## 🚀 Compilación y ejecución

El proyecto usa **CMake**. Para compilar y ejecutar:

```bash
mkdir build && cd build
cmake ..
cmake --build .
./Practica
```

> El `CMakeLists.txt` copia `vuelos.txt` automáticamente al directorio de compilación, por lo que no es necesario moverlo manualmente.

---

## 📚 Conceptos trabajados

- Grafos dirigidos y ponderados
- Listas de adyacencia dinámicas
- Recorrido en anchura (BFS)
- Comprobación de conectividad fuerte y débil
- Lectura y parsing de ficheros de texto en C
- Gestión de memoria dinámica (`malloc` / `free`)
- Diseño modular mediante TADs independientes
