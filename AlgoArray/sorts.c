#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genera_random();
void menu(char algo, int*, int n);
void riempi_rand(int*, int num);
void stampa(int*, int num);
void insert_sort(int*, int n);
void select_sort (int*, int n);
void bubble_sort(int*, int n);
void merge_sort(int*, int sx, int dx);
void merge(int*, int sx, int mx, int dx);
void quick_sort(int*, int sx, int dx);
void heap_sort(int*, int n);
void setaccia_heap(int *a, int n, int i);

int main(int argc, char** argv){
    if(argc < 3){
        printf("Uso: ./ordina <n> <lettera-iniziale-algoritmo>\n");
        exit(0);
    }

    int n = atoi(argv[1]), *arr = NULL;
    char algo = argv[2][0];

    srand(time(NULL));

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
        case 'q':
            printf("\nQuick sort\n");
            quick_sort(arr, 0, n - 1);
            break;
        case 'h':
            printf("\nHeap sort\n");
            heap_sort(arr, n);
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
    aux = (rand() % 13);
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

    for(i = 1; i < n; i++){
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

void merge(int* a, int sx, int mx, int dx){
    int *b,
        i,
        j,
        k;

    b = (int *)calloc(dx + 1, sizeof(int));
    for(i = sx, j = mx + 1, k = 0; ((i <= mx) && (j <= dx)); k++)
        if (a[i] <= a[j]){
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
    while (i <= mx){
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= dx){
        b[k] = a[j];
        j++;
        k++;
    }
    for(k = sx; k <= dx; k++)
        a[k] = b[k - sx];
    free(b);
}

void quick_sort(int* a, int sx, int dx){
    int pivot, tmp, i, j;

    for (pivot = a[rand() % (dx - sx + 1) + sx], i = sx, j = dx; (i <= j);) {
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
        quick_sort(a, sx, j);
    if (i < dx)
        quick_sort(a, i, dx);
}

void heap_sort(int a[], int n){
    int tmp, sx, dx;

    /* Prima fase: trasformare l'array in heap */
    for(sx = n / 2; (sx >= 1); sx--)
        setaccia_heap(a, sx, n);

    /* Seconda fase: ordinarlo mantenendo organizzazione ad heap */
    for (dx = n; (dx > 1); dx--){
        tmp = a[1];
        a[1] = a[dx];
        a[dx] = tmp;
        setaccia_heap(a, 1, dx - 1);
    }
}

void setaccia_heap(int a[], int sx, int dx) {
    int nuovo_valore, i, j;

    for (nuovo_valore = a[sx], i = sx, j = 2 * i; (j <= dx);) {
        if ((j < dx) && (a[j + 1] > a[j]))
            j++;
        if (nuovo_valore < a[j]) {
            a[i] = a[j];
            i = j;
            j = 2 * i;
        } else
            j = dx + 1;
    }
    if (i != sx)
        a[i] = nuovo_valore;
}
