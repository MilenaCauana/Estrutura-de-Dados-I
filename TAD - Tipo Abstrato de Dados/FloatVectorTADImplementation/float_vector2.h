/*Implementação TAD - Milena Cauana

    ARQUIVO DE ESPECIFICAÇÃO! --> Interface pública

    Exercicio:
    Crie um TAD de um vetor de float:
        * O vetor tem uma capacidade máxima (número máximo de elementos);
        * O vetor informa seu tamanho(quantidade de elementos armazenados atualmente);

    Funções:
        * size(tad vector); //Retorna o tamanho do vetor (numero atual de elementos inseridos)
        * capacity(tad vector); //Retorna a capacidade do vetor (numero máximo de elementos)
        * at(tad vector, int index); //Retorna o elemento do índice "index" com bound-checked
        * get(tad vector, int index); //Retorna o elemento do index
        * append(tad vector, float float val); //Adiciona o valor 'bal' no final do vetor. Lança um erro se estiver cheio.
        * set(tad vector, int index, float val); //Atribui o valor 'val' no indice 'index' do vetor de tipo 'tad'. Lança um erro se o índice for inválido
        * print (tad vector); //Imprime todos os elementos do vetor. */

//#include<stdio.h> //Ele adicionará no Main essa biblioteca tbm, mas não é uma boa prática de programa

//Primeiro iremos definir um tipo de dado, no geral, se esconde a implementação da estruturaq de dados (da struct)

typedef struct float_vector floatVector; //Aqui ele diz: "Existe uma estrutura chamada float_vector, que está em algum lugar, e eu estou dando um novo nome pra essa estrutura -> floatVector

//Agora, temos de colocar as definições das funções

    //Essas duas funções que virão, servem para criação e desalocação
    floatVector *floatVector_create(int capacity);
    void floatVector_destroy(floatVector **vec_ref);

    //Funções já definidas pelo exercício
    int floatVector_size(const floatVector *vec);
    int floatVector_capacity(const floatVector *vec);
    float floatVector_at(const floatVector *vec, int index);
    float floatVector_get(const floatVector *vec, int index);
    void floatVector_append(floatVector *vec, float val);
    void floatVector_set(const floatVector *vec, int index, float val);
    void floatVector_print (const floatVector *vec);
