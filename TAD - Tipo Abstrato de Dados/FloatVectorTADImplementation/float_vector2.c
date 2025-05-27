/*Implementa��o TAD - Milena Cauana

    ARQUIVO DE IMPLEMENTA��O!

    Exercicio:
    Crie um TAD de um vetor de float:
        * O vetor tem uma capacidade m�xima (n�mero m�ximo de elementos);
        * O vetor informa seu tamanho(quantidade de elementos armazenados atualmente);

    Fun��es:
        * size(tad vector); //Retorna o tamanho do vetor (numero atual de elementos inderidos)
        * capacity(tad vector); //Retorna a capacidade do vetor (numero m�ximo de elementos)
        * at(tad vector, int index); //Retorna o elemento do �ndice "index" com bound-checked
        * get(tad vector, int index); //Retorna o elemento do index
        * append(tad vector, float float val); //Adiciona o valor 'bal' no final do vetor. Lan�a um erro se estiver cheio.
        * set(tad vector, int index, float val); //Atribui o valor 'val' no indice 'index' do vetor de tipo 'tad'. Lan�a um erro se o �ndice for inv�lido
        * print (tad vector); //Imprime todos os elementos do vetor. */

//Primeira coisa que devemos fazer � incluir o .h que cont�m as especifica��es
#include "float_vector2.h"
#include <stdlib.h>

struct float_vector
{
    int capacity; //Numero m�ximo de elementos do vetor
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
    floatVector *vec = (floatVector*) calloc(1, sizeof(floatVector)); //Diferen�a entre malloc e calloc -> malloc: aloca mem�ria mas n�o inicializa (o conte�do pode ser "lixo de mem�ria") calloc: Aloca mem�ria e inicializa todos os seus bytes com o valor zero;
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
void destroy(floatVector **vec_ref) //Perceba que, a assinatura do header n�o precisa exatamente ter os mesmos nomes dos par�metros, o que importa mesmo � a assinatura dos tipos, mas, como boa pratica de programa��o, busca-se colocar os mesmos nomes
{
    floatVector *vec = *vec_ref;

    free(vec -> data);
    free(vec);
    *vec_ref = NULL;

}
