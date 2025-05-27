/*Implementação TAD - Milena Cauana

    ARQUIVO DE IMPLEMENTAÇÃO!

    Exercicio:
    Crie um TAD de um vetor de float:
        * O vetor tem uma capacidade máxima (número máximo de elementos);
        * O vetor informa seu tamanho(quantidade de elementos armazenados atualmente);

    Funções:
        * size(tad vector); //Retorna o tamanho do vetor (numero atual de elementos inderidos)
        * capacity(tad vector); //Retorna a capacidade do vetor (numero máximo de elementos)
        * at(tad vector, int index); //Retorna o elemento do índice "index" com bound-checked
        * get(tad vector, int index); //Retorna o elemento do index
        * append(tad vector, float float val); //Adiciona o valor 'bal' no final do vetor. Lança um erro se estiver cheio.
        * set(tad vector, int index, float val); //Atribui o valor 'val' no indice 'index' do vetor de tipo 'tad'. Lança um erro se o índice for inválido
        * print (tad vector); //Imprime todos os elementos do vetor. */

//Primeira coisa que devemos fazer é incluir o .h que contém as especificações
#include "float_vector2.h"
#include <stdlib.h>

struct float_vector
{
    int capacity; //Numero máximo de elementos do vetor
    int size; //Quantidade de elementos armazenados
    float *data; //um ponteiro para um vetor de floats

};

/*@brief cria(aloca) um vetor de floats com uma data capacidades;
*
*@param capacity Capacidade do vetor
*@return floatcVector* um vetor de floats alocado/criado
*/
floatVector *create(int capacity)
{
    floatVector *vec = (floatVector*) calloc(1, sizeof(floatVector)); //Diferença entre malloc e calloc -> malloc: aloca memória mas não inicializa (o conteúdo pode ser "lixo de memória") calloc: Aloca memória e inicializa todos os seus bytes com o valor zero;
    vec -> size = 0;
    vec -> capacity = capacity;
    vec -> data = (float*) calloc(capacity, sizeof(float));

    return vec;
}

/*
*
*
*
*/
void destroy(floatVector **vec_ref) //Perceba que, a assinatura do header não precisa exatamente ter os mesmos nomes dos parâmetros, o que importa mesmo é a assinatura dos tipos, mas, como boa pratica de programação, busca-se colocar os mesmos nomes
{
    floatVector *vec = *vec_ref;

    free(vec -> data);
    free(vec);
    *vec_ref = NULL;

}
