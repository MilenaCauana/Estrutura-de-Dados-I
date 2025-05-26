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
#include "float_vector.h"

struct float_vector
{
    int capacity; //Numero m�ximo de elementos do vetor
    int size; //Quantidade de elementos armazenados
    float *data; //Vetor de floats

};

    floatVector *create(int capacity)
    {

    }
    void destroy(floatVector **vec);

    int size(const floatVector *vec);
    capacity(const floatVector *vec);
    at(const floatVector *vec, int index);
    get(const floatVector *vec, int index);
    append(const floatVector *vec, float val);
    set(const floatVector *vec, int index, float val);
    print (const floatVector *vec);
