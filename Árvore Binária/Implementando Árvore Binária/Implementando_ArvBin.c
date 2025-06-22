/*  --- IMPLEMENTA��O �RVORE BIN�RIA ---
* � poss�vel realizar as seguintes opera��es:
* - Cria��o da �rvore;
* - Inser��o de um elemento;
* - Remo��o de um elemento;
* - Acesso a um elemento;
* - Destrui��o da �rvore;
*
*  Essas opera��es dependem do tipos de aloca��o de mem�ria usasa: est�tica ou din�mica.
*
* --Aloca��o Est�tica (heap)--
*   - Uso de Array;
*   - Usa 2 fun��es para retornar a posi��o dos filhos � esquerda e � direita de um pai.
*      FILHOS_ESQ(PAI) = 2 * PAI + 1;
*      FILHOS_DIR(PAI) = 2 * PAI + 2;
*
* --Aloca��o Din�mica (lista encadeada)--
*   - Cada n� da �rvore � tratado como um ponteiro alocado dinamicamente a medida que  os dados s�o inseridos;
*     Veja:
*
*               [ *esq  |  dado  |  *dir  ]
*                   /                  \
*                  /                    \
*   [ *esq  |  dado  |  *dir  ]       [ *esq  |  dado  |  *dir  ]
*
*/

/* -- IMPLEMENTANDO UMA �RVORE BIN�RIA COM ALOCA��O DIN�MICA --
*Para guardar o primeiro n� da �rvore utilizaremos um "ponteiro para ponteiro", poisson_distributio
*pois, ele pode guardar o endere�o de um "ponteiro". Assim, fica f�cil mudar quem � a "raiz" da �rvore.
*/

// ===================== C�DIGO ===================
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
ArvBin *raiz; //--> Ponteiro para o endere�o do ponteiro da raiz

/*
* -- Fun��o de cria��o da �rvore --
* Consiste no ato de criar a "raiz" da �rvore. A "raiz" � um tipo de n� especial que aponta
* para o primeiro elemento da �rvore.
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
void libera_ArvBin(ArvBin *raiz)
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
int estaVazia_ArvBin(ArvBin *raiz)
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
* Fun��o que o n�mero total de n�s da �rvore
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

