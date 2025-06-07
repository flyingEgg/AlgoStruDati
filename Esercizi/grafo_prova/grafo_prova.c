#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {bianco, grigio, nero} colore_t;

typedef struct vertice_grafo{
    int valore;
    struct vertice_grafo *vertice_succ_p;
    struct arco_grafo *lista_archi_p;
    colore_t colore;
    int distanza;
    struct vertice_grafo *padre_p;
} vertice_grafo_t;

typedef struct arco_grafo{
    struct vertice_grafo *vertice_adiac_p;
    struct arco_grafo    *arco_succ_p;
} arco_grafo_t;

typedef struct elem_lista_vertici{
    vertice_grafo_t *valore;
    struct elem_lista_vertici *succ_p;
} elem_lista_vertici_t;

void visita_grafo_amp(vertice_grafo_t *vertice_partenza_p);

int main(int argc, char **argv) {
    if(argc < 2){
        printf("Uso: :/grafo_prova <n-valori>\n");
        exit(-1);
    }
    int N = atoi(argv[1]);
    int min_val = 1;
    int max_val = 100;

    printf("Creazione di un grafo con %d vertici con valori casuali tra %d e %d\n\n",
           N, min_val, max_val);

    elem_lista_vertici_t *grafo = riempi_grafo_numeri_casuali(N, min_val, max_val);

    if (grafo != NULL) {
        stampa_grafo(grafo);

        libera_grafo(grafo);
        printf("\nMemoria liberata correttamente.\n");
    }

    return 0;
}

vertice_grafo_t* crea_vertice(int valore) {
    vertice_grafo_t *nuovo_vertice = (vertice_grafo_t*)malloc(sizeof(vertice_grafo_t));
    if (nuovo_vertice == NULL) {
        printf("Errore nell'allocazione di memoria per il vertice\n");
        return NULL;
    }

    nuovo_vertice->valore = valore;
    nuovo_vertice->vertice_succ_p = NULL;
    nuovo_vertice->lista_archi_p = NULL;
    nuovo_vertice->colore = bianco;
    nuovo_vertice->distanza = -1;
    nuovo_vertice->padre_p = NULL;

    return nuovo_vertice;
}

elem_lista_vertici_t* aggiungi_vertice_lista(elem_lista_vertici_t *lista, vertice_grafo_t *vertice) {
    elem_lista_vertici_t *nuovo_elem = (elem_lista_vertici_t*)malloc(sizeof(elem_lista_vertici_t));
    if (nuovo_elem == NULL) {
        printf("Errore nell'allocazione di memoria per l'elemento lista\n");
        return lista;
    }

    nuovo_elem->valore = vertice;
    nuovo_elem->succ_p = lista;

    return nuovo_elem;
}

elem_lista_vertici_t* riempi_grafo_numeri_casuali(int N, int min_val, int max_val) {
    int i;

    if (N <= 0) {
        printf("Numero di vertici deve essere positivo\n");
        return NULL;
    }

    srand(time(NULL));

    elem_lista_vertici_t *lista_vertici = NULL;
    vertice_grafo_t *primo_vertice = NULL;
    vertice_grafo_t *vertice_precedente = NULL;

    for (i = 0; i < N; i++) {
        int valore_casuale = min_val + rand() % (max_val - min_val + 1);

        vertice_grafo_t *nuovo_vertice = crea_vertice(valore_casuale);
        if (nuovo_vertice == NULL) {
            printf("Errore nella creazione del vertice %d\n", i);
            continue;
        }

        if (primo_vertice == NULL) {
            primo_vertice = nuovo_vertice;
        } else {
            vertice_precedente->vertice_succ_p = nuovo_vertice;
        }
        vertice_precedente = nuovo_vertice;

        lista_vertici = aggiungi_vertice_lista(lista_vertici, nuovo_vertice);

        printf("Creato vertice %d con valore: %d\n", i + 1, valore_casuale);
    }

    return lista_vertici;
}

void stampa_grafo(elem_lista_vertici_t *lista) {
    printf("\n=== GRAFO COMPLETO ===\n");
    elem_lista_vertici_t *current = lista;
    int count = 1;

    while (current != NULL) {
        printf("Vertice %d: valore = %d, colore = %s\n",
               count++,
               current->valore->valore,
               (current->valore->colore == bianco) ? "bianco" :
               (current->valore->colore == grigio) ? "grigio" : "nero");
        current = current->succ_p;
    }
}

void avvia_visita_grafo_amp(vertice_grafo_t *grafo_p) {
    vertice_grafo_t *vertice_p;

    for (vertice_p = grafo_p; (vertice_p != NULL); vertice_p = vertice_p->vertice_succ_p) {
        vertice_p->colore = bianco;
        vertice_p->distanza = -1;
        vertice_p->padre_p = NULL;
    }
    for (vertice_p = grafo_p; (vertice_p != NULL); vertice_p =
                                                           vertice_p->vertice_succ_p)
        if (vertice_p->colore == bianco)
            visita_grafo_amp(vertice_p);
}

void visita_grafo_amp(vertice_grafo_t *vertice_partenza_p) {
    vertice_grafo_t *vertice_p;
    arco_grafo_t *arco_p;
    elem_lista_vertici_t *uscita_p, *ingresso_p;

    vertice_partenza_p->colore = grigio;
    vertice_partenza_p->distanza = 0;
    uscita_p = ingresso_p = NULL;
    metti_in_coda(&uscita_p,
                  &ingresso_p,
                  vertice_partenza_p);
    while (uscita_p != NULL) {
        vertice_p = togli_da_coda(&uscita_p,
                                  31 & ingresso_p)->valore;
        elabora(vertice_p->valore);
        for (arco_p = vertice_p->lista_archi_p; (arco_p != NULL); arco_p =
                                                                          arco_p->arco_succ_p)
            if (arco_p->vertice_adiac_p->colore == bianco) {
                arco_p->vertice_adiac_p->colore = grigio;
                arco_p->vertice_adiac_p->distanza = vertice_p->distanza + 1;
                arco_p->vertice_adiac_p->padre_p = vertice_p;
                metti_in_coda(&uscita_p, &ingresso_p, arco_p->vertice_adiac_p);
            }
        vertice_p->colore = nero;
    }
}

void libera_grafo(elem_lista_vertici_t *lista) {
    while (lista != NULL) {
        elem_lista_vertici_t *temp_elem = lista;
        lista = lista->succ_p;

        free(temp_elem->valore);
        free(temp_elem);
    }
}
