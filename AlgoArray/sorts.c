#include <stdio.h>
#include <stdlib.h>

int genera_random();
void menu(char algo, int* a, int n);
void riempi_rand(int* a, int num);
void stampa(int* a, int num);
void insert_sort(int* a, int n);
void select_sort (int* a, int n);
void bubble_sort(int*, int n);
void merge_sort(int*, int sx, int dx);
void merge(int*, int sx, int mx, int dx);

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

    menu(algo, arr, n);

    printf("\nDopo: ");
    stampa(arr, n);

    free(arr);
    return 0;
}

void menu(char algo, int* arr, int n){
    switch(algo){
        case 'i':
            printf("\nInsert sort\n");
            insert_sort(arr, n);
            break;
        case 's':
            printf("\nSelect sort\n");
            select_sort(arr, n);
            break;
        case 'b':
            printf("\nBubble sort\n");
            bubble_sort(arr, n);
            break;
        case 'm':
            printf("\nMerge sort\n");
            merge_sort(arr, 0, n - 1);
            break;
        default:
            printf("\nAlgoritmo %c non riconosciuto\n", algo);
    }
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


void bubble_sort(int* a, int n){
    int tmp,
        i,
        j;

    for (i = 1; i < n; i++) {
        for (j = n - 1 ; j >= i; j--)
            if(a[j] < a[j - 1]){
                tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
    }
}

void merge_sort(int* a, int sx, int dx){
    int mx;
    if(sx < dx){
        mx = (sx + dx) / 2;
        merge_sort(a, sx, mx);
        merge_sort(a, mx + 1, dx);
        merge(a, sx, mx, dx);
    }
}

void merge(int* a, int sx, int mx, int dx) {
    int *b, i, j, k;

    printf("\n--- INIZIO MERGE ---");
    printf("\nSottoarray sinistro: ");
    stampa(a + sx, mx - sx + 1);
    printf("Sottoarray destro: ");
    stampa(a + mx + 1, dx - mx);

    b = (int *)calloc(dx + 1, sizeof(int));

    printf("\nInizio fusione...\n");
    for(i = sx, j = mx + 1, k = 0; ((i <= mx) && (j <= dx)); k++) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            printf("Prendo %d dalla sinistra -> ", a[i]);
            i++;
        } else {
            b[k] = a[j];
            printf("Prendo %d dalla destra -> ", a[j]);
            j++;
        }
        stampa(b, k + 1);
    }

    printf("\nElementi rimanenti a sinistra: ");
    while (i <= mx) {
        b[k] = a[i];
        printf("%d ", a[i]);
        i++;
        k++;
    }

    printf("\nElementi rimanenti a destra: ");
    while (j <= dx) {
        b[k] = a[j];
        printf("%d ", a[j]);
        j++;
        k++;
    }

    printf("\n\nArray temporaneo completo: ");
    stampa(b, dx - sx + 1);

    for(k = sx; k <= dx; k++) {
        a[k] = b[k - sx];
    }

    printf("Array dopo il merge: ");
    stampa(a + sx, dx - sx + 1);
    printf("--- FINE MERGE ---\n\n");

    free(b);
}