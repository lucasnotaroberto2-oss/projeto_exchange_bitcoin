#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*
void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
*/

int login(){
	char nome[50],cpf[11],senha[6],limpeza_de_buffer[1];
	int tamanho,i,c;
	bool achado;

	//abrir o arquivo de texto no modo append "a"
	while ((c = getchar()) != '\n' && c != EOF);
	printf("Digite seu nome: ");
	//scanf("%s",nome);
	fgets(nome, 50, stdin);
	
	while ((c = getchar()) != '\n' && c != EOF);
	printf("\nDigite seu cpf: ");
	fgets(cpf, 11, stdin);
	
	while(1){
		achado = false;
		while ((c = getchar()) != '\n' && c != EOF);
		printf("\nDigite sua senha(6 caracteres): ");
		scanf("%s",senha);
		
		tamanho = strlen(senha);
		if(tamanho != 6){
			printf("\nA senha precisa ter 6 caracteres!\n");
			continue;
		}
		else{
			for( i = 0; i < 6; i++){
				if(isalpha(senha[i])){
					achado = true;
					printf("\nA senha precisa ter 6 numeros\n");
					break;
				}
			}
			if(achado){
				continue;
			}
		}
		
	}
	
	//escrever as variaveis no arquivo
	//fechar o arquivo
	system("pause");
	return 0;
}
