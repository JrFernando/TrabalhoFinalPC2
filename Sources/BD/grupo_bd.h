/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Grupo
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 29/06/2017
 */
 
#include "bd.h"
#include "../MODELO/grupo.h" 

/**
 * Esta função recebe um id, faz a busca no banco de dados
 * pelo grupo correspondente e o retorna. 
 */
Grupo find_grupo(int);

/**
 * Esta função retorna um ponteiro para todos os 
 * grupos cadastrados no banco de dados.
 *
 */
Gupro* get_all_grupos();

/**
 * Esta função retorna quantos grupos 
 * estão cadastrados no banco de dados.
 *
 */
int get_qtd_all_grupos();

/**
 * Esta função retorna um ponteiro para todos os 
 * grupos cadastrados no banco de dados.
 *
 * tam - Ponteiro para uma variavel inteira. É usada para
 *       retornar a quantidade de grupos que contém o ponteiro
 *       que é retornado pela função.
 */
Grupo* get_all_grupos(int* tam);