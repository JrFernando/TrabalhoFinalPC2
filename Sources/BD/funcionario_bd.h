/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Funcionarios
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 23/06/2017
 */
 
#include "bd.h"
#include "../MODELO/funcionario.h"

/**
 * Esta função recebe um id, faz a busca no banco de dados
 * pelo funcionario correspondente e o retorna. 
 */
Funcionario* find_funcionario(int);

/**
 * Esta função retorna um ponteiro para todos os 
 * funcionarios cadastrados no banco de dados.
 *
 */
Funcionario* get_all_funcionarios();

/**
 * Esta função retorna quantos funcionarios 
 * estão cadastrados no banco de dados.
 *
 * Retorno - retorna a quantidade de registros no banco.
 *
 * Erro - retorna -1 em caso de erro.
 */
int get_qtd_all_funcionarios();

/**
 * Esta recebe um Funcionario e faz sua inserção no 
 * banco de dados.
 */
bool insert_funcionario(const Funcionario);
 
/**
 * Esta recebe um Funcionario e atualiza os dados do 
 * funcionario com o respectivo id no banco de dados. 
 */
bool update_funcionario(const Funcionario);

/**
 * Esta recebe um Funcionario e o deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
bool delete_funcionario(const Funcionario);