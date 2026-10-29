#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int consulta_saldo(int id){
	char linha[200];
	
	FILE *conta;
	conta = fopen("contas.txt","r");
	
	if(conta == NULL){
		printf("\nerro ao abrir arquivo\n");
		return 0;
	}
	
	while(fgets(linha, sizeof(linha), conta) != NULL){
		char *fid = strtok(linha, ";");
		char *reais = strtok(NULL, ";");
		char *bitcoin = strtok(NULL, ";");
		char *ethereum = strtok(NULL, ";");
		char *ripple = strtok(NULL, ";");
		
		int consulta_id = atoi(fid);
		
		if(consulta_id == id){
			printf("\nReais: %s\n",reais);
			printf("Bitcoin: %s\n",bitcoin);
			printf("Ethereum: %s\n",ethereum);
			printf("Ripple: %s\n",ripple);
			break;
		}
	}
	
	fclose(conta);
	return 1;
}
