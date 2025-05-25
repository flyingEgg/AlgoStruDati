#include <stdio.h>
#include <stdlib.h>

typedef struct elem_albero{
    int dato;
    struct elem_albero *sx, *dx;
} elem_albeo_t;

void parse_file(elem_albeo_t **radice_p);
int inserisci_in_bst(elem_albeo_t **radice_p, int valore);
void visita_bst_sim(elem_albeo_t *radice_p);

int main(void){
    elem_albeo_t *radice;

    radice = NULL;

    parse_file(&radice);
    printf("\n");
    visita_bst_sim(radice);

    return (0);
}

void parse_file(elem_albeo_t **radice_p) {
    int n, i, valore;
    FILE *fp;

    fp = fopen("dati.txt", "r");
    fscanf(fp, "%d", &n);
    for (i = 0;
         (i < n);
         i++) {
        fscanf(fp, "%d", &valore);
        inserisci_in_bst(radice_p, valore);
    }
    fclose(fp);
}

int inserisci_in_bst(elem_albeo_t **radice_p, int valore){
    int inserito;
    elem_albeo_t *nuovo_p, *nodo_p, *padre_p;

    for(nodo_p = padre_p = *radice_p;
        ((nodo_p != NULL) && (nodo_p -> dato != valore));
        nodo_p = (valore < nodo_p -> dato) ?
                 nodo_p -> sx : nodo_p -> dx);


    if(nodo_p != NULL){
        inserito = 0;
    } else {
        inserito = 1;

        nuovo_p = (elem_albeo_t *) malloc(sizeof (elem_albeo_t));
        nuovo_p -> dato = valore;
        nuovo_p -> sx = nuovo_p -> dx = NULL;

        if(padre_p == NULL)
            *radice_p = nuovo_p;
        else if (valore < padre_p -> dato)
            padre_p -> sx = nuovo_p;
        else
            padre_p -> dx = nuovo_p;
    }

    return (inserito);
}

void visita_bst_sim(elem_albeo_t *radice_p){
    if(radice_p != NULL){
        visita_bst_sim(radice_p -> sx);
        printf("%d ", radice_p -> dato);
        visita_bst_sim(radice_p -> dx);
    }
}
