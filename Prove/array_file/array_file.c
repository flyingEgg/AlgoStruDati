#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void stampa(int *arr, int n);
void reverse_quicksort(int *arr, int sx, int dx);
void selectsort(int *arr, int n);
int ricerca_binaria(int *arr, int n, int valore);

int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./array_file <nome-del-file>\n");
        exit(-1);
    }

    int n,
        i,
        *arr,
        ricercato,
        esito_ricerca;
    char *nome_file = malloc(sizeof (char) * (strlen(argv[1]) + 1));
    FILE *file_p;
    srand(time(NULL));

    strcpy(nome_file, argv[1]);
    file_p = fopen(nome_file, "r");

    if(file_p == NULL){
        printf("File \"%s\" non trovato\n", nome_file);
        exit(-1);
    }

    fscanf(file_p, "%d", &n);
    arr = (int *) malloc(sizeof(int) * n);

    for(i = 0; i < n; i++){
        fscanf(file_p, "%d", &arr[i]);
    }

    stampa(arr, n);

    reverse_quicksort(arr, 0, n - 1);
    printf("Array ordinato (max -> min):\n");
    stampa(arr, n);

    selectsort(arr, n);
    printf("Array ordinato (min -> max):\n");
    stampa(arr, n);

    printf("Digitare un elemento da cercare:\n");
    scanf("%d", &ricercato);

    esito_ricerca = ricerca_binaria(arr, n, ricercato);
    if(esito_ricerca != -1)
        printf("Trovato in posizione: %d\n", esito_ricerca);
    else
        printf("Elemento non trovato.\n");

    free(nome_file);
    free(arr);

    return (0);
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

void reverse_quicksort(int *arr, int sx, int dx){
    int i,
        j,
        pivot,
        tmp;

    for(pivot = arr[(sx + dx) / 2], i = sx, j = dx; (i <= j);){
        while(arr[i] > pivot)
            i++;
        while(arr[j] < pivot)
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

        if(i < dx)
            reverse_quicksort(arr, i, dx);
    }
}

void selectsort(int *arr, int n){
    int i,
            j,
            candidato,
            indice_candidato;

    for(i = 0;
        (i < n - 1);
        i++){
        for(candidato = arr[i], indice_candidato = i, j = i + 1; (j < n); j++){
            if(arr[j] < candidato){
                candidato = arr[j];
                indice_candidato = j;
            }
        }
        if(indice_candidato != i){
            arr[indice_candidato] = arr[i];
            arr[i] = candidato;
        }
    }
}

int ricerca_binaria(int *arr, int n, int valore){
    int sx, mx, dx;

    for(sx = 0, dx = n, mx = (sx + dx)/2;
        ((sx <= dx) && (valore != arr[mx]));
        mx = (sx + dx) / 2){

        if(valore < arr[mx])
            dx = mx - 1;
        else
            sx = mx + 1;
    }

    return((sx <= dx) ? mx : -1);
}
