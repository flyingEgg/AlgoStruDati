#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elem_lista{
    int dato;
    struct elem_lista *next_p;
}elem_lista_t;

void impila(elem_lista_t **cima_p, int valore);
void visita(elem_lista_t *testa_p);
void cerca_maggiori_di_x(elem_lista_t *testa_p, int x);

int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./pile_rand_coeff <n-valori>\n");
        exit(-1);
    }

    int N = atoi(argv[1]),
        i,
        val;
    elem_lista_t *testa_p;

    testa_p = NULL;
    srand(time(NULL));

    for(i = 0; i < N; i++){
        val = rand() % (11*N);
        printf("Aggiungo %d alla pila.\n", val);
        impila(&testa_p, val);
    }

    printf("\nSTAMPA DELLA PILA:\n");
    visita(testa_p);

    printf("Digitare un numero intero \"x\": ");
    scanf("%d", &val);

    printf("\n\nElementi maggiori di x:\n");
    cerca_maggiori_di_x(testa_p, val);

    return 0;
}

void impila(elem_lista_t **cima_p, int valore){
    elem_lista_t *nuovo_p;

    nuovo_p = (elem_lista_t *) malloc(sizeof (elem_lista_t));
    nuovo_p -> dato = valore;
    nuovo_p -> next_p = *cima_p;
    *cima_p = nuovo_p;
}

void visita(elem_lista_t *testa_p){
    elem_lista_t *elem_p;

    for(elem_p = testa_p;
        (elem_p != NULL);
        elem_p = elem_p -> next_p){
        printf("%d\n", elem_p -> dato);
    }
}

void cerca_maggiori_di_x(elem_lista_t *testa_p, int x){
    elem_lista_t *elem_p;

    for (elem_p = testa_p; (elem_p != NULL); elem_p = elem_p -> next_p){
        if(elem_p -> dato >= x)
            printf("%d\n", elem_p -> dato);
    }
}
