#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


typedef struct elem_lista{
    int dato;
    struct elem_lista *next_p;
}elem_lista_t;

void accoda(elem_lista_t **ingresso_p, elem_lista_t **uscita_p, int valore);
void visita(elem_lista_t *testa_p);
int *calcola_max_min(elem_lista_t  *testa_p);

int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./min_max_coda <n-valori>\n");
        exit(-1);
    }

    int N = atoi(argv[1]),
        i,
        val,
        *arr;
    elem_lista_t *testa_p,
                 *coda_p;

    testa_p = coda_p = NULL;

    srand(time(NULL));

    for(i = 0; (i < N); i++){
        val = rand() % (4*N);
        printf("Accodo %d\n", val);
        accoda(&coda_p, &testa_p, val);
    }

    printf("\nELEMENTI DELLA LISTA:\n");
    visita(testa_p);

    arr = calcola_max_min(testa_p);
    printf("\nmin: %d, MAX: %d\n", arr[0], arr[1]);

    free(arr);
    return 0;
}

void accoda(elem_lista_t **ingresso_p, elem_lista_t **uscita_p, int valore){
    elem_lista_t *nuovo_p;

    nuovo_p = (elem_lista_t *) malloc(sizeof(elem_lista_t));
    nuovo_p -> dato = valore;
    nuovo_p -> next_p = NULL;

    if(*uscita_p != NULL){
        (*ingresso_p) -> next_p = nuovo_p;
    } else {
        *uscita_p = nuovo_p;
    }
    *ingresso_p = nuovo_p;
}

void visita(elem_lista_t *testa_p){
    elem_lista_t *elem_p;

    for(elem_p = testa_p; (elem_p != NULL); elem_p = elem_p -> next_p){
        if(elem_p -> next_p != NULL)
            printf("%d -> ", elem_p -> dato);
        else
            printf("%d\n", elem_p -> dato);
    }
}

int *calcola_max_min(elem_lista_t  *testa_p){
    int max = 0,
        min = INT_MAX,
        *risultati = (int *) malloc(sizeof(int)*2);
    elem_lista_t *elem_p;

    for(elem_p = testa_p; (elem_p != NULL); elem_p = elem_p -> next_p){
        if(elem_p -> dato > max)
            max = elem_p -> dato;
        else if(elem_p -> dato < min)
            min = elem_p -> dato;
    }

    risultati[0] = min;
    risultati[1] = max;

    return risultati;
}
