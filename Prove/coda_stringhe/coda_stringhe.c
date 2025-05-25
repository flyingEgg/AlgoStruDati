#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct elem_lista{
    char dato[5];
    struct elem_lista *next_p;
} elem_lista_t;

int menu(void);
char *genera_stringa(void);
void accoda(elem_lista_t **ingresso, elem_lista_t **uscita, char *valore);
void visita(elem_lista_t *testa);

int main(void){
    int n, i;
    char valore[5];
    elem_lista_t *testa,
                 *coda;
    testa = coda = NULL;
    srand(time(NULL));


    printf("Digitare il numero di stringhe\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        strcpy(valore, genera_stringa());
        accoda(&coda, &testa, valore);
    }

    visita(testa);

    return(0);
}

int menu(void){
    int scelta,
        esito;
    
    printf("\nMENU\n
            1. Inserisci\n
            2. Rimuovi\n
            3. Esci\n");
    
    switch(scelta){
        case 1:
            
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
    
    
    return (0);
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
