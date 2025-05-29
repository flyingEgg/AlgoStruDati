/* Esercizio inventato 1 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct elem_lista{
    int dato;
    struct elem_lista *next_p;
}elem_lista_t;

void accoda(elem_lista_t **ingresso_p, elem_lista_t **uscita_p, int valore);
elem_lista_t *rimovi(elem_lista_t **uscita_p, elem_lista_t **ingresso_p);
void visita(elem_lista_t *testa_p);

int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./code_rand <nome-del-file>\n");
        exit(-1);
    }

    char *nome_file = malloc(sizeof(char) * (strlen(argv[1]) + 1));
    int n,
        i,
        elemento,
        scelta;
    elem_lista_t *testa_p,
                 *coda_p,
                 *rimosso_p;
    FILE *fp;

    strcpy(nome_file, argv[1]);

    fp = fopen(nome_file, "r");
    if(fp == NULL){
        printf("File inesistente.\n");
        exit(-1);
    }

    testa_p = coda_p = NULL;

    fscanf(fp, "%d", &n);
    for(i = 0; i < n; i++){
        fscanf(fp, "%d", &elemento);
        accoda(&coda_p, &testa_p, elemento);
    }

    printf("\nElementi della coda:\n");
    visita(testa_p);

    do{
        printf("1) rimuovi un elemento\n");
        printf("2) termina esecuzione\n");
        scanf("%d", &scelta);
        if(scelta == 1){
            if(testa_p != NULL)
                rimosso_p = rimovi(&testa_p, &coda_p);
            else{
                printf("Nient'altro da rimuovere\n");
                break;
            }
            printf("elemento rimosso: %d\n\n", rimosso_p -> dato);
            free(rimosso_p);
            visita(testa_p);
        }
    } while (scelta == 1);

    free(nome_file);
    return(0);
}

void accoda(elem_lista_t **ingresso_p, elem_lista_t **uscita_p, int valore){
    elem_lista_t *nuovo_p;

    nuovo_p = (elem_lista_t *) malloc(sizeof(elem_lista_t));
    nuovo_p -> dato = valore;
    nuovo_p -> next_p = NULL;

    if(*uscita_p == NULL){
        *uscita_p = nuovo_p;
    } else {
        (*ingresso_p) -> next_p = nuovo_p;
    }
    *ingresso_p = nuovo_p;
}

void visita(elem_lista_t *testa_p){
    elem_lista_t *elem_p;

    for(elem_p = testa_p;
        (elem_p != NULL);
        elem_p = elem_p -> next_p)
        printf("%d\n", elem_p -> dato);
}

elem_lista_t *rimovi(elem_lista_t **uscita_p, elem_lista_t **ingresso_p){
    elem_lista_t *rimosso_p;
    rimosso_p = *uscita_p;

    if(*uscita_p != NULL){
        *uscita_p = (*uscita_p) -> next_p;

        if(*uscita_p == NULL){
            *ingresso_p = NULL;
        }
    }

    return rimosso_p;
}
