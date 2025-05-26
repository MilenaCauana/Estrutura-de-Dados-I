/*Milena Cauana - Lista Encadeada Dinâmica - Implementando com operações*/
#include <stdio.h>
#include<stdlib.h>

//--Definições das Estruturas Internas (Privadas)--

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

//--Operações--

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
        perror("Erro ao alocar memória para o descritor da lista");
    }

    return descritor;
}

//Destruindo a lista
void destruir_lista(Lista *ptr)
{
    //Verifica se os ponteiros são válidos
    if (ptr == NULL || *ptr == NULL)
    {
        printf("Ponteiro para a lista invalido ou lista ja destruida.\n");
        return;
    }

    Lista l = *ptr;

    No *atual = l -> inicio;
    No *proximo_no;

    printf("Começando a liberar nos da lista...\n");
    while (atual != NULL)
    {
        proximo_no = atual -> prox; //Aqui, estou armazenando o endereço do próximo nó, para ele não ser perdido quando eu liberar o anterior
        free(atual);
        atual = proximo_no;
    }

    printf("Liberando descritor.\n");
    free(l);

    *ptr = NULL;
    printf("Lista destruida.\n");

}

//Função de inserção (o primeiro a ser colocado é o primeiro, e ao passo em que novos
//elementos são inseridos, eles vão se tornando o último
void insereNo(int elemento, Lista lista)
{
    //Verificando se o ponteiro é válido
    if (lista == NULL)
    {
        printf("Erro: tentativa de inserir em lista NULA.\n");
        return;
    }

    No *novoNo;
    novoNo = (No *) malloc (sizeof(No));

    //Verificando se o espaço foi alocado
    if (novoNo == NULL)
    {
        perror("O novo no nao foi alocado");
        return;
    }

    //Se ele foi alocado, continuará a execução dessa função
    novoNo -> dado = elemento;
    novoNo -> prox = NULL;

    //Verificando se é o primeiro elemento da lista
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

//Função de Remoção
//O primeiro e último elemento, eu tenho que alterar os parâmetros (inicio, fim)
//Os do meio, o anterior tem que apontar para o próximo,
//Ou seja, terei que guardar o endereço do elemento anterior
void Remove(int elem, Lista lista)
{
    if (lista == NULL || lista -> tamanho == 0)
    {
        printf("Lista NULA ou vazia, nada a remover.\n");
        return;
    }

    No *atual = lista -> inicio;
    No *anterior = NULL;

    //Iremos percorrer a lista, a fim de achar o elemento que será removido
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

    if (anterior == NULL) //Aqui, verificaremos se ele é o primeiro
    {
        lista -> inicio = atual -> prox;
    } else //Se não, então, o anterior a ele terá de apontar para o próximo
    {
        anterior -> prox = atual -> prox;
    }

    if (atual == lista -> fim) //Verificando se é o último
    {
        lista -> fim = anterior;
    }

    free(atual);

    lista -> tamanho --;
}

//Imprimindo a lista
void Imprimir(Lista lista)
{
    //Verificando se o ponteiro para p descritor é válido
    if (lista == NULL)
    {
        printf("Lista NULA ou destruida.\n");
        return;
    }

    //Verificando se a lista está vazia
    if (lista -> inicio == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    //Agora, irei criar um ponteiro auxiliar para o tipo No, para poder utilizar ele para printar
    No *aux = lista -> inicio;

    //Ele receberá o primeiro elemento e assim, percorrerá a lista
    while (aux != NULL)
    {
        printf("\nElemento =  %d", aux -> dado);
        aux = aux -> prox; //Aqui, ele irá receber o endereço de memória do próximo elemento
    }
}

//Função para verificar se a lista está vazia
int vazia(Lista lista)
{
    if (lista -> inicio == NULL)
    {
        return 1;
    }
    return 0;
}

//Buscando um elemento na lista e retornando sua referência caso seja encontrado
No * busca (int elem, Lista lista)
{
    //Verificando se o ponteiro para o descritor esta valido
    if (lista == NULL)
    {
        printf("Lista NULA.\n");
        return NULL;
    }
    //Primeiro, verificando se a lista está vazia
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
        printf("Escolha uma opçao:\n1)Inserir Elemento;\n2)Remover Elemento;\n3)Imprimir Lista;\n4)Lista Vazia?;\n5)Destruir Lista;\n6)Sair;\n");
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
                    printf("Não!\n");
                }
                break;

            case 5:
                destruir_lista(&minha_lista);
                break;
        }

    }while(x != 6);

return 0;
}
