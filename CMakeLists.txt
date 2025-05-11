cmake_minimum_required(VERSION 3.15)
project(AlgoStruDati C)

set(CMAKE_C_STANDARD 11)

# Aggiungi la cartella src dove si trovano i tuoi file .c
add_executable(AlgoStruDati AlgoArray/ricerca.c
        AlgoArray/sorts.c
        Esercizi/pila_int_rand.c
        Esercizi/esercizio_array/esercizio_array.c
        AlgoListe/liste.c
        AlgoListe/Code.c
        AlgoListe/Pile.c)
