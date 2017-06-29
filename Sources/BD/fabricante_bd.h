/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Fabricante
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 23/06/2017
 */
 
#include "bd.h"
#include "../MODELO/fabricante.h" 

/**
 * Esta função recebe um id, faz a busca no banco de dados
 * pelo fabricante correspondente e o retorna. 
 *
 * return - Retorna uma struct Fabricante. Caso não exista retorna NULL. 
 */
Fabricante find_fabricante(int);

/**
 * Esta função retorna um ponteiro para todos os 
 * fabricantes cadastrados no banco de dados.
 *
 */
Fabricante* get_all_fabricantes();

/**
 * Esta função retorna quantos fabricantes 
 * estão cadastrados no banco de dados.
 *
 */
int get_qtd_all_fabricantes();

/**
 * Esta função retorna um ponteiro para todos os 
 * fabricantes cadastrados no banco de dados.
 *
 * tam - Ponteiro para uma variavel inteira. É usada para
 *       retornar a quantidade de Fabricantes que contém o ponteiro
 *       que é retornado pela função.
 */
Fabricante* get_all_fabricantes(int* tam);

/**
 * Esta recebe um Fabricante e faz sua inserção no 
 * banco de dados.
 */
bool insert_fabricante(const Fabricante);
 
/**
 * Esta recebe um Fabricante e atualiza os dados do 
 * fabricante com o respectivo id no banco de dados. 
 */
bool update_fabricante(const Fabricante);

/**
 * Esta recebe um Fabricante e o deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
bool delete_fabricante(const Fabricante);
