#include <stdio.h>
#include <stdlib.h>

int hub(void);

int main(int argc, char *argv[]) {
	int entrada;
	while(1){
		printf("digite\n1-login\n2-cadastro\n");
		scanf("%d",&entrada);
		if(entrada == 1 || entrada ==2){
			if(entrada == 1){
				//funcao de login
			}
			//funcao de cadastro   //cadastro sera chamado escolhendo 2 ou não
			hub();
		}
		else{
			printf("opção fora de alcance");
			continue;
		}
	}
	system("pause");	
	return 0;
}

int hub(void){
	int entrada;
	while(1){
		printf("1. Consultar saldo\n2. Consultar extrato\n3. Depositar\n4. Sacar\n5. Comprar Criptomoedas\n6. Vender Criptomoedas\n7. Atualizar Cotacao\n8. Sair\n");
		scanf("%d",&entrada);

	}
}
