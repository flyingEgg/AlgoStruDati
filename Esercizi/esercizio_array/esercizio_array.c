#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genera_random(int n, int*);
void stampa_array(int n, int*);
void quicksort(int*, int sx, int dx);
void reverse_quicksort(int* , int sx, int dx);
int inserimento();
int ricerca_binaria_array(int*, int n, int valore);

int main(){
    int n, x, pos_x, *arr;

    srand(time(NULL));

    n = inserimento();


    arr = (int *) malloc(sizeof (int) * n);

    genera_random(n, arr);
    stampa_array(n, arr);

    reverse_quicksort(arr, 0, n - 1);
    stampa_array(n, arr);
    quicksort(arr, 0, n - 1);

    stampa_array(n, arr);

    x = inserimento();


    pos_x = ricerca_binaria_array(arr, n, x);

    if(pos_x != -1)
        printf("Trovato alla posizione %d\n", pos_x);
    else
        printf("Elemento non trovato.\n");


    return 0;
}

int inserimento(){
    int esito_lettura, acquisizione_errata, n;

    do{
        printf("Digitare un numero ");
        esito_lettura = scanf("%d", &n);
        acquisizione_errata = esito_lettura != 1 || n <= 0;

        if(acquisizione_errata){
            printf("\nSi è digitato un valore errato\n");
        }
        while (getchar() != '\n');
    } while (acquisizione_errata);

    return n;
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
    int pivot, tmp, i, j;

    for (pivot = a[(sx + dx) / 2], i = sx, j = dx; (i <= j);) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if(i <= j){
            if(i < j){
                /*printf("\ntemp arr: ");
                stampa(a, dx + 1);*/
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                /*printf("\ntemp arr: ");
                stampa(a, dx + 1);*/
            }
            i++;
            j--;
        }
    }

    if(sx < j)
        quicksort(a, sx, j);
    if (i < dx)
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

int ricerca_binaria_array(int* a, int n, int valore){
    int sx, mx, dx;

    for ( sx = 0, dx = n - 1, mx = (sx + dx) / 2;
          ((sx <= dx) && (a[mx] != valore));
          mx = (sx + dx) / 2){
        if(a[mx] > valore)
            dx = mx - 1;
        else
            sx = mx + 1;
    }

    return ((sx <= dx) ?
            mx:
            -1);
}