/* Prova del 13-01-2025 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elem_albero{
    double dato;
    struct elem_albero *sx_p,
                       *dx_p;
}nodo_albero_t;

int carica_in_bst(nodo_albero_t **radice_p, double valore);
void visita_anticipata(nodo_albero_t *radice_p);
void visita_simmetrica(nodo_albero_t *radice_p);

int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./bst_rand <n-elementi>");
        exit(-1);
    }

    int n = atoi(argv[1]),
        i,
        esito_caricamento;
    double nuovo_nodo;
    nodo_albero_t *radice_p;

    radice_p = NULL;
    srand(time(NULL));

    for(i = 0; i < n; i++){
        nuovo_nodo = (double)rand() / RAND_MAX;
        esito_caricamento = carica_in_bst(&radice_p, nuovo_nodo);
        if(esito_caricamento == 1)
            printf("Nodo caricato: %.2f\n", nuovo_nodo);
        else
            printf("Nodo già presente\n");
    }

    printf("\nVisita in ordine anticipato:\n");
    visita_anticipata(radice_p);

    printf("\nVisita in ordine simmetrico:\n");
    visita_simmetrica(radice_p);

    return(0);
}

int carica_in_bst(nodo_albero_t **radice_p, double valore){
    int esito;
    nodo_albero_t *nodo_p,
                  *padre_p,
                  *nuovo_p;

    for(padre_p = nodo_p = *radice_p;
        ((nodo_p != NULL) && (nodo_p -> dato != valore));
        padre_p = nodo_p, nodo_p = (valore < nodo_p -> dato) ?
                                   nodo_p -> sx_p : nodo_p -> dx_p);

    if(nodo_p != NULL){
        esito = 0;
    } else {
        esito = 1;

        nuovo_p = (nodo_albero_t *) malloc(sizeof(nodo_albero_t));
        nuovo_p -> dato = valore;

        if(padre_p == NULL)
            *radice_p = nuovo_p;
        else if(valore < padre_p -> dato)
            padre_p -> sx_p = nuovo_p;
        else
            padre_p -> dx_p = nuovo_p;
    }

    return(esito);
}

void visita_anticipata(nodo_albero_t *radice_p){
    if(radice_p != NULL){
        printf("%.2f\n", radice_p -> dato);
        visita_anticipata(radice_p -> sx_p);
        visita_anticipata(radice_p -> dx_p);
    }
}

void visita_simmetrica(nodo_albero_t *radice_p){
    if(radice_p != NULL){
        visita_simmetrica(radice_p -> sx_p);
        printf("%.2f\n", radice_p -> dato);
        visita_simmetrica(radice_p -> dx_p);
    }
}
