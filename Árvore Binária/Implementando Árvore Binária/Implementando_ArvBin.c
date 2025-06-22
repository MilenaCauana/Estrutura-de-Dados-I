/*  --- IMPLEMENTAÇÃO ÁRVORE BINÁRIA ---
* É possível realizar as seguintes operações:
* - Criação da árvore;
* - Inserção de um elemento;
* - Remoção de um elemento;
* - Acesso a um elemento;
* - Destruição da árvore;
*
*  Essas operações dependem do tipos de alocação de memória usasa: estática ou dinâmica.
*
* --Alocação Estática (heap)--
*   - Uso de Array;
*   - Usa 2 funções para retornar a posição dos filhos à esquerda e à direita de um pai.
*      FILHOS_ESQ(PAI) = 2 * PAI + 1;
*      FILHOS_DIR(PAI) = 2 * PAI + 2;
*
* --Alocação Dinâmica (lista encadeada)--
*   - Cada nó da árvore é tratado como um ponteiro alocado dinamicamente a medida que  os dados são inseridos;
*     Veja:
*
*               [ *esq  |  dado  |  *dir  ]
*                   /                  \
*                  /                    \
*   [ *esq  |  dado  |  *dir  ]       [ *esq  |  dado  |  *dir  ]
*
*/

/* -- IMPLEMENTANDO UMA ÁRVORE BINÁRIA COM ALOCAÇÃO DINÂMICA --
*Para guardar o primeiro nó da árvore utilizaremos um "ponteiro para ponteiro", poisson_distributio
*pois, ele pode guardar o endereço de um "ponteiro". Assim, fica fácil mudar quem é a "raiz" da árvore.
*/

// ===================== CÓDIGO ===================
#include <stdio.h>
#include <stdlib.h>
#include "Implementando_ArvBin.h"

// --- Definindo estruturas ---
struct NO
{
    int info;
    struct NO *esq;
    struct NO *dir;
};

//Fazendo o ponteiro para o ponteiro
ArvBin *raiz; //--> Ponteiro para o endereço do ponteiro da raiz

/*
* -- Função de criação da árvore --
* Consiste no ato de criar a "raiz" da árvore. A "raiz" é um tipo de nó especial que aponta
* para o primeiro elemento da árvore.
*
* RETORNA:  raiz ---> NULL; //Ponteiro para um ponteiro do tipo NO apontando para NULL
*
*/
ArvBin *cria_ArvBin()
{
    ArvBin *raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if (raiz != NULL)
    {
        *raiz = NULL;
    }

    return raiz;
}

/*
* -- Função de Destruição da árvore --
* Envolve percorrer todos os nós da árvore de modo a liberar a memória alocada para cada um deles.
*
*/

//Primeiro, uma função que irá liberar cada nó
void libera_NO(struct NO *no)
{
    if (no == NULL)
    {
        return;
    }
    libera_NO(no -> esq);
    libera_NO(no -> dir);
    free(no);
    no = NULL;

}

//Agora, teremos uma função que irá chamar a função recursiva acima e
//depois liberar a raiz
void libera_ArvBin(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}

// --- Funções que trazem informações sobre a árvore ---

/*
* Função que diz se a árvore está vazia
*/
int estaVazia_ArvBin(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return 1;
    }
    if (*raiz == NULL) //Verifica se o conteúdo para o qual rais aponta é nulo
    {
        return 1;
    }
    return 0;
}

/*
* Função que passa a altura da árvore
*/
int altura_ArvBin(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    if (*raiz == NULL)
    {
        return 0;
    }

    int alt_esq = altura_ArvBin(&((*raiz) -> esq));
    int alt_dir = altura_ArvBin(&((*raiz) -> dir));
    if (alt_esq > alt_dir)
    {
        return (alt_esq + 1);
    } else
    {
        return (alt_dir + 1);
    }
}


/*
* Função que o número total de nós da árvore
*/
int totalNO_ArvBin(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    if (*raiz == NULL)
    {
        return 0;
    }

    int alt_esq = totalNO_ArvBin(&((*raiz) -> esq));
    int alt_dir = totalNO_ArvBin(&((*raiz) -> dir));

    return (alt_esq + alt_dir + 1);
}


// --- Função para percorrer a Árvore Binária ---
/* Pode-se percorrer a árvore de três formas diferentes.
*
* - PRÉ-ORDEM:
*   Visita a "raiz", o filho da "esquerda" e o filho da "direita";
*
* - EM-ORDEM:
* Visita o filgo da "esquerda", a "raiz" e o filho da "direita".
*
* - PÓS-ORDEM:
* Visita o filho da "esquerda", o filho da "direita" e a "raiz";
*/
void preOrdem_ArvBin(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    if (*raiz != NULL)
    {
        printf("%d\n", (*raiz) -> info);
        preOrdem_ArvBin(&((*raiz) -> esq));
        preOrdem_ArvBin(&((*raiz) -> dir));

    }
}

void emOrdem_ArvBin(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    if (*raiz != NULL)
    {
        emOrdem_ArvBin(&((*raiz) -> esq));

        printf("%d\n", (*raiz) -> info);

        emOrdem_ArvBin(&((*raiz) -> dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    if (*raiz != NULL)
    {
        posOrdem_ArvBin(&((*raiz) -> esq));
        posOrdem_ArvBin(&((*raiz) -> dir));

        printf("%d\n", (*raiz) -> info);
    }
}

