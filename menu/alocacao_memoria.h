#include<stdio.h>
#include<stdlib.h>

//biblioteca para alocar memoria:

char* alocacao_memoria_strings(){
	char *vetor_PTR;
	
	//alocando memoria para o vetor de strings:
	vetor_PTR=calloc(51,sizeof(char));
	if(!vetor_PTR){
		printf("ERRO AO ALOCAR MEMORIA-FIM DO PROGRAMA");
		exit(1);
	}
	
	return vetor_PTR;
}

int* alocacao_memoria_int(){
	int *vetor_PTR;
	
	//alocando memoria para o vetor de strings:
	vetor_PTR=calloc(51,sizeof(int));
	if(!vetor_PTR){
		printf("ERRO AO ALOCAR MEMORIA-FIM DO PROGRAMA");
		exit(1);
	}
	
	return vetor_PTR;
}

float* alocacao_memoria_float(){
	float *vetor_PTR;
	
	//alocando memoria para o vetor de strings:
	vetor_PTR=calloc(51,sizeof(float));
	if(!vetor_PTR){
		printf("ERRO AO ALOCAR MEMORIA-FIM DO PROGRAMA");
		exit(1);
	}
	
	return vetor_PTR;
}
