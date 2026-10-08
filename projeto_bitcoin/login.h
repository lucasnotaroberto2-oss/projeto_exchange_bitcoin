int login(){
	FILE *usuarios;
	usuarios = fopen("usuarios.txt","a");
	
	char nome;
	long long cpf;
	long long senha;
	
	printf("Digite seu nome: ");
	scanf("%c",&nome);
	fprintf(usuarios,"%c\n",nome);
		
	
	while(1){
		printf("\nDigite seu cpf: ");
		scanf("%lld",&cpf);
		if(cpf >= 10000000000LL && cpf <= 99999999999LL){
			fprintf(usuarios,"%lld\n",cpf);
			break;
		}
		else{
			printf("\ncpf fora de alcance!\n");
			continue;
		}
	}
	
	while(1){
		printf("\nDigite sua senha(6 caracteres): ");
		scanf("%lld",&senha);
		if(senha >= 100000LL && senha <= 999999LL){
			fprintf(usuarios,"%lld\n",senha);
			break;
		}
		else{
			printf("\na senha precisa ter 6 caracteres!\n");
			continue;
		}
	}
	
	fclose(usuarios);
	
	return 0;
}
