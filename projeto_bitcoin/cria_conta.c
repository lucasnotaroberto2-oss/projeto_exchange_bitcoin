#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cria_conta(int id){
	float reais = 0;
	float bitcoin = 0;
	float ethereum = 0;
	float ripple = 0;
	
	FILE *contas;
	contas = fopen("contas.txt","a");
	
	if(contas == NULL){
		printf("\nerro ao abrir arquivo\n");
		return 0;	
	}
	
	fprintf(contas, "%d;%f;%f;%f;%f\n", id,reais,bitcoin,ethereum,ripple);
	fclose(contas);
	
	printf("\nconta cadastrada com sucesso\n");
	return 1;
}
