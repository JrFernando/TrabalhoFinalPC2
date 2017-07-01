/**
 * Este módulo disponibiliza funções para facilitar a utilização de alocação dinâmica
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 27/06/2017
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Esta função retorna um ponteiro genérico para um bloco de memória.
 *
 * tam - Números de elementos a ser alocado
 * size - Tamanho dos elementos
 *
*/
void* alocar_memoria(int tam, size_t size);

/**
 * Esta função retorna um ponteiro genérico para um bloco de memória
 * realocado para o novo tamanho, caso não seja possível realocar e retornado
 * o mesmo ponteiro sem alterações.
 *
 * vetor_ptr - Ponteiro com memória alocada previamente
 * tam - Números de elementos a ser realocado
 * size - Tamanho dos elementos
 *
*/
void* realocar_memoria(void* vetor_ptr, int tam, size_t size);

