#include <stdio.h>
#include <stdlib.h>
#include "login.h"

int inicio(void);

int main(int argc, char *argv[]) {
	int entrada;
	while(1){
		printf("digite\n1-login\n2-cadastro\n");
		scanf("%d",&entrada);
		if(entrada == 1 || entrada ==2){
			if(entrada == 1){
				//funcao de login
				login();
			}
			//funcao de cadastro   //cadastro sera chamado escolhendo 2 ou não
			inicio();
		}
		else{
			printf("opcao fora de alcance!");
			continue;
		}
	}
	system("pause");	
	return 0;
}

int inicio(void){
	int entrada;
	while(1){
		printf("1. Consultar saldo\n2. Consultar extrato\n3. Depositar\n4. Sacar\n5. Comprar Criptomoedas\n6. Vender Criptomoedas\n7. Atualizar Cotacao\n8. Sair\n");
		scanf("%d",&entrada);
		if(entrada == 1){
		}
		else if(entrada == 2){
		}
		else if(entrada == 3){
		}
		else if(entrada == 4){
		}
		else if(entrada == 5){
		}
		else if(entrada == 6){
		}
		else if(entrada == 7){
		}
		else if(entrada == 8){
			printf("obrigado por usar nosso site!\n");
			system("pause");
			return;
		}
		else{
			printf("opcao fora do alcance!\n");
			continue;
		}
	}
}
