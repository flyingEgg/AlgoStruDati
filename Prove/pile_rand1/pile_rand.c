/* Prova del 06-02-2024 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elem_lista{
    int dato;
    struct elem_lista *next_p;
}elem_lista_p;

void genera_rand(int n, elem_lista_p **cima_p);
void impila(elem_lista_p **cima_p, int valore);
void visita(elem_lista_p *testa);

int main(int argc, char **argv){
    if(argc < 2){
        printf("Uso: ./pile_rand <numero>\n");
        exit(-1);
    }

    int n = atoi(argv[1]);
    elem_lista_p *cima_p1,
                 *cima_p2;
    double somma;

    cima_p1 = cima_p2 = NULL;

    srand(time(NULL));

    genera_rand(n, &cima_p1);
    genera_rand(n, &cima_p2);

    visita(cima_p1);
    visita(cima_p2);

    somma = cima_p1 -> dato + cima_p2 -> dato;
    printf("\nSomma dei valori piu' recenti: %f\n", somma);

    return (0);
}

void genera_rand(int n, elem_lista_p **cima_p){
    int i;
    double generato;

    for(i = 0; i < n; i++){
        generato = rand() % 2;
        impila(cima_p, generato);
    }
}

void impila(elem_lista_p **cima_p, int valore){
    elem_lista_p *nuovo_p;
    nuovo_p = (elem_lista_p *) malloc(sizeof(elem_lista_p));
    nuovo_p -> dato = valore;
    nuovo_p -> next_p = *cima_p;

    *cima_p = nuovo_p;
}

void visita(elem_lista_p *testa){
    elem_lista_p *curr_p;

    printf("\nElementi lista:\n");
    for(curr_p = testa;
    (curr_p != NULL);
    curr_p = curr_p -> next_p){
        printf("%d\n", curr_p -> dato);
    }
}
