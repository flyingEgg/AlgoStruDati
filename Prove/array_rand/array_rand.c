#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void stampa(int *arr, int n);
void quicksort(int *arr, int sx, int dx);
void reverse_quicksort(int *arr, int sx, int dx);
int ricerca_binaria(int *arr, int n, int ricercato);



int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./array_rand <numero-elementi>\n");
        exit(-1);
    }

    int n,
        i,
        *arr,
        ricercato,
        posizione_ricercato;

    n = atoi(argv[1]);
    arr = (int *) malloc(sizeof(int) * n),
    srand(time(NULL));

    for(i = 0; i < n; i++){
        arr[i] = rand() % 101;
    }

    stampa(arr, n);

    reverse_quicksort(arr, 0, n);
    printf("\nArray ordinato (max -> min): ");
    stampa(arr, n);

    quicksort(arr, 0, n);
    printf("\nArray ordinato (min -> max): ");
    stampa(arr, n);

    printf("\nAdesso digita un numero intero: ");
    scanf("%d", &ricercato);

    posizione_ricercato = ricerca_binaria(arr, n, ricercato);
    if(posizione_ricercato != -1)
        printf("\n%d trovato alla posizione %d\n", ricercato, posizione_ricercato);
    else
        printf("%d non trovato\n", ricercato);


    return(0);
}

void stampa(int *arr, int n){
    int i;

    printf("[");
    for(i = 0; i < n; i++){
        if(i != n - 1)
            printf("%d,", arr[i]);
        else
            printf("%d]\n", arr[i]);
    }
}

void quicksort(int *arr, int sx, int dx){
    int i, j, pivot, tmp;

    for(pivot = arr[rand() % (dx - sx + 1) + sx], i = sx, j = dx; (i <= j);){
        while(arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        
        if(i <= j){
            if(i < j){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            i++;
            j--;
        }

        if(sx < j)
            quicksort(arr, sx, j);
        if(i < dx){
            quicksort(arr, i, dx);
        }
    }
}

void reverse_quicksort(int *arr, int sx, int dx){
    int i, j, pivot, tmp;

    for(pivot = arr[rand() % (dx - sx + 1) + sx], i = sx, j = dx; (i <= j);){
        while(arr[i] > pivot)
            i++;
        while (arr[j] < pivot)
            j--;
        
        if(i <= j){
            if(i < j){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            i++;
            j--;
        }

        if(sx < j)
            reverse_quicksort(arr, sx, j);
        if(i < dx){
            reverse_quicksort(arr, i, dx);
        }
    }
}

int ricerca_binaria(int *arr, int n, int ricercato){
    int sx, mx, dx;

    for(sx = 0, dx = n - 1, mx = (sx + dx) / 2;
       ((sx <= dx) && (arr[mx] != ricercato));
        mx = (sx + dx) / 2){
        if(arr[mx] > ricercato)
            dx = mx - 1;
        else
            sx = mx + 1;
    }

    if(sx <= dx)
        return mx;
    else
        return -1;

    return((sx <= dx) ? mx : -1);
}
