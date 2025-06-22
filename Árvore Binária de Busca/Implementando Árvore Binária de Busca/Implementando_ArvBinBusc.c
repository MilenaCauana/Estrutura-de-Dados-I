//Primeiro, aproveitarei todos os códigos feitos para a Árvore Binária

#include <stdio.h>
#include <stdlib.h>
#include "Implementando_ArvBinBusc.h"

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
ArvBin *cria_ArvBinBusc()
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
void libera_ArvBinBusc(ArvBin *raiz)
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
int estaVazia_ArvBinBusc(ArvBin *raiz)
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
int altura_ArvBinBusc(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    if (*raiz == NULL)
    {
        return 0;
    }

    int alt_esq = altura_ArvBinBusc(&((*raiz) -> esq));
    int alt_dir = altura_ArvBinBusc(&((*raiz) -> dir));
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
int totalNO_ArvBinBusc(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    if (*raiz == NULL)
    {
        return 0;
    }

    int alt_esq = totalNO_ArvBinBusc(&((*raiz) -> esq));
    int alt_dir = totalNO_ArvBinBusc(&((*raiz) -> dir));

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
void preOrdem_ArvBinBusc(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    if (*raiz != NULL)
    {
        printf("%d\n", (*raiz) -> info);
        preOrdem_ArvBinBusc(&((*raiz) -> esq));
        preOrdem_ArvBinBusc(&((*raiz) -> dir));

    }
}

void emOrdem_ArvBinBusc(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    if (*raiz != NULL)
    {
        emOrdem_ArvBinBusc(&((*raiz) -> esq));

        printf("%d\n", (*raiz) -> info);

        emOrdem_ArvBinBusc(&((*raiz) -> dir));
    }
}

void posOrdem_ArvBinBusc(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    if (*raiz != NULL)
    {
        posOrdem_ArvBinBusc(&((*raiz) -> esq));
        posOrdem_ArvBinBusc(&((*raiz) -> dir));

        printf("%d\n", (*raiz) -> info);
    }
}

// ========= INSERÇÃO ===========
// Retorna 0 se não deu certo ou 1 se deu certo.
int insere_ArvBinBusc (ArvBin *raiz, int valor)
{
    if (raiz == NULL)
    {
        return 0; // Raiz inválida
    }

    // Criar o novo nó
    struct NO *novo = (struct NO*) malloc(sizeof(struct NO));
    if (novo == NULL)
    {
        return 0; // Erro de alocação de memória
    }
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    // Inserir o nó na árvore
    if (*raiz == NULL) // Árvore vazia: o novo nó se torna a raiz
    {
        *raiz = novo;
    }
    else // Árvore não vazia: encontrar o local de inserção
    {
        struct NO *atual = *raiz;
        struct NO *ant = NULL; // Ponteiro para o pai de 'atual'

        while (atual != NULL)
        {
            ant = atual; // 'ant' sempre guarda o nó pai antes de 'atual' avançar

            if (valor == atual->info) // Elemento já existe
            {
                free(novo); // Libera o nó recém-criado
                return 0;
            }

            if (valor > atual->info)
            {
                atual = atual->dir; // Avança para a direita
            }
            else // valor < atual->info
            {
                atual = atual->esq; // Avança para a esquerda
            }
        }

        // 'atual' é NULL, então 'ant' é o nó pai onde 'novo' deve ser inserido
        if (valor > ant->info) // Se o valor for maior, insere à direita de 'ant'
        {
            ant->dir = novo;
        }
        else // Se o valor for menor, insere à esquerda de 'ant'
        {
            ant->esq = novo;
        }
    }

    return 1; // Inserido com sucesso
}

// =========== REMOÇÃO =============

/* Serão duas funções:
* A primeira será responsável pela busca do nó a ser removido
* A segunda será responsável por tratar os três tipos de remoção:
*
* - nó folha (sem filhos);
* - nó com 1 filho;
* - nó com 2 filhos;
*
*/

/*
* Função de busca
*/
int remove_ArvBinBusc(ArvBin *raiz, int valor)
{
    if (raiz == NULL)
    {
        return 0;
    }

    struct NO *ant = NULL;
    struct NO *atual = *raiz;

    while (atual != NULL)
    {
        if (valor == atual -> info) //Se achar o nó
        {
            if (atual == *raiz)
                *raiz = remove_atual(atual);
        } else
        {
            if (ant -> dir == atual)
            {
                ant -> dir = remove_atual(atual);
            } else
            {
                ant -> esq = remove_atual(atual);
            }
        }
        return 1;

        //Se ele não foi achado, eu irei na busca
        ant = atual;
        if (valor > atual -> info)
        {
            atual = atual -> dir;
        }else
        {
            atual = atual -> esq;
        }
    }
}

/*
* Função que remove o nó
*/
struct NO* remove_atual(struct NO* atual)
{
    struct NO *no1, *no2;

    if (atual -> esq == NULL)
    {
        no2 = atual -> dir;
        free(atual);
        return no2;
    }

    //Entender melhor daqui:
    no1 = atual;
    no2 = atual -> esq;

    while (no2 -> dir != NULL)
    {
        no1 = no2;
        no2 = no2 -> dir;
    }

    if (no1 != atual)
    {
        no1 -> dir = no2 -> esq;
        no2 -> esq = atual -> esq;
    }

    no2 -> dir = atual -> dir;
    free(atual);
    return no2;
}


// ========== CONSULTA ========
int consulta_ArvBinBusc (ArvBin *raiz, int valor)
{
   if (raiz == NULL)
   {
       return 0;
   }

   struct NO *atual = *raiz;

   while (atual != NULL)
   {
       if (valor == atual -> info)
       {
           return 1;
       }
       if (valor > atual -> info)
       {
           atual = atual -> dir;
       } else
       {
           atual = atual -> esq;
       }
   }

   return 0;
}
