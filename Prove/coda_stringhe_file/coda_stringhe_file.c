#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct elem_lista {
    char dato[6];
    struct elem_lista *succ_p;
} elem_lista_p;

void accoda(elem_lista_p **uscita, elem_lista_p **entrata, char valore[]);
void visita(elem_lista_p *testa);

int main(){
    FILE *file_p;
    elem_lista_p *testa, *coda, *elem_p;
    int n, i;
    char valore[6];

    testa = coda = NULL;

    file_p = fopen("dati.txt", "r");
    fscanf(file_p, "%d", &n);


    for(i = 0; i < n; i++){
        fscanf(file_p, "%s\n", valore);
        printf("Dato acquisito: %s\n", valore);
        accoda(&testa, &coda, valore);
    }

    visita(testa);

    fclose(file_p);
    return 0;
}

void accoda(elem_lista_p **uscita, elem_lista_p **entrata, char valore[]){
    elem_lista_p *nuovo_p;
    nuovo_p = (elem_lista_p *) malloc(sizeof(elem_lista_p));

    strcpy(nuovo_p -> dato, valore);
    nuovo_p -> succ_p = NULL;

    if(*entrata != NULL){
        (*entrata) -> succ_p = nuovo_p;
    } else {
        *uscita = nuovo_p;
    }

    *entrata = nuovo_p;
}


void visita(elem_lista_p *testa){
    elem_lista_p *current_p;

    for(current_p = testa; (current_p != NULL); current_p = current_p->succ_p){
        printf("%s\n", current_p->dato);
    }
}

