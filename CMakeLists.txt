
cmake_minimum_required(VERSION 3.5)
project(Practica C)

set(CMAKE_C_STANDARD 11)

# -------- LIBRERIA DE TADs --------
add_library(tads
        tads/tGrafo.c
        tads/tListaAdyacencia.c
        tads/tVertice.c
        tads/tPeso.c
        tads/UsosGrafo.c
        tads/tConjunto.c
        tads/tCola.c
)

target_include_directories(tads PUBLIC tads)

add_executable(Practica main.c)

target_link_libraries(Practica tads)



configure_file(
        ${CMAKE_SOURCE_DIR}/datos/vuelos.txt
        ${CMAKE_BINARY_DIR}/vuelos.txt
        COPYONLY
)
