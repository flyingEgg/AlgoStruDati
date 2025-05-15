#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct elem_lista{
    char dato[5];
    struct elem_lista *succ_p;
} elem_lista_t;

void accoda_elemento(elem_lista_t **ingresso, elem_lista_t **uscita, char valore[5]);
char *genera_stringa();
void visita(elem_lista_t *testa);

/* NB: per test rapidi a casa ho inserito n da *
 * riga di comando invece che da tastiera. Da non *
 * replicare all'esame */
int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso corretto: ./coda_stringhe_rand <numero-elementi>\n");
        exit(-1);
    }

    int n = atoi(argv[1]), i;
    char *valore;
    elem_lista_t *testa, *coda;
    testa = coda = NULL;

    srand(time(NULL));

    for(i = 0; i <= n; i++){
        valore = genera_stringa();
        accoda_elemento(&coda, &testa, valore);
    }


    visita(testa);

    return 0;
}

void visita(elem_lista_t *testa){
    elem_lista_t *corrente_p;

    for (corrente_p = testa;
        (corrente_p != NULL);
        corrente_p = corrente_p -> succ_p) {
        printf("%s\n", corrente_p -> dato);
    }
}


void accoda_elemento(elem_lista_t **ingresso, elem_lista_t **uscita, char valore[5]){
    elem_lista_t *nuovo_p;
    nuovo_p = (elem_lista_t *) malloc(sizeof (elem_lista_t));

    strcpy(nuovo_p -> dato, valore);
    nuovo_p -> succ_p = NULL;

    if(*ingresso != NULL){
        (*ingresso) -> succ_p = nuovo_p;
    } else {
        *uscita = nuovo_p;
    }
    *ingresso = nuovo_p;

    free(nuovo_p);
}

char *genera_stringa(){
    int i;
    char *generata = malloc(sizeof (char) * 5);


    for(i = 0; i < 4; i++){
        generata[i] = (rand() % 25) + 97;
    }
    generata[4] = '\0';
    return generata;
}


