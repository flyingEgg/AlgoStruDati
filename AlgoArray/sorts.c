#include <stdio.h>
#include <stdlib.h>

void riempi_rand(int* a, int num);
int genera_random();
void stampa(int* a, int num);

int main(){
    int n = 10, ricercato = 23,
            *arr = NULL;

    printf("Numero elementi: %d\n", n);
    arr = (int *) malloc(sizeof(int) * n);

    riempi_rand(arr, n);
    stampa(arr, n);

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