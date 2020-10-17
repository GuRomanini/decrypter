#include <stdio.h>
#include <stdlib.h>

#include "TAD.h"

//funções de criptografia
void crypt1(Lista* li) {
	Elem *knot = *li;	
	while(knot != NULL) {
		knot->letter = knot->letter + 1;
		knot = knot->prox;
	}
}

void crypt2(Lista* li) {
	Elem *knot = *li;
	while(knot != NULL) {
                knot->letter = knot->letter + 3;
        	knot = knot->prox;
        }
}

void crypt3(Lista* li) {
	Elem *knot = *li;
	int i = 1;
	while(knot != NULL) {
        	knot->letter = knot->letter + i;
                knot = knot->prox;
		i++;
		if(i == 4) i = 1;
        }
}

void crypt4(Lista* li, char *key) {
	Elem *knot = *li;	
	int i = 0;
        while(knot != NULL) {
        	knot->letter = knot->letter + (key[i] - '0');
                knot = knot->prox;
                i++;
                if(i == 5) i = 0;
        }
}

void crypt5(Lista* li, char *key) {
	Elem *knot = *li;	
	int i = 0;
	int j = 0;
        while(knot != NULL) {
		if(key[i] == 48) continue;
		if(j == 3) {
			j = 0;
			knot = knot->prox;
			continue;
		}
        knot->letter = knot->letter + (key[i] - '0');
        knot = knot->prox;
        i++;
	j++;
        if(i == 5) i = 0;
	}
}
