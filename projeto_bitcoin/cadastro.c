#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int valida_senha(char senha[]){
	int i;
	if(strlen(senha) != 6){
		return 0;
	}
	for(i = 0; i < 6;i++){
		if(isalpha(senha[i])){
			return 0;
		}
	}
	return 1;
}

int cadastro(){
	char nome[50],cpf[12],senha[7];

	printf("Digite seu nome: ");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';

	printf("Digite seu CPF: ");
	fgets(cpf, sizeof(cpf), stdin);
	cpf[strcspn(cpf, "\n")] = '\0';

	
	while(1){
		printf("\nDigite sua senha: ");
		fgets(senha, sizeof(senha), stdin);
		senha[strcspn(senha, "\n")] = '\0';
		if(valida_senha(senha)){
			break;
		}
		else{
			printf("\nSenha invalida!");
			continue;
		}
	}
	
	FILE *usuarios;
	usuarios = fopen("usuarios.txt","a");
	fprintf(usuarios, "%s;%s;%s\n", nome, cpf, senha);
	fclose(usuarios);
	
	return 0;
}

//arrumar o problema ao ler a senha(por hora resolvido)
// - fazer com que a senha seja lida sem precisar usar dois \n.
