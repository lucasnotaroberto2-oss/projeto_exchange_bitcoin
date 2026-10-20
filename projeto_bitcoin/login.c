#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

int verifica_usuario(char cpf[],char senha[]){
	char linha[200];
	
	FILE *usuarios;
	usuarios = fopen("usuarios.txt","r");
	
	if(usuarios == NULL){
		return 0;
	}
	
	while(fgets(linha, sizeof(linha), usuarios) != NULL){
		char *id = strtok(linha, ";");
		char *nome = strtok(NULL, ";");
		char *registro = strtok(NULL, ";");
		char *fsenha = strtok(NULL, ";\r\n");
		
		if(strcmp(registro,cpf) == 0){
			if(strcmp(fsenha,senha) == 0){
				fclose(usuarios);
				return 1;
			}
		}
	}
	
	fclose(usuarios);
	return 0;	
}

int login(){
	char cpf[12], senha[7];
	
	while(1){	
		printf("\nDigite seu cpf: ");
		fgets(cpf, sizeof(cpf), stdin);
		cpf[strcspn(cpf, "\n")] = '\0';
		limpar_buffer();
		
		printf("\nDigite sua senha: ");
		fgets(senha, sizeof(senha), stdin);
		senha[strcspn(senha, "\n")] = '\0';
		
		if(verifica_usuario(cpf,senha)){
			break;
		}
		printf("\nCPF e/ou senha nao encontrados\n");
	}
	
	printf("\nBem vindo ao site!\n");
	return 1;
}

