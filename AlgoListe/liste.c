#include <stdio.h>


typedef struct elem_lista
{
    int valore;
    struct elem_lista_dc *succ_p;
} elem_lista_t;


void visita_lista(elem_lista_t *testa_p);
elem_lista_t* cerca_in_lista(elem_lista_t *testa_p, int valore);
void elabora(int v);

int main(){

}

void visita_lista(elem_lista_t *testa_p){
    elem_lista_t *elem_p;

    for(elem_p = testa_p;
        elem_p != NULL;
        elem_p = elem_p -> succ_p){

        elabora(elem_p->valore);
    }
}

elem_lista_t* cerca_in_lista(elem_lista_t *testa_p, int valore){
    elem_lista_t *elem_p;

    for(elem_p = testa_p; ((elem_p != NULL) && (elem_p -> valore != valore)) ; elem_p = elem_p -> succ_p);
    return elem_p;
}
