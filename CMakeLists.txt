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
        Prove/bst_rand/bst_rand.c
        Prove/pile_rand_coeffn/pile_rand_coeffn.c
        Prove/bst_rand1/bst_rand.c
        Prove/bst_file1/bst_file.c
        Prove/code_rand/code_rand.c Prove/pile_file/pile_file.c
        Prove/bst_rand2/bst_rand.c
        Esercizi/grafo_prova/grafo_prova.c
        Prove/07-06-2023/pile_rand_coeff.c
        Prove/simulazione_23-05-2023/min_max_coda.c
        Prove/09-01-2024/bst_rand.c
        Prove/10-07-2023/bst_interi_file.c)
