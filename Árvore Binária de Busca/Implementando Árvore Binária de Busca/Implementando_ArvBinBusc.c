//Primeiro, aproveitarei todos os c�digos feitos para a �rvore Bin�ria

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
ArvBin *raiz; //--> Ponteiro para o endere�o do ponteiro da raiz

/*
* -- Fun��o de cria��o da �rvore --
* Consiste no ato de criar a "raiz" da �rvore. A "raiz" � um tipo de n� especial que aponta
* para o primeiro elemento da �rvore.
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
* -- Fun��o de Destrui��o da �rvore --
* Envolve percorrer todos os n�s da �rvore de modo a liberar a mem�ria alocada para cada um deles.
*
*/

//Primeiro, uma fun��o que ir� liberar cada n�
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

//Agora, teremos uma fun��o que ir� chamar a fun��o recursiva acima e
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

// --- Fun��es que trazem informa��es sobre a �rvore ---

/*
* Fun��o que diz se a �rvore est� vazia
*/
int estaVazia_ArvBinBusc(ArvBin *raiz)
{
    if (raiz == NULL)
    {
        return 1;
    }
    if (*raiz == NULL) //Verifica se o conte�do para o qual rais aponta � nulo
    {
        return 1;
    }
    return 0;
}

/*
* Fun��o que passa a altura da �rvore
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
* Fun��o que o n�mero total de n�s da �rvore
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


// --- Fun��o para percorrer a �rvore Bin�ria ---
/* Pode-se percorrer a �rvore de tr�s formas diferentes.
*
* - PR�-ORDEM:
*   Visita a "raiz", o filho da "esquerda" e o filho da "direita";
*
* - EM-ORDEM:
* Visita o filgo da "esquerda", a "raiz" e o filho da "direita".
*
* - P�S-ORDEM:
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

// ========= INSER��O ===========
// Retorna 0 se n�o deu certo ou 1 se deu certo.
int insere_ArvBinBusc (ArvBin *raiz, int valor)
{
    if (raiz == NULL)
    {
        return 0; // Raiz inv�lida
    }

    // Criar o novo n�
    struct NO *novo = (struct NO*) malloc(sizeof(struct NO));
    if (novo == NULL)
    {
        return 0; // Erro de aloca��o de mem�ria
    }
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    // Inserir o n� na �rvore
    if (*raiz == NULL) // �rvore vazia: o novo n� se torna a raiz
    {
        *raiz = novo;
    }
    else // �rvore n�o vazia: encontrar o local de inser��o
    {
        struct NO *atual = *raiz;
        struct NO *ant = NULL; // Ponteiro para o pai de 'atual'

        while (atual != NULL)
        {
            ant = atual; // 'ant' sempre guarda o n� pai antes de 'atual' avan�ar

            if (valor == atual->info) // Elemento j� existe
            {
                free(novo); // Libera o n� rec�m-criado
                return 0;
            }

            if (valor > atual->info)
            {
                atual = atual->dir; // Avan�a para a direita
            }
            else // valor < atual->info
            {
                atual = atual->esq; // Avan�a para a esquerda
            }
        }

        // 'atual' � NULL, ent�o 'ant' � o n� pai onde 'novo' deve ser inserido
        if (valor > ant->info) // Se o valor for maior, insere � direita de 'ant'
        {
            ant->dir = novo;
        }
        else // Se o valor for menor, insere � esquerda de 'ant'
        {
            ant->esq = novo;
        }
    }

    return 1; // Inserido com sucesso
}

// =========== REMO��O =============

/* Ser�o duas fun��es:
* A primeira ser� respons�vel pela busca do n� a ser removido
* A segunda ser� respons�vel por tratar os tr�s tipos de remo��o:
*
* - n� folha (sem filhos);
* - n� com 1 filho;
* - n� com 2 filhos;
*
*/

/*
* Fun��o de busca
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
        if (valor == atual -> info) //Se achar o n�
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

        //Se ele n�o foi achado, eu irei na busca
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
* Fun��o que remove o n�
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
