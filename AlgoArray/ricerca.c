#include <stdio.h>
#include <stdlib.h>

void riempi_rand(int* a, int num);
int genera_random();
void stampa(int* a, int num);
int ricerca_lineare_array(int* a, int n, int valore);
int ricerca_binaria_array(int* a, int n, int valore);

int main(int argc, char** argv){

    int n = atoi(argv[1]),
        ricercato = atoi(argv[2]),
        *arr = NULL;

    printf("Numero elementi: %d\n", n);
    arr = (int *) malloc(sizeof(int) * n);

    riempi_rand(arr, n);

    stampa(arr, n);
    printf("\nCerco elemento: %d...\n", ricercato);
    printf("Trovato alla posizione: %d\n", ricerca_lineare_array(arr, n, ricercato) + 1);
    printf("\nTrovato alla posizione: %d\n", ricerca_binaria_array(arr, n, ricercato) + 1);

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
    if(aux % 2 == 0){
        val += (rand() % 40);
    } else {
        val -= (rand() % 24);
    }
    return val;
}

void stampa(int* a, int num){        /*Esempio di algoritmo di VISITA*/
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
    int i, clock = 0;
    for (i = 0;
        ((i < n) && (a[i] != valore));
        i++)
        clock++;                                        /*Corpo vuoto {} perché tutto il lavoro è fatto nella condizione del for*/
    printf("Clk lin: %d\n", clock);
    return ((i < n) ? i : -1);                                  /* Se i < n, il ciclo for è terminato prima che i raggiungesse n perché è stato trovato "valore */
 }                                                              /* Se i >= n, il ciclo for è terminato perché i ha raggiunto n, quindi "valore" non è stato trovato (-1 valore convenzionale
                                                                   che indica il fallimento nella ricerca) */


int ricerca_binaria_array(int* a, int n, int valore){
    int sx, mx, dx, clock = 0;

    for ( sx = 0, dx = n - 1, mx = (sx + dx) / 2;
        ((sx <= dx) && (a[mx] != valore));
        mx = (sx + dx) / 2){
        clock++;
        if(a[mx] > valore)
            dx = mx - 1;
        else
            sx = mx + 1;
    }
    printf("\nClk bin: %d",  clock);
    return ((sx <= dx) ?
            mx:
            -1);
}
