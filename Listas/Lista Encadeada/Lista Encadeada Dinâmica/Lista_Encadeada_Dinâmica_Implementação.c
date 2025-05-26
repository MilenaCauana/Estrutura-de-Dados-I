/*Milena Cauana - Lista Encadeada Din�mica - Implementando com opera��es*/
#include <stdio.h>
#include<stdlib.h>

//--Defini��es das Estruturas Internas (Privadas)--

//Definindo a estrutura da lista
typedef struct no
{
    int dado;
    struct no *prox;
} No;

//Criando o descritor para a lista
typedef struct
{
    No *inicio;
    No *fim;
    int tamanho;
} Descritor;

//Definirei 'Lista' como um ponteiro para o descritor
typedef Descritor *Lista;

//--Opera��es--

//Inicializando a lista
Lista inicializaLista() //Retorna um ponteiro para uma estrutura Descritor
{
    Lista descritor = (Lista) malloc(sizeof(Descritor));

    if (descritor != NULL)
    {
        descritor -> inicio = NULL;
        descritor -> fim = NULL;
        descritor -> tamanho = 0;
        printf("Lista Inicializada com sucesso!\n");
    } else
    {
        perror("Erro ao alocar mem�ria para o descritor da lista");
    }

    return descritor;
}

//Destruindo a lista
void destruir_lista(Lista *ptr)
{
    //Verifica se os ponteiros s�o v�lidos
    if (ptr == NULL || *ptr == NULL)
    {
        printf("Ponteiro para a lista invalido ou lista ja destruida.\n");
        return;
    }

    Lista l = *ptr;

    No *atual = l -> inicio;
    No *proximo_no;

    printf("Come�ando a liberar nos da lista...\n");
    while (atual != NULL)
    {
        proximo_no = atual -> prox; //Aqui, estou armazenando o endere�o do pr�ximo n�, para ele n�o ser perdido quando eu liberar o anterior
        free(atual);
        atual = proximo_no;
    }

    printf("Liberando descritor.\n");
    free(l);

    *ptr = NULL;
    printf("Lista destruida.\n");

}

//Fun��o de inser��o (o primeiro a ser colocado � o primeiro, e ao passo em que novos
//elementos s�o inseridos, eles v�o se tornando o �ltimo
void insereNo(int elemento, Lista lista)
{
    //Verificando se o ponteiro � v�lido
    if (lista == NULL)
    {
        printf("Erro: tentativa de inserir em lista NULA.\n");
        return;
    }

    No *novoNo;
    novoNo = (No *) malloc (sizeof(No));

    //Verificando se o espa�o foi alocado
    if (novoNo == NULL)
    {
        perror("O novo no nao foi alocado");
        return;
    }

    //Se ele foi alocado, continuar� a execu��o dessa fun��o
    novoNo -> dado = elemento;
    novoNo -> prox = NULL;

    //Verificando se � o primeiro elemento da lista
    if (lista -> inicio == NULL)
    {
        lista -> inicio = novoNo;
    } else
    {
        lista -> fim -> prox = novoNo;
    }

    lista -> fim = novoNo;
    lista -> tamanho ++;
}

//Fun��o de Remo��o
//O primeiro e �ltimo elemento, eu tenho que alterar os par�metros (inicio, fim)
//Os do meio, o anterior tem que apontar para o pr�ximo,
//Ou seja, terei que guardar o endere�o do elemento anterior
void Remove(int elem, Lista lista)
{
    if (lista == NULL || lista -> tamanho == 0)
    {
        printf("Lista NULA ou vazia, nada a remover.\n");
        return;
    }

    No *atual = lista -> inicio;
    No *anterior = NULL;

    //Iremos percorrer a lista, a fim de achar o elemento que ser� removido
    while (atual!= NULL && atual -> dado != elem)
    {
        anterior = atual;
        atual = atual -> prox;
    }

    if (atual == NULL)
    {
        printf("Elemento nao encontrado!\n");
        return;
    }

    if (anterior == NULL) //Aqui, verificaremos se ele � o primeiro
    {
        lista -> inicio = atual -> prox;
    } else //Se n�o, ent�o, o anterior a ele ter� de apontar para o pr�ximo
    {
        anterior -> prox = atual -> prox;
    }

    if (atual == lista -> fim) //Verificando se � o �ltimo
    {
        lista -> fim = anterior;
    }

    free(atual);

    lista -> tamanho --;
}

//Imprimindo a lista
void Imprimir(Lista lista)
{
    //Verificando se o ponteiro para p descritor � v�lido
    if (lista == NULL)
    {
        printf("Lista NULA ou destruida.\n");
        return;
    }

    //Verificando se a lista est� vazia
    if (lista -> inicio == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    //Agora, irei criar um ponteiro auxiliar para o tipo No, para poder utilizar ele para printar
    No *aux = lista -> inicio;

    //Ele receber� o primeiro elemento e assim, percorrer� a lista
    while (aux != NULL)
    {
        printf("\nElemento =  %d", aux -> dado);
        aux = aux -> prox; //Aqui, ele ir� receber o endere�o de mem�ria do pr�ximo elemento
    }
}

//Fun��o para verificar se a lista est� vazia
int vazia(Lista lista)
{
    if (lista -> inicio == NULL)
    {
        return 1;
    }
    return 0;
}

//Buscando um elemento na lista e retornando sua refer�ncia caso seja encontrado
No * busca (int elem, Lista lista)
{
    //Verificando se o ponteiro para o descritor esta valido
    if (lista == NULL)
    {
        printf("Lista NULA.\n");
        return NULL;
    }
    //Primeiro, verificando se a lista est� vazia
    if (lista -> inicio == NULL)
    {
        printf("Lista vazia!\n");
        return NULL;
    }

    No *p;

    for (p = lista -> inicio; p != NULL; p = p -> prox)
    {
        if (p -> dado == elem)
        {
            return  p;
        }
    }

    return NULL;
}

int main ()
{
    Lista minha_lista = NULL; //Aqui, criei um ponteiro para o descritor da lista
    int x, y;

    printf("-- Testando a lista --\n");

    minha_lista = inicializaLista();
    if (minha_lista == NULL)
    {
        return 1;
    }

    do
    {
        printf("\n\n");
        printf("Escolha uma op�ao:\n1)Inserir Elemento;\n2)Remover Elemento;\n3)Imprimir Lista;\n4)Lista Vazia?;\n5)Destruir Lista;\n6)Sair;\n");
        scanf("%d", &x);

        switch(x)
        {
            case 1:
                printf("Elemento que sera inserido: ");
                scanf("%d", &y);
                insereNo(y, minha_lista);
                break;

            case 2:
                printf("Elemento que sera removido: ");
                scanf("%d", &y);
                Remove(y, minha_lista);
                break;

            case 3:
                printf("--Imprimindo lista--\n");
                Imprimir(minha_lista);
                break;

            case 4:
                if (vazia(minha_lista))
                {
                    printf("Sim1\n");
                } else
                {
                    printf("N�o!\n");
                }
                break;

            case 5:
                destruir_lista(&minha_lista);
                break;
        }

    }while(x != 6);

return 0;
}
