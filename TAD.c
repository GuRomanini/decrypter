#include <stdio.h>
#include <stdlib.h>

#include "TAD.h"

//rotinas de TAD necessárias no programa
Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li) {
    if(li != NULL) {
        Elem* no;
        while((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, char letter) {
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->letter = letter;
    no->prox = NULL;
    if((*li) == NULL) {
        *li = no;
    } else {
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

void imprime_lista(Lista* li) {
    if(li == NULL) return;
    Elem* no = *li;
    while(no != NULL){
        printf("%c", no->letter);
        no = no->prox;
    }
}
