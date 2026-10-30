#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

int inicio(int id);

int main(int argc, char *argv[]) {
	int entrada,id;
	while(1){
		printf("\n1. Cadastrar conta\n2. Fazer login\n0. Sair\n");
		scanf("%d",&entrada);
		if(entrada == 1 || entrada == 2){
			limpar_buffer();
			if(entrada == 1){
				id = cadastro();
				cria_conta(id);
			}
			else if(entrada == 2){
				id = login();
			}
			inicio(id);
		}
		else if(entrada == 0){
			printf("\nObrigado por usar o programa!\n");
			break;
		}
		else{
			printf("\nOpcao fora de alcance!\n");
			continue;
		}
	}
	system("pause");	
	return 0;
}

int inicio(id){
	int entrada;
	while(1){
		
		mostra_usuario(id);
		
		printf("\n1. Consultar saldo\n2. Consultar extrato\n3. Depositar\n4. Sacar\n5. Comprar Criptomoedas\n6. Vender Criptomoedas\n7. Atualizar Cotacao\n8. Voltar ao inicio\n");
		scanf("%d",&entrada);
		limpar_buffer();
		
		if(entrada == 1){
			if(!verifica_senha(id)){
				continue;
			}
			consulta_saldo(id);
		}
		else if(entrada == 2){
			//funcao para consulta de extrato
		}
		else if(entrada == 3){
			deposito(id);
		}
		else if(entrada == 4){
			saque(id);
		}
		else if(entrada == 5){
			if(!verifica_senha(id)){
				continue;
			}
			//funcao para compra
		}
		else if(entrada == 6){
			if(!verifica_senha(id)){
				continue;
			}
			//funcao para venda
		}
		else if(entrada == 7){
			cotacao(); 
		}
		else if(entrada == 8){
			return 0;
		}
		else{
			printf("\nOpcao fora do alcance!\n");
			continue;
		}
	}
}

//a fazer:
//2 - funcoes de compra e venda com as taxas por moeda
//3 - fazer os extratos e coloca-los em um arquivo para extratos

