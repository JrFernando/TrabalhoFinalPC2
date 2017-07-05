/**
 * Este módulo define as  funções de manipulações 
 * da struct Fabricante.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
  @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 
 * @date 27/06/2017
*/
#include "fabricante.h"
#include "../UTIL/alocacao_memoria.h"
#include<string.h>


Fabricante lendo_fabricante(){
	Fabricante f;
	
	//alocando memoria para string:
	f.nome=alocar_memoria(51,sizeof(char));
	
	//printf("\nDigite o id do fabricante:");
	//scanf("%d",&f.id);
	
	printf("\nDigite o nome do fabrincante:");
	scanf("\n%[^\n]s",f.nome);
	
	//realocando a memoria da string:
	f.nome=realocar_memoria(f.nome,strlen(f.nome),sizeof(char));
	
	return f;
} 
