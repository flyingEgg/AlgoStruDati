#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elem_lista{
    int dato;
    struct elem_lista *next_p;
} elem_lista_t;

int inserisci(elem_lista_t **testa_p, int valore);
void visita(elem_lista_t *testa_p);
elem_lista_t *rimuovi(elem_lista_t **testa_p, int valore);

int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./sortedlist_rand <n-di-elementi>\n");
        exit(-1);
    }

    int n = atoi(argv[1]),
        i,
        val,
        scelta;
    elem_lista_t *testa_p,
                 *rimosso_p;

    srand(time(NULL));
    testa_p = NULL;

    for(i = 0; i < n; i++){
        val = rand() % 50;
        if(inserisci(&testa_p, val) != 0)
            printf("Inserisco %d\n", val);
        else
            printf("%d duplicato, non inserito\n", val);
    }

    visita(testa_p);

    do{
        printf("Rimuovere? (digitare 1 se si\')\n");
        scanf("%d", &scelta);
        if(scelta == 1){
            printf("Elemento da rimuovere: ");
            scanf("%d", &val);
            rimosso_p = rimuovi(&testa_p, val);
            if(rimosso_p == NULL)
                printf("%d non trovato; lista invariata\n", val);
            else
                free(rimosso_p);

            visita(testa_p);
        }
    } while (scelta == 1);

    return(0);
}

int inserisci(elem_lista_t **testa_p, int valore){
    int inserito;
    elem_lista_t *elem_p,
                 *prec_p,
                 *nuovo_p;

    for(prec_p = elem_p = *testa_p;
        ((elem_p != NULL) && (valore > elem_p -> dato));
        prec_p = elem_p, elem_p = elem_p -> next_p);


    if(elem_p != NULL && elem_p -> dato == valore){
        inserito = 0;
    } else {
        inserito = 1;

        nuovo_p = (elem_lista_t *) malloc(sizeof(elem_lista_t));
        nuovo_p -> dato = valore;
        nuovo_p -> next_p = elem_p;

        if(elem_p == *testa_p)
            *testa_p = nuovo_p;
        else {
            prec_p->next_p = nuovo_p;
        }
    }

    return inserito;
}

void visita(elem_lista_t *testa_p){
    elem_lista_t *elem_p;

    for(elem_p = testa_p; (elem_p != NULL); elem_p = elem_p -> next_p){
        printf("%d\n", elem_p -> dato);
    }
}

elem_lista_t *rimuovi(elem_lista_t **testa_p, int valore){
    elem_lista_t *curr_p,
                 *prev_p,
                 *rimosso_p;
    rimosso_p = NULL;

    for(prev_p = curr_p = *testa_p;
        ((curr_p != NULL) && (valore != curr_p -> dato));
        prev_p = curr_p, curr_p = curr_p -> next_p);

    if(curr_p != NULL){
        prev_p -> next_p = curr_p -> next_p;
        rimosso_p = curr_p;
    }

    return rimosso_p;
}
