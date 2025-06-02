#include <stdlib.h>
#include<string.h>
#include "Tabela_Hash.h"

//-----------Defini��o do tipo Hash----------
/*
* - Por quest�es de desempenho, a tabela hash ir� armazenar apenas o endere�o
*   para a estrutura que cont�m os dados do aluno e n�o os dados em si
* - Esse yipo de abordagem tem como objetivo evitar o gasto exessivo de mem�ria.
* - A medida que os elementos s�o inseridos na tabela, n�s realizamos a aloca��o daquele �nico elemento
*/
struct hash
{
    int qtd, TABLE_SIZE; //qtd -> quantidade de elementos j� armazenados
    Aluno **itens;
};

/*
*------------Fun��o de cria��o da tabela--------
* - Aloca espa�o para o array de ponteiros e os inicializa com NULL
* - Na cria��o da Tabela Hash, o ideal � sempre usar n�meros primos
*   e evitar valores que seham uma pot�ncia de dois;
* - Um n�mero primo reduz a probabilidade de colis�es, mesmo que a fun��o
*   de hashing utilizada n�o seja muito eficaz;
* - Uma pot�ncia de dois melhora a velociade, mas pode aumentar os proble-
*   mas de colis�o se estivermos utilizando uma fun��o de hashing mais simples.
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
*------------Fun��o de cria��o da tabela--------
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
* ------------Fun��o para ca�cular a posi��o da chave ----------
* - Inser��o e busca, � necess�rio calcular a posi��o dos dados dentro da tabela

* ----- Fun��o de Hashing -------
* - Permite calcular uma posi��o a partir de uma chave escolhida a partir dos dados;
* - � extremamente importante para o bom desempenho da tabela;
* - Respons�vel por distribuir as informa��es de forma equilibrada pela tabela hash;
*
* - Deve ser simples e barata de se calcular;
* - Garantir que valores diferentes produzam posi��es diferentes;
* - Gerar uma distribui��o equilibrada dos dados na tabela, ou seja, cada posi��o da
*   tabela tem a mesma chance de receber uma chave (m�ximo espalhamento);
*
* - A implementa��o da fun��o de hashing depende do conhecimento pr�vio da natureza e
*   dom�nio da chave a ser utilizada;
*
* ��� M�todo da Divis�o (ou da Congru�ncia Linear) ��� -> Iremos utilizar no trabalho.
*/
int chaveDivisao (int chave, int TABLE_SIZE)
{
    return (chave & 0xFFFFFFF) % TABLE_SIZE; //Esse '0xFFFFFFF' elimina o bit de sinal do valor da chave, evita n�meros negativos
}

/*--------Inser��o de Elementos sem tratamento de colis�o-------
* - Calcular a posi��o da cave no array;
* - Alocar espa�o para os dados;
* - Armazenar os dados na posi��o calculada;
*
*/
int insereHash_SemColisao(Hash  *ha, Aluno aluno)
{
    if (ha == NULL || ha -> qtd == ha -> TABLE_SIZE) //Situa��es em que n�o � poss�vel inserir
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

/*--------Busca de Elementos sem tratamento de colis�o-------
* - Calcular a posi��o da cave no array;
* - Verifica se h� dados na posi��o calculada;
* - Retorna os dados;
*/

buscaHash_SemColisao(Hash *ha, int mat, Aluno *aluno) //mat == matr�cula
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

    *aluno = *(ha -> itens[pos]); //Copia o conte�do para o ponteiro
    return 1;
}
