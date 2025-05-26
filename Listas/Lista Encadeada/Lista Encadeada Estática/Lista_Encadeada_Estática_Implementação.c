/*Milena Cauana - Lista Estática Encadeada - Implementação + Criação de Funções: Inicializa a lista vazia,  Flag de lista vazia (resultado flag: TRUE se vazia e
FALSE caso contrário), Retira (retorna o item x que está na posição pos da lista mantendo a ordenação dos demais, flag = TRUE se item removido com sucesso
flag FALSE caso contrário), Insere (flags tbm), Imprime os elementos em ordem de ocorrência*/

#include<stdio.h>

#define MAX 5

//Primeiro, irei criar a lista
typedef struct
{
    int elemento;
    int prox;
} Dado;

typedef struct
{
    int disp;
    int prim;
    int ult; //Adicionei esse, para sabermos até aaonde vai a minha lista
    Dado dado[MAX];
} Lista;

//Agora, irei inicializar a lista
void Inicializa(Lista *lista)
{
    int i = 0;
    lista -> disp = 0;
    lista -> prim = -1; //Aqui, o -1 faz o papel do NULL, indicando que a lista não tem elementos
    lista -> ult = -1;
    //Agora, irei definir o prox de cada elemento da minha lista
    for (i; i < MAX - 1; i++)
    {
        lista -> dado[i].prox = i + 1;
    }
    lista -> dado[i].prox = -1; //O último elemento não aponta para nada
}

//Agora veremos se a lista está vazia, para isso, farei uma função que vizualiza unicamente o prim
int Vazia(Lista *lista)
{
    if (lista -> prim == -1)
    {
        printf("Vazia!\n");
        return -1;
    } else
    {
        printf("Nao vazia!\n");
        return 0;
    }
}

//Inserindo um elemento
void Inserir (Lista *lista, int *flag_inser, int x)
{
    if (lista -> disp == -1)
    {
        printf("Erro: Lista cheia!\n");
        *flag_inser = 0;
        return;
    }

    int indice_novo_no = lista -> disp;

    lista -> disp = lista -> dado[indice_novo_no].prox;
    lista -> dado[indice_novo_no].elemento = x;
    lista -> dado[indice_novo_no].prox = -1;

    if (lista -> prim == -1)
    {
        lista -> prim = indice_novo_no;
    } else
    {
        lista -> dado[lista -> ult].prox = indice_novo_no;
    }

    lista -> ult = indice_novo_no;
    *flag_inser = 1;
}

//Retirando um elemento
void Remover(Lista *lista, int *flag_remov, int x) //Aqui, o i seria o indice do elemento que será removido
{
    if (lista -> prim == -1)
    {
        *flag_remov = 0;
        return;
    }

    //Se a lista não estiver vazia, inicializarei o processo de busca do elemento x
    int indice_atual = lista -> prim;
    int indice_anterior = -1;

    while (indice_atual != -1 && lista -> dado[indice_atual].elemento != x)
    {
        indice_anterior = indice_atual;
        indice_atual = lista -> dado[indice_atual].prox;
    }

    //Verificaremos se o elemento 'x' foi encontrado
    if (indice_atual == -1)
    {
        printf("Elemento nao encontrado para remoção!\n");
        *flag_remov = 0;
        return;
    }

    int valor_removido = lista -> dado[indice_atual].elemento;

    //Agora, vou remover o elemento
    if (indice_anterior == -1)
    {
        lista -> prim = lista -> dado[indice_atual].prox;

        if(lista -> prim == -1)
        {
            lista -> ult = -1;
        }
    } else
    {
        lista -> dado [indice_anterior].prox = lista -> dado[indice_atual].prox;

        if (indice_atual == lista -> ult)
        {
            lista -> ult = indice_anterior;
        }
    }

    lista -> dado[indice_atual].prox = lista -> disp;
    lista -> disp = indice_atual;

    *flag_remov = 1;
}

void Imprimir(Lista *lista)
{
    printf("\n--Imprimindo--\n");

    if (lista -> prim == -1)
    {
        printf("Lista vazia!\n");
    }

    for (int i = lista -> prim; i != -1; i = lista -> dado[i].prox)
    {
        printf("Elemento %d e proximo dele esta na posicao %d\n", lista -> dado[i].elemento, lista -> dado[i].prox);
    }
}

int main ()
{
    Lista lista;

    //Inicializando a lista
    Inicializa(&lista);

    //Vamos verificar se ela foi inicializada
    printf("Primeiro: %d\n", lista.prim);
    printf("Ultimo: %d\n", lista.ult);
    printf("Disponivel: %d\n", lista.disp);

    for (int i = 0; i < MAX; i++)
    {
        printf("Elemento %d e proximo dele esta na posicao %d\n", lista.dado[i].elemento, lista.dado[i].prox);
    }

    //Agora, farei um menu, permitindo que o usuario escolha o que quer fazer
    int  x;
    do
    {
        printf("\n\nEscolha uma opcao:\n1- Inserir Elemento;\n2- Remover Elemento;\n3- Imprimir Lista;\n4- Verificar se lista está vazia;\n5-Sair\n");
        scanf("%d", &x);
        int y, flag_inser, flag_remov;

        switch(x)
        {
            case 1:
                printf("Qual elemennto deseja inserir?\n");
                scanf("%d", &y);
                Inserir(&lista, &flag_inser, y);
                if(flag_inser)
                {
                    printf("Elemento inserido com sucesso!\n");
                } else
                {
                    printf("Elemento nao inserido!");
                }
                break;
            case 2:
                printf("Qual elemennto deseja remover?\n");
                scanf("%d", &y);
                Remover(&lista, &flag_remov, y);
                if(flag_remov)
                {
                    printf("Elemento removido com sucesso!\n");
                } else
                {
                    printf("Elemento nao removido!");
                }
                break;
            case 3:
                Imprimir(&lista);
                break;
            case 4:
                Vazia(&lista);
                break;
        }
    } while (x != 5);



return 0;
}
