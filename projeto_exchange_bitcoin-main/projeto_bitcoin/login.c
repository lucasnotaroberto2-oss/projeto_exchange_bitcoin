int login(nome,cpf,senha){
	FILE *arquivo;
	arquivo = fopen("usuarios.txt","a");
	
	printf("Digite seu nome: ");
	fgets(nome, 20, stdin);
	fprintf(usuarios,"%s\n",nome);
	
	while(1){
		printf("\nDigite seu cpf: ");
		fgets(cpf, 11, stdin);
		if(//função para calculo de tamanho de cpf
		){
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
		fgets(senha, 6, stdin);
		if(//função para reconhecer tamanho de senha
		){
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
