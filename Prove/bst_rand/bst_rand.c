#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo_bst{
    int dato;
    struct nodo_bst *sx, *dx;
} nodo_bst_t;


void visita_simmetrico(nodo_bst_t *nodo_p);
void genera(nodo_bst_t **radice_p, int n);
int inserisci(nodo_bst_t **radice_p, int valore);

int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./bst_rand <n-dei-numeri>\n");
        exit(-1);
    }

    int n = atoi(argv[1]);
    nodo_bst_t *radice_p = NULL;

    srand(time(NULL));

    genera(&radice_p, n);

    visita_simmetrico(radice_p);

    return (0);
}

void genera(nodo_bst_t **radice_p, int n){
    int i, v;

    for(i = 0; i < n; i++){
        v = rand() % 2;
        inserisci(radice_p, v);
    }
}

int inserisci(nodo_bst_t **radice_p, int valore){
    int inserito;

    nodo_bst_t *nuovo_p,  /* ciò che sarà il nuovo nodo o foglia */
    *padre_p,  /* il padre del nodo attuale */
    *nodo_p;   /* nodo attuale (equivalente indice "i") */

    for(nodo_p = padre_p = *radice_p;
        ((nodo_p != NULL) && (nodo_p -> dato != valore));
        padre_p = nodo_p, nodo_p = (valore < nodo_p -> dato) ?
                                   nodo_p -> sx : nodo_p -> dx);


    if(nodo_p != NULL)
        inserito = 0;
    else{
        inserito = 1;

        nuovo_p = (nodo_bst_t *) malloc(sizeof(nodo_bst_t));
        nuovo_p -> dato = valore;
        nuovo_p -> sx = nuovo_p -> dx = NULL;

        if(nodo_p == *radice_p){
            *radice_p = nuovo_p;
        }else if (valore < padre_p -> dato){
            padre_p -> sx = nuovo_p;
        } else {
            padre_p -> dx = nuovo_p;
        }
    }
    return inserito;
}

void visita_simmetrico(nodo_bst_t *nodo_p){

    if(nodo_p != NULL){
        visita_simmetrico(nodo_p -> sx);
        printf("%d ", nodo_p -> dato);
        visita_simmetrico(nodo_p -> dx);
    }
}
