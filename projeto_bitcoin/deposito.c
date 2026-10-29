#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//fazer a funcao para escrita de extrato bem aqui

int deposito(int id){
	char linha[200];
	int encontrado = 0;
	float quantidade;
	
	//abre o arquivo existente
	FILE *conta;
	conta = fopen("contas.txt","r");
	
	//arquivo temporario onde vao ser reescritas as contas todas
	FILE *temp;
	temp = fopen("temp.txt","a");
	
	//confere se conta esta vazio
	if(conta == NULL){
		printf("\nerro ao abrir arquivo\n");
		return 0;
	}
	
	//faz a reescrita no novo arquivo
	while(fgets(linha, sizeof(linha), conta) != NULL){
		char *fid = strtok(linha, ";");
		char *reais = strtok(NULL, ";");
		char *bitcoin = strtok(NULL, ";");
		char *ethereum = strtok(NULL, ";");
		char *ripple = strtok(NULL, "\r\n");
		
		//converte os valores para manipulacao das variaveis
		int consulta_id = atoi(fid); // char -> int
		float saldo = atof(reais); //char -> float
		
		//caso seja a conta a ser depositada
		if(consulta_id == id){
			printf("\nQuantos reais quer depositar: ");
			scanf(" %f",&quantidade);
			
			saldo += quantidade;
			encontrado = 1;
			
			printf("\n\nVoce depositou %.2f reais na sua conta\n",quantidade);
			printf("\nNovo saldo : %.2f\n",saldo);	
		}
		
		//reescreve todos os valores no novo arquivo
		fprintf(temp, "%d;%.2f;%s;%s;%s\n", consulta_id,saldo,bitcoin,ethereum,ripple);
	}
	
	fclose(conta);
	fclose(temp);
	
	//checa se o arquivo foi aberta propriamente(evita perda de dodoa existentes
	if(!encontrado){
		remove("temp.txt");
		printf("\nconta não encontrada\n");
		return 0;
	}
	
	remove("contas.txt"); //exclui o arquivo de contas
	rename("temp.txt","contas.txt"); //renomea o arquivo temporario como novo arquivo de contas
	
	return 1;
}
