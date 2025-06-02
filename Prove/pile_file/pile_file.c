#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem_lista{
    char dato[5];
    struct elem_lista *next_p;
}elem_lista_t;

void impila(elem_lista_t **cima_p, char valore[5]);
void visita(elem_lista_t *testa_p);

int main(int argc, char **argv){
    if(argc < 3){
        printf("Uso: ./pile_file <n-di-stringhe-da-leggere> <nome-del-file>\n");
        exit(-1);
    }

    int n = atoi(argv[1]),
        i;
    char *nome_file = malloc(sizeof (char) * strlen(argv[2])),
         valore[5];
    elem_lista_t *testa_p;
    FILE *fp;

    testa_p = NULL;
    strcpy(nome_file, argv[2]);
    fp = fopen(nome_file, "r");

    if(fp == NULL){
        printf("Errore di lettura sul file \"%s\"\n", nome_file);
        free(nome_file);
        exit(-1);
    }

    for (i = 0; i < n; i++) {
        fscanf(fp, "%s", valore);
        impila(&testa_p, valore);
    }

    visita(testa_p);

    fclose(fp);
    free(nome_file);
    return 0;
}

void impila(elem_lista_t **cima_p, char valore[5]){
    elem_lista_t *nuovo_p;

    nuovo_p = (elem_lista_t *) malloc(sizeof(elem_lista_t));
    strcpy(nuovo_p -> dato, valore);
    nuovo_p -> next_p = *cima_p;
    *cima_p = nuovo_p;
}

void visita(elem_lista_t *testa_p){
    elem_lista_t *elem_p;

    printf("Elementi della lista:\n");
    for(elem_p = testa_p;
        (elem_p != NULL);
        elem_p = elem_p -> next_p){

        printf("%s\n", elem_p -> dato);
    }
}
