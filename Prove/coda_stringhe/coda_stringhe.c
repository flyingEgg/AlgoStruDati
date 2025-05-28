/* Prova del 13-09-2023 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct elem_lista{
    char dato[5];
    struct elem_lista *next_p;
} elem_lista_t;

int menu(elem_lista_t **ingresso, elem_lista_t **uscita);
char *genera_stringa(void);
void accoda(elem_lista_t **ingresso, elem_lista_t **uscita, char *valore);
elem_lista_t *rimuovi(elem_lista_t **ingresso, elem_lista_t **uscita);
void visita(elem_lista_t *testa);

int main(void){
    int n, i, esito_menu = 1;
    elem_lista_t *testa,
                 *coda;
    testa = coda = NULL;
    srand(time(NULL));


    printf("Digitare il numero di stringhe\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        accoda(&coda, &testa, genera_stringa());
    }

    visita(testa);

    do
        esito_menu = menu(&coda, &testa);
    while(esito_menu != 0);

    return(0);
}

int menu(elem_lista_t **ingresso, elem_lista_t **uscita){
    int esito, scelta;
    char rimosso[5];
    
    
    printf("\n1) Inserisci\n2) Rimuovi\n3) Stop esecuzione\n");
    scanf("%d", &scelta);

    switch(scelta){
        case 1:
            esito = 1;
            accoda(ingresso, uscita, genera_stringa());                 /* Continua l'inserimento, esito = 1 --> procede con l'esecuzione */
            visita((*uscita));
            break;
        case 2:                                                       /* Rimuove un elemento, esito = 1 --> procede con l'esecuzione */
            strcpy(rimosso, rimuovi(ingresso, uscita) -> dato);
            if(rimosso != NULL){
                printf("\nElemento rimosso: %s", rimosso);
                visita((*uscita));
            }
            esito = 1;
            break;
        case 3:                                                       /* Segnale di stop, esito = 0 --> termina l'esecuzione */
            esito = 0;                                                  
            break;
        default:
            printf("Scelta inesistente. Riprovare.\n");
            esito = 1;
            break;
    }
    
    
    return (esito);
}

char *genera_stringa(void){
    int i;
    char *generato = malloc(sizeof (char)*5),
          alfabeto[27] = "abcdefghijklmnopqrstuvwxyz";

    for(i = 0; i < 4; i++)
        generato[i] = alfabeto[rand() % 26];

    generato[4] = '\0';

    return generato;
}

void accoda(elem_lista_t **ingresso,
    elem_lista_t **uscita,
            char *valore){
    elem_lista_t *nuovo_p;
    nuovo_p = (elem_lista_t *) malloc(sizeof(elem_lista_t));
    
    strcpy(nuovo_p -> dato, valore);
    nuovo_p -> next_p = NULL;

    if(*uscita == NULL){
        *uscita = nuovo_p;
    }else{
        (*ingresso) -> next_p = nuovo_p;
    }
    *ingresso = nuovo_p;
}

void visita(elem_lista_t *testa){
    elem_lista_t *corr_p;

    for(corr_p = testa;
        (corr_p != NULL);
        corr_p = corr_p -> next_p){
        printf("%s\n", corr_p -> dato);
    }
}

elem_lista_t *rimuovi(elem_lista_t **ingresso_p, elem_lista_t **uscita_p){
    elem_lista_t *rimo_p;

    rimo_p = *uscita_p;

    if(*uscita_p != NULL){
        *uscita_p = (*uscita_p) -> next_p;

        if(*uscita_p == NULL)
            *ingresso_p = NULL;
    }
    

    return (rimo_p);
}
