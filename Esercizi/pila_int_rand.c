#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Struttura dati pila */
typedef struct nodoPila {
    int dato;
    struct nodoPila *nodoSucc;
} nodoPilaType;

typedef struct {
    nodoPilaType *top;
} Pila;

/* Prototipi funzioni ausiliarie */
void inizializzaPila(Pila *pila);
int push(Pila *pila, int valore);
int pop(Pila *pila, int *valore);
void visitaPila(Pila *pila);
void freePila(Pila *pila);
void valoriMaggioriUguali(Pila *pila, int x);

/* Funzione principale */
int main(void) {
    Pila miaPila;
    inizializzaPila(&miaPila);

    int N, x;

    /* Acquisizione di un numero intero N */
    printf("Inserisci il numero di elementi (N): ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Il numero di elementi deve essere maggiore di zero.\n");
        return 1;
    }

    /* Generazione casuale di N numeri e caricamento nella pila */
    srand(time(NULL));
    int i;
    for (i = 0; i < N; i++) {
        int valore = rand() % (10 * N + 1);
        push(&miaPila, valore);
    }

    /* Stampa dei valori contenuti nella pila */
    printf("Contenuto della pila:\n");
    visitaPila(&miaPila);

    /* Acquisizione di un numero intero x */
    printf("\nInserisci un valore x: ");
    scanf("%d", &x);

    /* Calcolo e stampa dei valori >= x */
    printf("\nValori nella pila maggiori o uguali a %d:\n", x);
    valoriMaggioriUguali(&miaPila, x);

    /* Libero la memoria */
    freePila(&miaPila);
    return(0);
}

/* Inizializza una pila vuota */
void inizializzaPila(Pila *pila) {
    pila->top = NULL;
}

/* Inserisce un elemento nella pila (push) */
int push(Pila *pila, int valore) {
    nodoPilaType *nuovoNodo = (nodoPilaType *)malloc(sizeof(nodoPilaType));
    if (nuovoNodo == NULL) {
        return(0);
    }
    nuovoNodo->dato = valore;
    nuovoNodo->nodoSucc = pila->top;
    pila->top = nuovoNodo;
    return(1);
}

/* Rimuove un elemento dalla pila (pop) */
int pop(Pila *pila, int *valore) {
    if (pila->top == NULL) {
        return(0);
    }

    nodoPilaType *nodoDaRimuovere = pila->top;
    *valore = nodoDaRimuovere->dato;

    pila->top = nodoDaRimuovere->nodoSucc;
    free(nodoDaRimuovere);
    return(1);
}

/* Visita la pila stampando tutti gli elementi */
void visitaPila(Pila *pila) {
    nodoPilaType *corrente = pila->top;
    while (corrente != NULL) {
        printf("%d ", corrente->dato);
        corrente = corrente->nodoSucc;
    }
    printf("\n");
}

/* Libera tutta la memoria occupata dalla pila */
void freePila(Pila *pila) {
    int valore;
    while (pop(pila, &valore));
}

/* Stampa tutti i valori nella pila maggiori o uguali a x */
void valoriMaggioriUguali(Pila *pila, int x) {
    nodoPilaType *corrente = pila->top;
    while (corrente != NULL) {
        if (corrente->dato >= x) {
            printf("%d ", corrente->dato);
        }
        corrente = corrente->nodoSucc;
    }
    printf("\n");
}

