#include <stdio.h>
#include <string.h>
#include <time.h>

#include "alocacao_memoria.h"
#include "my_string.h"

#define TAM_MAX_STRING_DATE 20

typedef struct tm tm;

//prototipos das funcoes:

tm* gerando_horario();

/**
 * Converte a struct tm para uma string no formato 
 * do MySQL YYYY-MM-DD HH:MM:SS 
 *   
 * @param horario Struct tm
 * @return Uma string do horário
 */
char* tm_to_string_bd(tm horario);

/**
 * Converte a struct tm para uma string no formato 
 * do MySQL YYYY-MM-DD
 *   
 * @param horario Struct tm
 * @return Uma string da data
 */
char* tm_to_string_date_bd(tm horario);

/**
 * Converte a string no formato do MySQL YYYY-MM-DD HH:MM:SS 
 * para a struct tm  
 * 
 * @param string Uma string do horário no formato do MySQL
 * @return Struct tm
 */
tm string_bd_to_tm(char* string);