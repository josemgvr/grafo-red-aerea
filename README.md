# ✈️ Red Aérea Europea — Práctica de Grafos

> **Asignatura:** Estructura de Datos · Grado en Ingeniería Informática · URJC  
> **Lenguaje:** C  
> **Estructura principal:** Grafo dirigido y ponderado con listas de adyacencia

---

## 📋 Descripción

Modelado de una red aérea europea mediante un **grafo dinámico, dirigido y ponderado**. El programa carga la información de los vuelos desde un fichero de texto y permite al usuario realizar distintas consultas sobre la red.

Cada vuelo entre dos ciudades queda representado como una **arista del grafo** con tres pesos asociados:

| Campo     | Descripción                        |
|-----------|------------------------------------|
| Compañía  | Aerolínea que opera el trayecto    |
| Tiempo    | Duración del vuelo (en minutos)    |
| Precio    | Coste del billete (en euros)       |

Las **ciudades** son los vértices del grafo. Se trabaja con 8 ciudades europeas:
`Madrid`, `Londres`, `Roma`, `Atenas`, `Berlín`, `Ámsterdam`, `París` y `Dublín`.

---

## 🗂️ Estructura del proyecto

```
grafos-red-aerea/
├── src/
│   ├── main.c
│   ├── tGrafo.c / tGrafo.h          # TAD Grafo (lista de adyacencia)
│   ├── tListaAdy.c / tListaAdy.h    # Lista de adyacencia
│   ├── tVertice.c / tVertice.h      # TAD Vértice (ciudad)
│   └── tVuelo.c / tVuelo.h          # TAD Vuelo (peso de arista)
├── datos/
│   └── vuelos.txt                   # Fichero de entrada con los vuelos
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
- **Conectividad del grafo** — Determina si el grafo resultante es conexo.
- **Rutas con una escala** — Dada una ciudad A, lista todas las ciudades alcanzables haciendo exactamente una escala.
- **Vuelo directo** — Indica si existe conexión directa entre dos ciudades dadas.
- **Ciudades fuente y sumidero** — Detecta vértices sin entradas (fuente) o sin salidas (sumidero).
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
typedef char tVertice[MAX];

// Peso de la arista (vuelo)
typedef struct {
    char compania[MAX_COM];
    int tiempo;
    int precio;
} tVuelo;

// Nodo de la lista de adyacencia
struct NodoAdy {
    tVertice destino;
    tVuelo vuelo;
    struct NodoAdy *sig;
};

// Nodo del grafo
struct NodoLista {
    tVertice info;
    struct NodoAdy *ady;
    struct NodoLista *sig;
};

typedef struct NodoLista *tGrafo;
```

---

## 🚀 Compilación y ejecución

```bash
gcc src/*.c -o red_aerea
./red_aerea datos/vuelos.txt
```

---

## 📚 Conceptos trabajados

- Grafos dirigidos y ponderados
- Listas de adyacencia dinámicas
- Lectura y parsing de ficheros de texto en C
- Recorridos y búsquedas sobre grafos
- Gestión de memoria dinámica (`malloc` / `free`)
