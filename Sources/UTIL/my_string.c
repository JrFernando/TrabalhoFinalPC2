/**
 * Este módulo implementa as funções relacionadas a string.
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 *
 * @date 03/07/2017
*/

#include <string.h>

#include "alocacao_memoria.h"


char* substring(char* str, int start, int end){
    int i, j;
    char *sub; 
    

    if(start >= end || end > strlen(str)) {
        return NULL;
    }
     
    sub = (char *) alocar_memoria(end - start + 1, sizeof(char));
     
    for(i = start, j = 0; i < end; i++, j++) 
        sub[j] = str[i];
    
     
    sub[j] = '\0';
     
    return sub;
}