#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_albero_bin {
    int dato;
    struct nodo_albero_bin *sx_p, *dx_p;
} nodo_albero_bin_t;

int main() {

}

int rimuovi_da_albero_bin_ric(nodo_albero_bin_t **radice_p, int valore) {
    int rimosso;
    nodo_albero_bin_t *nodo_p, *padre_p, *sost_p;

    /* Cerca il nodo contenente il valore da rimuovere */
    for (nodo_p = padre_p = *radice_p;
         ((nodo_p != NULL) && (nodo_p->dato != valore));
         padre_p = nodo_p, nodo_p = (valore < nodo_p->dato) ?
                                    nodo_p->sx_p : nodo_p->dx_p);

    /* Se il nodo non esiste , restituisce 0 */
    if (nodo_p == NULL)
        rimosso = 0;
    else {
        rimosso = 1;

        /* Caso 1: nodo con al massimo un figlio ( destro ) */
        if (nodo_p->sx_p == NULL) {
            if (nodo_p == *radice_p)
                *radice_p = nodo_p->dx_p;
            else if (valore < padre_p->dato)
                padre_p->sx_p = nodo_p->dx_p;
            else
                padre_p->dx_p = nodo_p->dx_p;
        }
            /* Caso 2: nodo con solo figlio sinistro */
        else if (nodo_p->dx_p == NULL) {
            if (nodo_p == *radice_p)
                *radice_p = nodo_p->sx_p;
            else if (valore < padre_p->dato)
                padre_p->sx_p = nodo_p->sx_p;
            else
                padre_p->dx_p = nodo_p->sx_p;
        }
            /* Caso 3: nodo con due figli */
        else {
            /* Trova il predecessore ( massimo del sottoalbero sinistro ) */
            sost_p = nodo_p;
            for (padre_p = sost_p, nodo_p = sost_p->sx_p;
                 (nodo_p->dx_p != NULL);
                 padre_p = nodo_p, nodo_p = nodo_p->dx_p);

            /* Sostituisce il valore e riconnette i nodi */
            sost_p->dato = nodo_p->dato;
            if (padre_p == sost_p)
                padre_p->sx_p = nodo_p->sx_p;
            else
                padre_p->dx_p = nodo_p->sx_p;
        }
        /* Libera la memoria del nodo rimosso */
        free(nodo_p);
    }
    return (rimosso);
}
