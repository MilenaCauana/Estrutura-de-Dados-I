/*Implementa��o TAD - Milena Cauana

    ARQUIVO DE ESPECIFICA��O!

    Exercicio:
    Crie um TAD de um vetor de float:
        * O vetor tem uma capacidade m�xima (n�mero m�ximo de elementos);
        * O vetor informa seu tamanho(quantidade de elementos armazenados atualmente);

    Fun��es:
        * size(tad vector); //Retorna o tamanho do vetor (numero atual de elementos inseridos)
        * capacity(tad vector); //Retorna a capacidade do vetor (numero m�ximo de elementos)
        * at(tad vector, int index); //Retorna o elemento do �ndice "index" com bound-checked
        * get(tad vector, int index); //Retorna o elemento do index
        * append(tad vector, float float val); //Adiciona o valor 'bal' no final do vetor. Lan�a um erro se estiver cheio.
        * set(tad vector, int index, float val); //Atribui o valor 'val' no indice 'index' do vetor de tipo 'tad'. Lan�a um erro se o �ndice for inv�lido
        * print (tad vector); //Imprime todos os elementos do vetor. */

//#include<stdio.h> //Ele adicionar� no Main essa biblioteca tbm, mas n�o � uma boa pr�tica de programa

//Primeiro iremos definir um tipo de dado, no geral, se esconde a implementa��o da estruturaq de dados (da struct)

typedef struct float_vector floatVector; //Aqui ele diz: "Existe uma estrutura chamada float_vector, que est� em algum lugar, e eu estou dando um novo nome pra essa estrutura -> floatVector

//Agora, temos de colocar as defini��es das fun��es

    //Essas duas fun��es que vir�o, servem para cria��o e desaloca��o
    floatVector *create(int capacity);
    void destroy(floatVector **vec_ref);

    //Fun��es j� definidas pelo exerc�cio
    int size(const floatVector *vec);
    capacity(const floatVector *vec);
    at(const floatVector *vec, int index);
    get(const floatVector *vec, int index);
    append(const floatVector *vec, float val);
    set(const floatVector *vec, int index, float val);
    print (const floatVector *vec);
