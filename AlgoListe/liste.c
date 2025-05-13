#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct elem_lista {
    int dato;
    struct elem_lista *succ_p;
} elem_lista_t;


elem_lista_t *riempi_lista_random(int n);

elem_lista_t *crea_nodo(elem_lista_t *testa, int valore);

void visita_lista(elem_lista_t *testa_p);

elem_lista_t *cerca_in_lista(elem_lista_t *testa_p, int ricercato);

void libera_memoria(elem_lista_t *testa);

void elabora(int v);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Uso: ./liste <n-elementi>\n");
        exit(-1);
    }
    int n = atoi(argv[1]), ricercato;
    srand(time(NULL));

    elem_lista_t *testa = riempi_lista_random(n),
            *locazione_ricercato;
    visita_lista(testa);

    printf("Digita l'elemento da cercare: ");
    scanf("%d", &ricercato);

    locazione_ricercato = cerca_in_lista(testa, ricercato);
    printf("%p\n", locazione_ricercato);

    libera_memoria(testa);

    return 0;
}


elem_lista_t *riempi_lista_random(int n) {
    elem_lista_t *testa = NULL;
    int i, valore;

    for (i = 0; i < n; i++) {
        valore = rand() % 100;
        testa = crea_nodo(testa, valore);
    }

    return (testa);
}

elem_lista_t *crea_nodo(elem_lista_t *testa, int valore) {
    elem_lista_t *nuovo_elemento = (elem_lista_t *) malloc(sizeof(elem_lista_t));

    nuovo_elemento->dato = valore;
    nuovo_elemento->succ_p = NULL;

    /* Se manca la testa (quindi lista vuota) il nuovo elemento diventa la testa */
    if (testa == NULL) {
        return nuovo_elemento;
    }

    /* Altrimenti scorri fino all'ultimo nodo... */
    elem_lista_t *corrente = testa;
    while (corrente->succ_p != NULL) {
        corrente = corrente->succ_p;
    }

    /* ...ed aggiungi il nuovo nodo */
    corrente->succ_p = nuovo_elemento;
    return (testa);
}

void libera_memoria(elem_lista_t *testa) {
    elem_lista_t *temp;
    while (testa != NULL) {
        temp = testa;
        testa = testa->succ_p;
        free(temp);
    }
}

void visita_lista(elem_lista_t *testa_p) {
    elem_lista_t *elem_p;

    for (elem_p = testa_p;
         elem_p != NULL;
         elem_p = elem_p->succ_p) {

        printf("%d\n", elem_p->dato);
    }
}

elem_lista_t *cerca_in_lista(elem_lista_t *testa_p, int ricercato) {
    elem_lista_t *elem_p;

    for (elem_p = testa_p; ((elem_p != NULL)); elem_p = elem_p->succ_p) {
        if (elem_p->dato == ricercato) {
            return elem_p;
        }
    }
    return (NULL);
}

