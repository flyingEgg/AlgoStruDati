#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elem_p1{
    int dato;
    struct elem_p1 *succ_p;
} elem_p1_t;

typedef struct elem_p2{
    int dato;
    struct elem_p2 *succ_p;
} elem_p2_t;

void impila(elem_p1_t **cima_p1, elem_p2_t **cima_p2, int v1, int v2);
void riempi_pila(elem_p1_t **cima_p1, elem_p2_t **cima_p2, int n);
void visita(elem_p1_t *testa1, elem_p2_t *testa2);

int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./pile_rand <n-dei-valori-da-generare>\n");
        exit(-1);
    }

    int n = atoi(argv[1]), somma_recenti = 0;
    elem_p1_t *cima_p1;
    elem_p2_t *cima_p2;

    cima_p1 = NULL;
    cima_p2 = NULL;

    srand(time(NULL));

    riempi_pila(&cima_p1, &cima_p2, n);
    visita(cima_p1, cima_p2);

    somma_recenti += cima_p1 -> dato + cima_p2 -> dato;
    printf("Somma dei più recenti: %d\n", somma_recenti);

    return(0);
}

void visita(elem_p1_t *testa1, elem_p2_t *testa2){
    elem_p1_t *corr_p1;
    elem_p2_t *corr_p2;

    printf("\nPila 1: ");
    for(corr_p1 = testa1; corr_p1 != NULL; corr_p1 = corr_p1 -> succ_p){
        printf("%d ", corr_p1 -> dato);
    }
    printf("\n");

    printf("Pila 2: ");
    for(corr_p2 = testa2; corr_p2 != NULL; corr_p2 = corr_p2 -> succ_p){
        printf("%d ", corr_p2 -> dato);
    }
    printf("\n");
}

void impila(elem_p1_t **cima_p1, elem_p2_t **cima_p2, int v1, int v2){
    elem_p1_t *nuovo_p1 = (elem_p1_t *) malloc(sizeof(elem_p1_t));
    elem_p2_t *nuovo_p2 = (elem_p2_t *) malloc(sizeof(elem_p2_t));

    nuovo_p1 -> dato = v1;
    nuovo_p2 -> dato = v2;
    nuovo_p1 -> succ_p = *cima_p1;
    nuovo_p2 -> succ_p = *cima_p2;
    *cima_p1 = nuovo_p1;
    *cima_p2 = nuovo_p2;
}

void riempi_pila(elem_p1_t **cima_p1, elem_p2_t **cima_p2, int n){
    int i, valore1, valore2;

    for(i = 0; i < n; i++){
        valore1 = rand() % 2;
        valore2 = rand() % 2;
        printf("%d %d\n", valore1, valore2);
        impila(cima_p1, cima_p2, valore1, valore2);
    }
}
