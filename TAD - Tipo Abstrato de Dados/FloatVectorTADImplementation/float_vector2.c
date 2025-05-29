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

//Primeira coisa que devemos fazer � incluir o .h que cont�m as especifica��es e ao passo queeu precisar de bibliotecas, ir adicionando-as
#include "float_vector2.h"
#include <stdlib.h>
#include<stdio.h>
#include<stdbool.h>

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
floatVector *floatVector_create(int capacity)
{
    floatVector *vec = (floatVector*) calloc(1, sizeof(floatVector)); //Diferen�a entre malloc e calloc -> malloc: aloca mem�ria mas n�o inicializa (o conte�do pode ser "lixo de mem�ria") calloc: Aloca mem�ria e inicializa todos os seus bytes com o valor zero;
    vec -> size = 0;
    vec -> capacity = capacity;
    vec -> data = (float*) calloc(capacity, sizeof(float));

    return vec;
}

/*
*Destruindo a fun��o, desalocando;
*/
void floatVector_destroy(floatVector **vec_ref) //Perceba que, a assinatura do header n�o precisa exatamente ter os mesmos nomes dos par�metros, o que importa mesmo � a assinatura dos tipos, mas, como boa pratica de programa��o, busca-se colocar os mesmos nomes
{
    floatVector *vec = *vec_ref;

    free(vec -> data);
    free(vec);
    *vec_ref = NULL;

}

/*
*-------FUN��O PRIVADA: para ver se o vetor est� cheio
*/
bool _floatVector_isFull(const floatVector *vec)
{
    return vec -> size == vec -> capacity; //Se o tamanho for igual a capacidade, ele retornara true
}

/*
*Fun��o para adicionar um elemento no fim do vetor
*/
void floatVector_append(floatVector *vec, float val)
{
    //O size j� indica o indice do vetor que est� dispon�vel
    if (_floatVector_isFull(vec))
    {
        fprintf(stderr, "ERROR in 'append'\n"); //stderr -> significa que est� saindo em uma sa�da padr�o de texto
        fprintf(stderr, "Vector is full\n");
        exit(EXIT_FAILURE); //Aqui, voc� est� falando que est� saindo do programa uma falha
    }

    vec -> data[vec -> size] = val;
    vec -> size++;
}

/*
*Fun��o para printar o vetor
*/
void floatVector_print (const floatVector *vec)
{
    puts("------------------");
    printf("size: %d\n", vec -> size);
    printf("Capacity: %d\n", vec -> capacity);
    puts("---");

    for (int i = 0; i < vec -> size; i++)
    {
        printf("[%d} = %f\n", i, vec -> data[i]);
    }
    puts("-------------------\n");
}

/*
*Fun��o que retorna o tamanho atual do vetor
*/
int floatVector_size(const floatVector *vec)
{
    return vec -> size;
}


/*
*Fun��o que retorna a capacidade do vetor
*/
int floatVector_capacity(const floatVector *vec)
{
    return vec -> capacity;
}

/*Fun��o que retorna o elemento do �ndice "index" com bound-checked
* BOUNF-CHECKED -> Ele ir� checar se o �ndice que voc� mandou � v�lido
*/
float floatVector_at(const floatVector *vec, int index)
{
    if (index < 0 || index >= vec -> capacity)
    {
        fprintf(stderr, "ERROR in 'at'\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec -> capacity - 1);
        exit(EXIT_FAILURE);
    }

    return vec ->data[index];
}

/*
*Fun��o que retorna o elemento do �ndice
*/
float floatVector_get(const floatVector *vec, int index)
{
    return vec ->data[index];
}

/*
*Fun��o que adiciona um valor em um indice se o indice foir v�lido
*/
void floatVector_set(const floatVector *vec, int index, float val)
{
    if (index < 0 || index >= vec -> capacity)
    {
        fprintf(stderr, "ERROR in 'set'\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec -> capacity - 1);
        exit(EXIT_FAILURE);
    }

    vec -> data[index] = val;
}

