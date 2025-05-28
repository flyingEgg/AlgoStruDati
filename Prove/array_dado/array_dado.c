/* Prova del 30-08-2023 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Definizioni firme delle funzioni */
void lancio(int n_e, int n_l, int *somme);
void stampa_array(int n, int *arr);
void quick_sort(int *arr, int sx, int dx);
double media(int n, int *arr);

/* Funzione principale */
int main(int argc, char **argv){
    if(argc < 3){
        printf("Uso: ./array_dado <numero-esperimenti> <numero-lanci>\n");
        exit(-1);
    }
    int n_e = atoi(argv[1]),
        n_l = atoi(argv[2]),
        *somme_esiti = (int *) malloc(sizeof(int) * n_e) ;
    srand(time(NULL));

    lancio(n_e, n_l, somme_esiti);
    stampa_array(n_e, somme_esiti);
    printf("Ordinamento array...\n");
    quick_sort(somme_esiti, 0, n_e - 1);
    printf("\nArray ordinato: ");
    stampa_array(n_e, somme_esiti);

    printf("\nMedia: %f\n", media(n_e, somme_esiti));


    free(somme_esiti);
    return (0);
}

/* Funzione di visita dell'array che stampa i suoi elementi */
void stampa_array(int n, int *arr){
    int i;

    printf("[");
    for(i = 0;
        i < n;
        i++){
        if(i != n - 1)
            printf("%d,", arr[i]);
        else
            printf("%d]\n", arr[i]);
    }
}

/* Funzione che simula gli esperimenti effettuando i lanci e sommandoli */
void lancio(int n_e, int n_l, int *somme){
    int i, j, lancio, somma = 0;

    for(i = 0;
       (i < n_e);
        (i++, somma = 0)){
        for(j = 0;
           (j < n_l);
            j++){
            lancio = (rand() % 5) + 1;
            somma += lancio;
        }
        somme[i] = somma;
    }
}

/* Ordinamento quick sort dell'array delle somme degli esiti (pivot scelto casualmente tra sx e dx) */
void quick_sort(int *arr, int sx, int dx){
    int i, j, pivot, tmp;

    for(pivot = arr[rand() % (dx - sx + 1) + sx], i = sx, j = dx; (i <= j);){
        while (arr[i] < pivot)
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
            quick_sort(arr, sx, j);
        if(i < dx)
            quick_sort(arr, i, dx);
    }
}

/* Media aritmetica dei valori di un array */
double media(int n, int *arr){
    int i;
    double somma = 0;

    for(i = 0; i < n; i++){
        somma += arr[i];
    }

    return somma / n;
}