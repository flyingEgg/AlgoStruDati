#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genera_random(int n, int*);
void stampa_array(int n, int*);
void quicksort(int*, int sx, int dx);
void reverse_quicksort(int* , int sx, int dx);

int main(){
    int n, *arr, esito_lettura, acquisizione_errata;

    srand(time(NULL));

    do{
        printf("Digitare un numero ");
        esito_lettura = scanf("%d", &n);
        acquisizione_errata = esito_lettura != 1 || n <= 0;

        if(acquisizione_errata){
            printf("\nSi è digitato un valore errato\n");
        }
        while (getchar() != '\n');
    } while (acquisizione_errata);


    arr = (int *) malloc(sizeof (int) * n);

    genera_random(n, arr);
    stampa_array(n, arr);

    quicksort(arr, 0, n - 1);

    stampa_array(n, arr);
    reverse_quicksort(arr, 0, n - 1);
    stampa_array(n, arr);

    return 0;
}

void genera_random(int n, int* arr){
    int i;

    for(i = 0; i < n; i++){
        arr[i] = rand() % 101;
    }
}

void stampa_array(int n, int* arr){
    int i;

    printf("\n\n[");
    for(i = 0; i < n; i++){
        if(i == n - 1)
            printf("%d]\n", arr[i]);
        else
            printf("%d,", arr[i]);
    }
}

void quicksort(int* a, int sx, int dx){
    int i, j, pivot, tmp;

    for(pivot = a[(sx + dx) / 2], i = sx, j = dx; i <= j;){
        while(a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if(i <= j){
            if(i < j){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    }

    if (sx < j)
        quicksort(a, sx, j);
    if(dx < i)
        quicksort(a, i, dx);
}

void reverse_quicksort(int* a, int sx, int dx){
    int i, j, pivot, tmp;

    for(pivot = a[(sx + dx) / 2], i = sx, j = dx; i <= j;){
        while(a[i] > pivot){
            i++;
        }
        while (a[j] < pivot){
            j--;
        }

        if(i <= j){
            if(i < j){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    }

    if (sx < j)
        reverse_quicksort(a, sx, j);
    if(dx < i)
        reverse_quicksort(a, i, dx);
}