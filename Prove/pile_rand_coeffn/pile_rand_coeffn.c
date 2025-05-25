#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elem_lista{
    int dato;
    struct elem_lista *succ_p;
} elem_lista_t;


void impila(elem_lista_t **cima_p, int valore);
void genera_e_inserisci(elem_lista_t **cima_p, int n);
void visita(elem_lista_t *testa);

int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./pile_rand_coeffn <n>\n");
        exit(-1);
    }

    int n = atoi(argv[1]);
    elem_lista_t *testa_p;
    testa_p = NULL;

    srand(time(NULL));

    genera_e_inserisci(&testa_p, n);
    visita(testa_p);

    return (0);
}

void genera_e_inserisci(elem_lista_t **cima_p, int n){
    int i, generato;

    for(i = 0;
        i < n;
        i++){
        generato = rand() % ((100 * n) + 1);
        impila(cima_p, generato);
    }
}

void impila(elem_lista_t **cima_p, int valore){
    elem_lista_t *nuovo_p = (elem_lista_t *) malloc(sizeof (elem_lista_t));
    nuovo_p -> dato = valore;

    nuovo_p -> succ_p = *cima_p;
    *cima_p = nuovo_p;
}

void visita(elem_lista_t *testa){
    elem_lista_t *corr_p;

    printf("\n");
    for(corr_p = testa;
       (corr_p != NULL);
        corr_p = corr_p -> succ_p){
        printf("%d ", corr_p -> dato);
    }
    printf("\n");
}
