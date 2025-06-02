#include <stdlib.h>
#include<string.h>
#include "Tabela_Hash.h"

//-----------Definição do tipo Hash----------
/*
* - Por questões de desempenho, a tabela hash irá armazenar apenas o endereço
*   para a estrutura que contém os dados do aluno e não os dados em si
* - Esse yipo de abordagem tem como objetivo evitar o gasto exessivo de memória.
* - A medida que os elementos são inseridos na tabela, nós realizamos a alocação daquele único elemento
*/
struct hash
{
    int qtd, TABLE_SIZE; //qtd -> quantidade de elementos já armazenados
    Aluno **itens;
};

/*
*------------Função de criação da tabela--------
* - Aloca espaço para o array de ponteiros e os inicializa com NULL
* - Na criação da Tabela Hash, o ideal é sempre usar números primos
*   e evitar valores que seham uma potência de dois;
* - Um número primo reduz a probabilidade de colisões, mesmo que a função
*   de hashing utilizada não seja muito eficaz;
* - Uma potência de dois melhora a velociade, mas pode aumentar os proble-
*   mas de colisão se estivermos utilizando uma função de hashing mais simples.
*
* Nela, basicamente temos:
* Um ponteiro ha que aponta para uma estrutura do tipo hash e o seu
* itens aponta para um vetor de ponteiros do tipo aluno
*
* ha -> |     qtd    |
*       | __________ |
*       | TABLE_SIZE |
*       | __________ |
*       |    itens   | -----> [Aluno 0] ----> Estrutura Aluno
*                                ...
*                             [Aluno n] ----> Estrutura Aluno
*
*/
Hash *criaHash(int TABLE_SIZE)
{
    Hash *ha = (Hash *) malloc(sizeof(Hash)); //Criando a struct associada ao ponteiro ha

    if (ha != NULL)
    {
        int i;
        ha -> TABLE_SIZE = TABLE_SIZE;

        ha -> itens = (Aluno **) malloc (TABLE_SIZE * sizeof(Aluno*));

        if (ha -> itens == NULL)
        {
            free (ha);
            return NULL;
        }

        ha -> qtd = 0;

        for (i = 0; i < ha -> TABLE_SIZE; i++)
        {
            ha -> itens[i] = NULL;
        }

        return ha;
    }
}

/*
*------------Função de criação da tabela--------
* - Envolve percorrer todo o array e verificar se eciste elemento para ser desalocado
*/
void liberaHash(Hash *ha)
{
    if (ha != NULL)
    {
        int i;
        for (i = 0; i < ha -> TABLE_SIZE; i++)
        {
            if (ha -> itens[i] != NULL)
            {
                free(ha -> itens[i]);
            }
        }
        free (ha -> itens);
        free (ha);
    }
}

/*
* ------------Função para caçcular a posição da chave ----------
* - Inserção e busca, é necessário calcular a posição dos dados dentro da tabela

* ----- Função de Hashing -------
* - Permite calcular uma posição a partir de uma chave escolhida a partir dos dados;
* - è extremamente importante para o bom desempenho da tabela;
* - Responsável por distribuir as informações de forma equilibrada pela tabela hash;
*
* - Deve ser simples e barata de se calcular;
* - Garantir que valores diferentes produzam posições diferentes;
* - Gerar uma distribuição equilibrada dos dados na tabela, ou seja, cada posição da
*   tabela tem a mesma chance de receber uma chave (máximo espalhamento);
*
* - A implementação da função de hashing depende do conhecimento prévio da natureza e
*   domínio da chave a ser utilizada;
*
* ººº Método da Divisão (ou da Congruência Linear) ººº -> Iremos utilizar no trabalho.
*/
int chaveDivisao (int chave, int TABLE_SIZE)
{
    return (chave & 0xFFFFFFF) % TABLE_SIZE; //Esse '0xFFFFFFF' elimina o bit de sinal do valor da chave, evita números negativos
}

/*--------Inserção de Elementos sem tratamento de colisão-------
* - Calcular a posição da cave no array;
* - Alocar espaço para os dados;
* - Armazenar os dados na posição calculada;
*
*/
int insereHash_SemColisao(Hash  *ha, Aluno aluno)
{
    if (ha == NULL || ha -> qtd == ha -> TABLE_SIZE) //Situações em que não é possível inserir
    {
         return 0;
    }

    int chave = aluno.matricula;

    int pos = chaveDivisao(chave, ha -> TABLE_SIZE);

    Aluno *novo;
    novo = (Aluno *) malloc(sizeof(Aluno));

    if (novo == NULL)
    {
        return 0;
    }

    *novo = aluno;
    ha -> itens[pos] = novo;
    ha -> qtd ++;

    return 1;
}

/*--------Busca de Elementos sem tratamento de colisão-------
* - Calcular a posição da cave no array;
* - Verifica se há dados na posição calculada;
* - Retorna os dados;
*/

buscaHash_SemColisao(Hash *ha, int mat, Aluno *aluno) //mat == matrícula
{
    if (ha == NULL)
    {
        return 0;
    }

    int pos = chaveDivisao(mat, ha -> TABLE_SIZE);

    if (ha -> itens[pos] == NULL)
    {
        return 0;
    }

    *aluno = *(ha -> itens[pos]); //Copia o conteúdo para o ponteiro
    return 1;
}
