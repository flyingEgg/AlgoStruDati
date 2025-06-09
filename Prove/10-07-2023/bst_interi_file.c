#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo_albero{
    int dato;
    struct nodo_albero *sx_p,
                       *dx_p;
}nodo_albero_t;

int inserisci_in_bst(nodo_albero_t **radice_p, int valore);
void visita_bst_sim(nodo_albero_t *nodo_p);
void visita_minori_di_x(nodo_albero_t *nodo_p, int x);
int rimuovi_da_bst(nodo_albero_t **radice_p, int valore);

int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./bst_reali_file <nome-del-file>\n");
        exit(-1);
    }

    char *nome_file = malloc(sizeof(char) * strlen(argv[1]));
    int n,
        i,
        val,
        scelta;
    nodo_albero_t *radice_p;
    FILE *fp;

    radice_p = NULL;

    strcpy(nome_file, argv[1]);

    fp = fopen(nome_file, "r");
    if(fp == NULL){
        printf("Errore di lettura del file %s\n", nome_file);
        exit(-1);
    }

    fscanf(fp, "%d", &n);
    printf("Avvio il parsing dei dati dal file %s...\n", nome_file);
    for (i = 0; i < n; i++){
        fscanf(fp, "%d", &val);
        inserisci_in_bst(&radice_p, val);
    }
    printf("\nParsing completato!\n");

    printf("VISITA IN ORDINE SIMMETRICO:\n");
    visita_bst_sim(radice_p);

    printf("Inserire un valore intero x: ");
    scanf("%d", &val);
    printf("\nValori minori di x:\n");
    visita_minori_di_x(radice_p, val);

    do{
        printf("Inserire valore da rimuovere: ");
        scanf("%d", &val);
        if(rimuovi_da_bst(&radice_p, val) != 1){
            printf("ERRORE: elemento non trovato; albero invariato.\n");
        }
        visita_bst_sim(radice_p);

        printf("\nRimuovere altri? (1 = si' 0 = no)\n");
        scanf("%d", &scelta);
    } while (scelta != 0);


    fclose(fp);
    free(nome_file);
    return 0;
}

int inserisci_in_bst(nodo_albero_t **radice_p, int valore){
    int inserito;
    nodo_albero_t *padre_p,
                  *nodo_p,
                  *nuovo_p;

    for(padre_p = nodo_p = *radice_p;
        ((nodo_p != NULL) && (nodo_p -> dato != valore));
        padre_p = nodo_p, nodo_p = (valore < nodo_p -> dato) ? nodo_p -> sx_p : nodo_p -> dx_p);

    if(nodo_p != NULL)
        inserito = 0;
    else{
        inserito = 1;

        nuovo_p = (nodo_albero_t *) malloc(sizeof (nodo_albero_t));
        nuovo_p -> dato = valore;
        nuovo_p -> sx_p = nuovo_p -> dx_p = NULL;

        if(padre_p == NULL)
            *radice_p = nuovo_p;
        else if(valore < padre_p -> dato)
            padre_p -> sx_p = nuovo_p;
        else
            padre_p -> dx_p = nuovo_p;
    }

    return inserito;
}

void visita_bst_sim(nodo_albero_t *nodo_p){
    if(nodo_p != NULL){
        visita_bst_sim(nodo_p -> sx_p);
        printf("%d\n", nodo_p -> dato);
        visita_bst_sim(nodo_p -> dx_p);
    }
}

void visita_minori_di_x(nodo_albero_t *nodo_p, int x){
    if(nodo_p != NULL){
        visita_minori_di_x(nodo_p -> sx_p, x);
        if(nodo_p -> dato <= x)
            printf("%d\n", nodo_p -> dato);
        visita_minori_di_x(nodo_p -> dx_p, x);
    }
}

int rimuovi_da_bst(nodo_albero_t **radice_p, int valore){
    int rimosso;
    nodo_albero_t *padre_p,
                  *nodo_p,
                  *sost_p;

    for(padre_p = nodo_p = *radice_p;
        ((nodo_p != NULL) && (nodo_p -> dato != valore));
        padre_p = nodo_p, nodo_p = (valore < nodo_p -> dato) ? nodo_p -> sx_p : nodo_p -> dx_p);

    if(nodo_p == NULL)
        rimosso = 0;
    else {
        rimosso = 1;

        if(nodo_p -> sx_p == NULL){
            if(nodo_p == *radice_p){
                *radice_p = nodo_p -> dx_p;
            }else if(valore < padre_p -> dato)
                padre_p -> sx_p = nodo_p -> dx_p;
            else
                padre_p -> dx_p = nodo_p -> dx_p;
        } else if(nodo_p -> dx_p == NULL){
            if(nodo_p == *radice_p){
                *radice_p = nodo_p -> sx_p;
            }else if(valore < padre_p -> dato)
                padre_p -> sx_p = nodo_p -> sx_p;
            else
                padre_p -> dx_p = nodo_p -> sx_p;
        } else {
            sost_p = nodo_p;
            for(padre_p = sost_p, nodo_p = nodo_p -> sx_p;
                (nodo_p -> dx_p != NULL);
                padre_p = nodo_p, nodo_p = nodo_p -> dx_p);

            sost_p -> dato = nodo_p -> dato;
            if(padre_p == sost_p)
                padre_p -> sx_p = nodo_p -> sx_p;
            else
                padre_p -> dx_p = nodo_p -> sx_p;
        }
        free(nodo_p);
    }

    return rimosso;
}
