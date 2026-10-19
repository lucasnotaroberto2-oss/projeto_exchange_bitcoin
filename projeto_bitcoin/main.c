#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

int inicio();

void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}

int main(int argc, char *argv[]) {
	int entrada;
	while(1){
		printf("1. Cadastrar conta\n2. Fazer login\n0. Sair\n");
		scanf("%d",&entrada);
		if(entrada == 1 || entrada == 2){
			limpar_buffer();
			if(entrada == 1){
				cadastro();
			}
			else{
				//funcao de login de conta
			}
			
			inicio();
		}
		else if(entrada == 0){
			printf("Obrigado por usar o programa!\n");
			break;
		}
		else{
			printf("Opcao fora de alcance!\n");
			continue;
		}
	}
	system("pause");	
	return 0;
}

int inicio(void){
	int entrada;
	while(1){
		printf("1. Consultar saldo\n2. Consultar extrato\n3. Depositar\n4. Sacar\n5. Comprar Criptomoedas\n6. Vender Criptomoedas\n7. Atualizar Cotacao\n8. Voltar ao inicio\n");
		scanf("%d",&entrada);
		if(entrada == 1){
			//funcao para consulta de saldo
		}
		else if(entrada == 2){
			//funcao para consulta de extrato
		}
		else if(entrada == 3){
			//funcao para depositos
		}
		else if(entrada == 4){
			//funcao para saque
		}
		else if(entrada == 5){
			//funcao para compra
		}
		else if(entrada == 6){
			//funcao para venda
		}
		else if(entrada == 7){
			//funcao para mostrar cotacao
		}
		else if(entrada == 8){
			return 0;
		}
		else{
			printf("Opcao fora do alcance!\n");
			continue;
		}
	}
}

//proximos passos-
//1. adicionar os dados de usuario em um vetor e salvar no arquivo usuarios(funcao cadastro)



//2 - incluir nome,cpf e senha no arquivo de texto "usuarios"
