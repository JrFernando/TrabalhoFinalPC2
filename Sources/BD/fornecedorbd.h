/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Fornecedores
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 23/06/2017
 */
 
#include "bd.h"
//#include "" Importar arquivo com a struct Fornecedores

/**
 * Esta função recebe um id, faz a busca no banco de dados
 * pelo fornecedor correspondente e o retorna. 
 */
Fornecedor findFornecedor(int);

/**
 * Esta função retorna um ponteiro para todos os 
 * fornecedores cadastrados no banco de dados.
 */
Fornecedor* getAllFornecedores();

/**
 * Esta recebe um Fornecedor e faz sua inserção no 
 * banco de dados.
 */
bool insertFornecedor(const Fornecedor);
 
/**
 * Esta recebe um Fornecedor e atualiza os dados do 
 * fornecedor com o respectivo id no banco de dados. 
 */
bool updateFornecedor(const Fornecedor);

/**
 * Esta recebe um Fornecedor e o deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
bool deleteFornecedor(const Fornecedor);
