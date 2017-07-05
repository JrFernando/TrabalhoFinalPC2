/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Funcionarios
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 30/06/2017
 */
#include <string.h>

#include "funcionario_bd.h"
#include "../UTIL/alocacao_memoria.h"

#define TAM_MAX_ID 4
#define TAM_MAX_SALARIO 6
#define TAM_MAX_NOME 61;

Funcionario* find_funcionario(int id) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Funcionarios where func_id =  ;";
    Funcionario *funcionario;
    Grupo* grupo;
    int tamanho = 0, id_grupo;

    tamanho = strlen(query) + TAM_MAX_SALARIO;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Funcionarios where func_id = %d;", id);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }


    if ((resposta = mysql_store_result(&mysql))) {
        linhas = mysql_fetch_row(resposta);
        if(linhas == NULL) return NULL;
        
        funcionario = (Funcionario*) alocar_memoria(1, sizeof (Funcionario));
        funcionario->id = atoi(linhas[0]);

        funcionario->nome = (char*) alocar_memoria(strlen(linhas[1]), sizeof (char));
        strcpy(funcionario->nome, linhas[1]);

        funcionario->salario = atof(linhas[3]);

        id_grupo = atoi(linhas[4]);
        grupo = find_grupo(id_grupo);
        funcionario->grupo = *grupo;

    } else {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return funcionario;
}

Funcionario* find_funcionario_nome(const char* nome) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Funcionarios where func_nome like  ;";
    Funcionario *funcionarios, *temp;
    Grupo* grupo;
    int tamanho = 0, id_grupo, quantidade;

    tamanho = strlen(query) + TAM_MAX_NOME;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Funcionarios where func_nome like \"%s%\";", nome);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }


    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        funcionarios = (Funcionario*) alocar_memoria(quantidade, sizeof (Funcionario));

        temp = funcionarios;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp->id = atoi(linhas[0]);

            temp->nome = (char*) alocar_memoria(strlen(linhas[1]), sizeof (char));
            strcpy(temp->nome, linhas[1]);

            temp->salario = atof(linhas[3]);

            id_grupo = atoi(linhas[4]);
            grupo = find_grupo(id_grupo);
            temp->grupo = *grupo;

            temp++;
        }

    } else {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return funcionarios;
}

int get_qtd_find_funcionario_nome(const char* nome) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    char *query = "select * from Funcionarios where func_nome like  ;";
    int quantidade = -1, tamanho;

    tamanho = strlen(query) + TAM_MAX_NOME;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Funcionarios where func_nome like \"%s%\";", nome);

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}
 

Funcionario* get_all_funcionarios() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Funcionarios;";
    Funcionario *funcionarios, *temp;
    Grupo *grupo;
    int quantidade, id_grupo;

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        funcionarios = (Funcionario*) alocar_memoria(quantidade, sizeof (Funcionario));

        temp = funcionarios;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp->id = atoi(linhas[0]);

            temp->nome = (char*) alocar_memoria(strlen(linhas[1]), sizeof (char));
            strcpy(temp->nome, linhas[1]);

            temp->salario = atof(linhas[3]);

            id_grupo = atoi(linhas[4]);
            grupo = find_grupo(id_grupo);
            temp->grupo = *grupo;

            temp++;
        }

    } else {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return funcionarios;
}

int get_qtd_all_funcionarios() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    char *query = "select * from Funcionarios;";
    int quantidade = -1;

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

bool insert_funcionario(const Funcionario funcionario) {
    MYSQL mysql;
    char* query = "insert into Funcionarios (func_nome, func_salario, func_grup_id) values (\"\",,);"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + strlen(funcionario.nome) + TAM_MAX_SALARIO + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "insert into Funcionarios (func_nome, func_salario, func_grup_id) values (\"%s\",%.2f,%d);",
            funcionario.nome, funcionario.salario, funcionario.grupo.id);

    if (!bd_open(&mysql)) return FALSE;

    if (!mysql_query(&mysql, query)) {
        bd_close(&mysql);
        return TRUE;
    } else {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return FALSE;
    }
}

bool update_funcionario(const Funcionario funcionario) {
    MYSQL mysql;
    char* query = "update Funcionarios set func_nome = \"\", func_salario = , func_grup_id =  where func_id = ;"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + strlen(funcionario.nome) + TAM_MAX_SALARIO + TAM_MAX_ID + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "update Funcionarios set func_nome = \"%s\", func_salario = %.2f, func_grup_id = %d where func_id = %d;",
            funcionario.nome, funcionario.salario, funcionario.grupo.id, funcionario.id);

    if (!bd_open(&mysql)) return FALSE;

    if (!mysql_query(&mysql, query)) {
        bd_close(&mysql);
        return TRUE;
    } else {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return FALSE;
    }
}

bool delete_funcionario(const Funcionario funcionario) {
    MYSQL mysql;
    char* query = "delete from Funcionarios where func_id = ;"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "delete from Funcionarios where func_id = %d;", funcionario.id);

    if (!bd_open(&mysql)) return FALSE;

    if (!mysql_query(&mysql, query)) {
        bd_close(&mysql);
        return TRUE;
    } else {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return FALSE;
    }
}