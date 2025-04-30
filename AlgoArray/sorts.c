#include <stdio.h>
#include <stdlib.h>

void riempi_rand(int* a, int num);
int genera_random();
void stampa(int* a, int num);
void insert_sort(int* a, int n);
void select_sort (int* a, int n);

int main(int argc, char** argv){
    if(argc < 3){
        printf("Uso: ./ordina <n> <lettera-iniziale-algoritmo>\n");
        exit(0);
    }

    int n = atoi(argv[1]), *arr = NULL;
    char algo = argv[2][0];


    printf("Numero elementi: %d\n", n);
    arr = (int *) malloc(sizeof(int) * n);

    riempi_rand(arr, n);
    printf("Prima: ");
    stampa(arr, n);

    switch(algo){
        case 'i':
            printf("\nInsert sort\n");
            insert_sort(arr, n);
            break;
        case 's':
            printf("\nSelect sort\n");
            select_sort(arr, n);
            break;
        default:
            printf("\nAlgoritmo %c non riconosciuto\n", algo);
    }
    printf("\nDopo: ");
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
        val += rand() % 40;
    } else {
        val -= rand() % 24;
    }
    return val;
}

void stampa(int* a, int num){       /*Esempio di algoritmo di VISITA*/
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

void insert_sort(int* a, int n){
    int valore_ins, i, j;

    for(i = 0; i < n; i++){
        for(valore_ins = a[i], j = i - 1; ((j >= 0) && (a[j] > valore_ins)); j--)
            a[j + 1] = a[j];
        if(j + 1 != i)
            a[j + 1] = valore_ins;
    }
}

void select_sort(int* a, int n){
    int valore_min,
        indice_valore_min,
        i,
        j;

    for(i = 0; i < n - 1; i++){
        for (valore_min = a[i], indice_valore_min = i, j = i + 1; j < n; j++)
            if(a[j] < valore_min){
                valore_min = a[j];
                indice_valore_min = j;
            }
        if(indice_valore_min != i){
            a[indice_valore_min] = a[i];
            a[i] = valore_min;
        }
    }
}