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
int inserisci_in_lista_ordinata(elem_lista_t **testa_p, int valore);

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Uso: ./liste <numero-elementi> <tipologia-inserimento>\n");
        exit(-1);
    }
    int n = atoi(argv[1]), ricercato, nuovo_valore, i;
    char tipo_input = argv[2][0];

    srand(time(NULL));

    elem_lista_t *testa = NULL, *locazione_ricercato;

    switch (tipo_input) {
        case 'r':                                                   /* r = Random */
            testa = riempi_lista_random(n);
            break;
        case 't':
            printf("Digitare gli elementi da inserire:\n");
            for(i = 0; i < n; i++){
                scanf("%d", &nuovo_valore);
                inserisci_in_lista_ordinata(&testa, nuovo_valore);
            }
            break;
        default:
            printf("Errore\n");
            exit(-1);
    }


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

    printf("Visito la lista...\n");
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


int inserisci_in_lista_ordinata(elem_lista_t **testa_p, int valore) {
    int inserito;  /*Flag per indicare se l'inserimento è avvenuto*/
    elem_lista_t *corr_p, *prec_p, *nuovo_p;  /*Puntatori ausiliari*/

    /*Ciclo per trovare la posizione corretta dove inserire il nuovo elemento*/
    /*Scorre la lista finché non raggiunge la fine o trova un elemento >= al valore*/
    for (corr_p = prec_p = *testa_p;
         ((corr_p != NULL) && (corr_p->dato < valore));
         prec_p = corr_p, corr_p = corr_p->succ_p);

    /*Controlla se il valore è già presente nella lista*/
    if ((corr_p != NULL) && (corr_p->dato == valore))
        inserito = 0;  /*Valore già presente, non inserito*/
    else {
        inserito = 1;  /*Valore da inserire*/

        /* Alloca memoria per il nuovo elemento */
        nuovo_p = (elem_lista_t *) malloc(sizeof(elem_lista_t));
        nuovo_p->dato = valore;  /*Assegna il valore*/
        nuovo_p->succ_p = corr_p;   /*Collega al successivo*/

        /*Inserimento nella posizione corretta*/
        if (corr_p == *testa_p)  /*Inserimento in testa*/
            *testa_p = nuovo_p;
        else  /*Inserimento in mezzo o in coda*/
            prec_p->succ_p = nuovo_p;
    }
    return (inserito);  /* Restituisce 1 se inserito, 0 se già presente */
}
