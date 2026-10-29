#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

int verifica_senha(int id){
	char linha[200];
	int senha;
	
	FILE *usuarios;
	usuarios = fopen("usuarios.txt","r");
	
	printf("\nDigite a sua senha: ");
	scanf("%d",&senha);
	limpar_buffer();
	
	
	while(fgets(linha,sizeof(linha),usuarios) != NULL){
		char *fid = strtok(linha, ";"); //retorna apenas a primeira separacao, no caso o nome do usuario
		char *nome = strtok(NULL, ";"); //retorna a segunda comparacao a partir do momento em que a primeira parou
		char *registro = strtok(NULL, ";");
		char *fsenha = strtok(NULL, "\r\n");
		
		int verifica_id = atoi(fid);
		int verifica_senha = atoi(fsenha);
		
		if(verifica_id == id){
			if(verifica_senha == senha){
				printf("\n\nSenha correta\n");
				return 1;
			}
		} 
	}
	
	printf("\n\nSenha incorreta\n");
	return 0;
}
