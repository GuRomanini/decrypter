#include <stdio.h>
#include <stdlib.h>

#include "TAD.h"

//funções de desencriptografia
void decrypt1(Lista* li) {
	Elem *knot = *li;
	while(knot != NULL) {
		knot->letter = knot->letter - 1;
        	knot = knot->prox;
	}
}

void decrypt2(Lista* li) {
	Elem *knot = *li;	
	while(knot != NULL) {
                knot->letter = knot->letter - 3;
        	knot = knot->prox;
	}
}

void decrypt3(Lista* li) {
	Elem *knot = *li;	
	int i = 1;
	while(knot != NULL) {
                knot->letter = knot->letter - i;
                knot = knot->prox;
                i++;
        	if(i == 4) i = 1;
	}
}

void decrypt4(Lista* li, char *key) {
	Elem *knot = *li;	
	int i = 0;
        while(knot != NULL) {
               	knot->letter = knot->letter - (key[i] - '0');
                knot = knot->prox;
                i++;
        	if(i == 5) i = 0;
	}
}

void decrypt5(Lista* li, char *key) {
	Elem *knot = *li;	
	int i = 0;
        while(knot != NULL) {
        	if(key[i] == '0') continue;
                knot->letter = knot->letter - (key[i] - '0');
                knot = knot->prox;
                i++;
                if(i == 5) i = 0;
        }
}
