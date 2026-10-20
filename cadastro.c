#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

int valida_senha(char senha[]){
	int i;
	if(strlen(senha) != 6){
		return 0;
	}
	for(i = 0; i < 6;i++){
		if(!isdigit(senha[i])){
			return 0;
		}
	}
	return 1;
}

int valida_cpf(char cpf[]){
	char linha[100];
	
	FILE *usuarios;
	usuarios = fopen("usuarios.txt","r");
	
	if(usuarios == NULL){
		return 1;
	}
	
	while(fgets(linha, sizeof(linha), usuarios) != NULL){
		char *id = strtok(linha, ";"); //retorna apenas a primeira separacao, no caso o nome do usuario
		char *nome = strtok(NULL, ";"); //retorna a segunda comparacao a partir do momento em que a primeira parou
		char *registro = strtok(NULL, ";");
		
		if(registro != NULL){
			registro[strcspn(registro, "\r\n")] = '\0';
			if(strcmp(registro,cpf) == 0){
				fclose(usuarios);
				return 0;
			}
		}
	}
	
	fclose(usuarios);
	return 1;
}

int cadastra_id(void){
	char linha[200];
	int id = 1001;
	
	FILE *usuarios;
	usuarios = fopen("usuarios.txt","r");
	
	if(usuarios == NULL){
		return id;
	}
	
	while(fgets(linha, sizeof(linha), usuarios) != NULL){
		id++;
	}
	
	fclose(usuarios);
	return id;	
}

int cadastro(){
	char nome[50],cpf[12],senha[7];
	
	printf("\nDigite seu nome: ");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	while(1){
		printf("\nDigite seu CPF: ");
		fgets(cpf, sizeof(cpf), stdin);
		cpf[strcspn(cpf, "\n")] = '\0';
		
		if(valida_cpf(cpf)){
			limpar_buffer();
			break;
		}
		printf("\nCPF ja cadastrado!");
		limpar_buffer();
	}

	while(1){
		printf("\nDigite sua senha: ");
		fgets(senha, sizeof(senha), stdin);
		senha[strcspn(senha, "\n")] = '\0';
		
		if(valida_senha(senha)){
			break;
		}
		printf("\nSenha invalida!");
		limpar_buffer(); //problema aqui
	}
	
	int id = cadastra_id();
	
	FILE *usuarios;
	usuarios = fopen("usuarios.txt","a");
	fprintf(usuarios, "%d;%s;%s;%s\n", id,nome, cpf, senha);
	fclose(usuarios);
	
	printf("\nUsuario cadastrado\n");
	return 0;
}
