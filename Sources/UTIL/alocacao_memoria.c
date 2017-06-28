#include "alocacao_memoria.h"

void* alocar_memoria(int tam, size_t size){
	void* vetor_ptr;

	if ( !(vetor_ptrv = calloc(tam, size)) ){
		printf("Não foi possível alocar memória, libere recurso para continuar...\n");
		return NULL;
	}

	return vetor_ptr;
}

void* realocar_memoria(void* vetor_ptr, int tam, size_t size){
	void* new_vetor_ptr;

	if( !(new_vetor_ptr = realloc(vetor_ptr, tam * size)) ){
		printf("Não foi possível realocar memória, libere recurso para continuar...\n");
		return vetor_ptr;
	}

	return new_vetor_ptr;
}