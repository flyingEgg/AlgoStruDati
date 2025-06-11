/* Giacomo Rossi 314671 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elem_lista{
	double dato;				   /* Dato corrispondente all'elemento */
	struct elem_lista *prossimo_p;		   /* Puntatore all'elemento successivo */
}elem_lista_t;

/* Dichiarazione delle firme delle funzioni */
void aggiungi_a_pila(elem_lista_t **cima_p, double valore);       
elem_lista_t *rimuovi_da_pila(elem_lista_t **cima_p);
void visita(elem_lista_t *testa_p);

/* Funzione principale */
int main(){
	int n, i;
	double val;
	elem_lista_t *testa_p,
		     *rimosso_p;

	srand(time(NULL));		/* Inizializzo il generatore di valori pseudo-casuali */
	testa_p = NULL;			/* Inizializzo NULL il puntatore alla testa della lista */

	printf("Digitare un numero intero N: ");
	scanf("%d", &n);

	printf("\n%d Valori\n", n);
	for(i = 0;
	   (i < n);
	   i++){
		val = 10 + ((double) rand() / RAND_MAX * 10);
		printf("Aggiungo \"%f\" alla pila.\n", val);
		aggiungi_a_pila(&testa_p, val);
	}

	printf("\nELEMENTI NELLA PILA:\n");
	visita(testa_p);

	printf("\nAvvio rimozione elementi...\n");
	for(i = 0; i < n; i++){
		rimosso_p = rimuovi_da_pila(&testa_p);
		if(rimosso_p == NULL){
			printf("La pila e' gia' vuota.\n");
			break;
		} else {
			printf("Elemento \"%f\" rimosso.\n", rimosso_p -> dato);
			free(rimosso_p);						/* Libero la memoria occupata dall'elemento rimosso dalla pila */
		}
	}

	printf("\nPILA DOPO RIMOZIONI:\n");
	visita(testa_p);

	return 0;
}

/* Funzione per aggiungere un singolo valore alla pila */
void aggiungi_a_pila(elem_lista_t **cima_p, double valore){
	elem_lista_t *nuovo_p;

	nuovo_p = (elem_lista_t *) malloc(sizeof(elem_lista_t));	/* Alloco la memoria per il nuovo elemento */
	nuovo_p -> dato = valore;				 	/* Salvo il valore dentro il nuovo elemento */
	nuovo_p -> prossimo_p = *cima_p;				/* Salvo il puntatore al prossimo elemento */
	*cima_p = nuovo_p;						/* Aggiorno il puntatore della cima al nuovo elemento */
}

/* Funzione per stampare a video la pila */
void visita(elem_lista_t *testa_p){
	elem_lista_t *elem_p;

	if(testa_p != NULL)
		for(elem_p = testa_p;
	    	   (elem_p != NULL);
	    	    elem_p = elem_p -> prossimo_p)
			printf("%f\n", elem_p -> dato);
	else
		printf("pila vuota\n");
}

/* Funzione per rimuovere un singolo valore dalla pila */
elem_lista_t *rimuovi_da_pila(elem_lista_t **cima_p){
	elem_lista_t *rimosso_p;

	rimosso_p = *cima_p;						/* Tengo traccia del puntatore all'elemento da rimuovere */
	*cima_p = (*cima_p) -> prossimo_p;				/* Aggiorno il puntatore della cima */
	return rimosso_p;						/* Restituisco il riferimento all'elemento che e' stato rimosso */
}

