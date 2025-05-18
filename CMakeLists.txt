cmake_minimum_required(VERSION 3.15)
project(AlgoStruDati C)

set(CMAKE_C_STANDARD 11)

# Aggiungi la cartella src dove si trovano i tuoi file .c
add_executable(AlgoStruDati AlgoArray/ricerca.c
        AlgoArray/sorts.c
        Esercizi/pila_int_rand.c
        Esercizi/esercizio_array/esercizio_array.c
        AlgoListe/liste.c
        AlgoListe/code.c
        AlgoListe/pile.c
        Prove/coda_stringhe_file/coda_stringhe_file.c
        Prove/coda_stringhe_rand/coda_stringhe_rand.c
        AlgoAlberi/alberi_binari.c
        Prove/array_dado/array_dado.c
        Prove/pile_rand/pile_rand.c
        Prove/bst_rand/bst_rand.c)
