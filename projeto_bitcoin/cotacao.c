#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int gerar_valores(){ //gera o arquivo com os valores iniciais de cada moeda
	FILE *valores;
	valores = fopen("valores.txt","w");
	
	fprintf(valores,"%d;%d;%d",2,1,1);
	
	fclose(valores);
	
	return 1;
}
//arrumar o problema de gerar valores depois

int cotacao(){
	char linha[200];
	
	FILE *valores;
	valores = fopen("valores.txt","r");
	
	FILE *temp;
	temp = fopen("temp.txt","w");
	
	if(valores == NULL){
		gerar_valores();
		
		FILE *valores;
		valores = fopen("valores.txt","r");
	}
	
	fgets(linha,sizeof(linha),valores);
	char *fbit = strtok(linha,";");
	char *feth = strtok(NULL,";");
	char *fxrp = strtok(NULL,"\r\n");
	
	float valor_bitcoin = atof(fbit);
	float valor_ethereum = atof(feth);
	float valor_ripple = atof(fxrp);
	
	
	float cot_1 = rand() % 11 - 5;
	float cot_2 = rand() % 11 - 5;
	float cot_3 = rand() % 11 - 5;
	//retorna um numero aleatorio com resto da divisao por 11
	//apos isso subtrai 5 do resultado
	//faixa de valores: (-5,-4,-3,-2,-1,0,1,2,3,4,5)
	
	float novo_bit = valor_bitcoin + (cot_1/100) * valor_bitcoin;
	float novo_eth = valor_ethereum + (cot_2/100) * valor_ethereum;
	float novo_xrp = valor_ripple + (cot_3/100) * valor_ripple;
	
	fprintf(temp,"%.2f;%.2f;%.2f",novo_bit,novo_eth,novo_xrp);
	
	fclose(temp);
	fclose(valores);
	
	remove("valores.txt");
	rename("temp.txt","valores.txt");
	
	printf("\nBitcoin: %.2f\n",novo_bit);
	printf("Ethereum: %.2f\n",novo_eth);
	printf("Ripple: %.2f\n",novo_xrp);
	
	return 1;
}
