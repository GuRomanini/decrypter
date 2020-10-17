#include <stdio.h>
#include <stdlib.h>

#include "TAD.h"
#include "crypt.h"
#include "decrypt.h"

int main() {
	//printa as intruções do programa
	system("clear || cls");
	printf("Bem vindo ao Decrypter!!! =)\n\n\n");
	printf("Opcao 1: criptografa a mensagem no estilo cifra de Cesar, deslocando 1 caractere;\n");
	printf("Opcao 2: criptografa a mensagem no estilo cifra de Cesar, deslocando 3 caracteres;\n");
	printf("Opcao 3: criptografa a mensagem no estilo cifra de Cesar, deslocando 1, 2, 3, 4 e 5 caracteres, repetidamente;\n");
	printf("Opcao 4: criptografa a mensagem deslocando caracteres e utilizando uma chave simetrica de 5 digitos (e.g.: 13524);\n");
	printf("Opcao 5: criptografa a mensagem nos mesmos moldes da opcao 4, porem insere um * a cada 3 caracteres;\n\n");
	printf("Opcao -1: descriptografa a mensagem criptografada pela opcao 1;\n");
	printf("Opcao -2: descriptografa a mensagem criptografada pela opcao 2;\n");
	printf("Opcao -3: descriptografa a mensagem criptografada pela opcao 3;\n");
	printf("Opcao -4: descriptografa a mensagem criptografada pela opcao 4;\n");
	printf("Opcao -5: descriptografa a mensagem criptografada pela opcao 5;\n\n");
	printf("Digite a opcao desejada e, em seguida, pressione Enter: ");
	int command;
	char key[7];
	//recebe a opção desejada
	scanf("%d", &command);
	//recebe a chave, caso seja necessário
	if((command == -4) || (command == -5) || (command == 4) || (command == 5)) {
		printf("Digite a chave de criptografacao/descriptografacao: ");
		setbuf(stdin, NULL);
		fgets(key, 7, stdin); 
	}
	//recebe a mensagem a ser criptografada/descriptografada e cria a lista dinâmica
	printf("\nDigite a mensagem a ser criptografada/descriptografada: ");
	char message[1024];
	setbuf(stdin, NULL);
	fgets(message, 1024, stdin);
	Lista* listPointer = cria_lista();
	int i = 0;
	int j = 0;
	//insere a mensagem na lista dinâmica
	while ((message[i] != '\n') && (message[i] != '\r') && (message[i] != 13)) {
		insere_lista_final(listPointer, message[i]);
		//caso a opção escolhida seja 5, insere um * a cada 3 caracteres inseridos
		if(command == 5) {
			j++;
			if(j == 3) {
			       	j = 0;
				insere_lista_final(listPointer, '*');
			}
		}
		//caso a opção escolhida seja -5, pula os * no meio da mensagem, sem inserí-los na lista
		if(command == -5) {
                        j++;
                        if(j == 3) {
                                j = 0;
                                i += 2;
                                continue;
                        }
                }
		i++;
	}
	//criptografa ou desencriptografa a mensagem, dependendo da opção escolhida
	switch(command) {
		case 1:
			crypt1(listPointer);
			printf("\n");
			imprime_lista(listPointer);
			libera_lista(listPointer);
			break;
		case -1:
			decrypt1(listPointer);
			printf("\n");
            imprime_lista(listPointer);
			libera_lista(listPointer);
			break;
		case 2:
			crypt2(listPointer);
			printf("\n");
            imprime_lista(listPointer);
			libera_lista(listPointer);
			break;
		case -2:
			decrypt2(listPointer);
			printf("\n");
            imprime_lista(listPointer);
			libera_lista(listPointer);
			break;
		case 3:
			crypt3(listPointer);
			printf("\n");
			imprime_lista(listPointer);
			libera_lista(listPointer);
			break;
		case -3:
			decrypt3(listPointer);
			printf("\n");
            imprime_lista(listPointer);
			libera_lista(listPointer);
			break;
		case 4:
			crypt4(listPointer, key);
			printf("\n");
            imprime_lista(listPointer);
			libera_lista(listPointer);
			break;
		case -4:
			decrypt4(listPointer, key);
			printf("\n");
            imprime_lista(listPointer);
			libera_lista(listPointer);
			break;
		case 5:
			crypt5(listPointer, key);
			printf("\n");
            imprime_lista(listPointer);
			libera_lista(listPointer);
                        break;
		case -5:
			decrypt5(listPointer, key);
			printf("\n");
            imprime_lista(listPointer);
			libera_lista(listPointer);
			break;
	}
	return 0;
}