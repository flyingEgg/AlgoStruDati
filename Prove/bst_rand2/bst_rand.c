#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo_albero{
    int dato;
    struct nodo_albero *sx_p,
                       *dx_p;
}nodo_albero_t;

int inserisci(nodo_albero_t **radice_p, int valore);
void visita_ordine_posticipato(nodo_albero_t *nodo_p);
void cerca_minori_di_x(nodo_albero_t *nodo_p, int x);

int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./bst_rand <n-nodi>\n");
        exit(-1);
    }

    int n = atoi(argv[1]), i, val;
    nodo_albero_t *radice_p;

    radice_p = NULL;
    srand(time(NULL));

    for(i = 0; i < n; i++){
        val = 10 + rand() % 41;
        if(inserisci(&radice_p, val) == 1)
            printf("%d e\' stato inserito.\n", val);
        else
            printf("Rilevato duplicato %d; non inserito.\n", val);
    }

    printf("\nVisita in ordine posticipato:\n");
    visita_ordine_posticipato(radice_p);

    printf("Digita un valore reale: ");
    scanf("%d", &val);

    cerca_minori_di_x(radice_p, val);

    return 0;
}

int inserisci(nodo_albero_t **radice_p, int valore){
    int inserito;
    nodo_albero_t *nodo_p,
                  *padre_p,
                  *nuovo_p;
    for(padre_p = nodo_p = *radice_p;
        ((nodo_p != NULL) && (valore != nodo_p -> dato));
        padre_p = nodo_p, nodo_p = (valore < nodo_p -> dato) ? nodo_p -> sx_p : nodo_p -> dx_p);

    if(nodo_p != NULL){
        inserito = 0;
    } else {
        inserito = 1;

        nuovo_p = (nodo_albero_t *) malloc(sizeof(nodo_albero_t));
        nuovo_p -> dato = valore;
        nuovo_p -> sx_p = nuovo_p -> dx_p = NULL;

        if(padre_p == NULL){
            *radice_p = nuovo_p;
        } else if(nuovo_p -> dato < padre_p -> dato){
            padre_p -> sx_p = nuovo_p;
        } else
            padre_p -> dx_p = nuovo_p;
    }
    return inserito;
}

void visita_ordine_posticipato(nodo_albero_t *nodo_p){
    if(nodo_p != NULL){
        visita_ordine_posticipato(nodo_p -> sx_p);
        visita_ordine_posticipato(nodo_p -> dx_p);
        printf("%d\n", nodo_p -> dato);
    }
}

void cerca_minori_di_x(nodo_albero_t *nodo_p, int x){
    if(nodo_p == NULL)
        return;

    if(nodo_p -> dato <= x){
        cerca_minori_di_x(nodo_p -> sx_p, x);
        printf("\n%d", nodo_p -> dato);
    }
    if(nodo_p -> dx_p != NULL)
        cerca_minori_di_x(nodo_p -> dx_p, x);
}
