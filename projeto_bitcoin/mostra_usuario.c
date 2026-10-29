#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int mostra_usuario(int id){
	char linha[200];
	
	FILE *usuarios;
	usuarios = fopen("usuarios.txt","r");
	
	if(usuarios == NULL){
		printf("\nerro ao abrir arquivo\n");
		return 0;
	}
	
	while(fgets(linha, sizeof(linha), usuarios) != NULL){
		char *fid = strtok(linha, ";");
		char *nome = strtok(NULL, ";");
		char *registro = strtok(NULL, ";");
		
		int checagem_id = atoi(fid);
		
		if(checagem_id == id){
			printf("\nNome : %s\n",nome);
			printf("CPF : %c%c%c.%c%c%c.%c%c%c-%c%c\n",registro[0],registro[1],registro[2],registro[3],
				registro[4],registro[5],registro[6],registro[7],registro[8],registro[9],registro[10]);
			break;		
		}
	}
	fclose(usuarios);
	return 1;
}
