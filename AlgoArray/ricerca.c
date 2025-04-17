#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void riempi_rand(int* a, int num);
int genera_random();
void stampa(int* a, int num);
int ricerca_lineare_array(int* a, int n, int valore);

int main(){
    int n = 10, ricercato = 23,
    *arr = NULL;

    printf("Numero elementi: %d\n", n);
    arr = (int *) malloc(sizeof(int) * n);

    riempi_rand(arr, n);
    stampa(arr, n);
    printf("\nCerco elemento: %d...\n", ricercato);
    printf("Trovato alla posizione: %d\n", ricerca_lineare_array(arr, n, ricercato) + 1);

    free(arr);
    return 0;
}

void riempi_rand(int* a, int num){
    int i;
    for(i = 0; i < num; i++){
        a[i] = genera_random();
    }
}

int genera_random(){
    int val, aux;
    val = (rand() % 100);
    aux = (rand() % 20);
    if(aux % 2){
        val + rand();
    } else {
        val - rand();
    }
    return val;
}

void stampa(int* a, int num){       // Esempio di algoritmo di VISITA
    int i;
    printf("\n[");
    for(i = 0; i < num; i++){
        if(i == num-1)
            printf("%d",a[i]);
        else
            printf("%d,",a[i]);
    }
    printf("]\n");
}

int ricerca_lineare_array(int* a, int n, int valore){
    int i;
    for (i = 0; ((i < n) && (a[i] != valore)); i++) {};  // Corpo vuoto {} perché tutto il lavoro è fatto nella condizione del for
     return ((i < n) ? i : -1);
 }
