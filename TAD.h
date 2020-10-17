#include <stdio.h>
#include <stdlib.h>

typedef char data;

struct elemento {
    data letter;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, char letter);
void imprime_lista(Lista* li);
