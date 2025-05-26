/*Milena Cauana - Exercício Lista Estática Sequencial - Implementar as seguintes operações em uma lista estática sequencial:

● Inserção de um elemento na posição i
● Remoção do i-ésino elemento
● Imprimir a lista de forma recursiva*/

#include<stdio.h>
#include <stdbool.h>

#define MAX 15

//Criaremos uma estrutura para podermos ter o vetor de inteiros e uma variável que irá armazenar a quantidade de elementos que meu vetor tem
typedef struct
{
    int minha_lista[MAX];
    int qtdElemento;
} Lista;

//Para inserir um elemento, iremos fazer uma função
void inserir_elemento(int elemento, Lista *lista)
{
    int aux, i;

    //Primeiro, iremos verficar se a string está cheia
    if (lista->qtdElemento == MAX)
    {
        printf("Lista Cheia!!");
        return;
    } else if (lista->qtdElemento == 0)
    {
        lista->minha_lista[0] = elemento;
        lista->qtdElemento ++;
        return;
    } else
    {
        //Agora, verificaremos em que local da lista (que deve estar ordenada) o elemento será inserido
        for(i = 0; i < lista->qtdElemento; i++)
        {
            if (lista->minha_lista[i] > elemento)
            {
                break;
            }
        }

        //Agora, iremos inserir o elemento na lista
        for (int j = i; j <= lista->qtdElemento; j++)
        {
            aux = lista->minha_lista[j];
            lista->minha_lista[j] = elemento;
            elemento = aux;
        }

        lista->qtdElemento ++;
    }
}

//Para remover o i-ésimo elemnto, faremos uma função
void removendo_elemento(int elemento, Lista *lista)
{
    int indice, aux;
    _Bool estaNaLista = false;

    //Primeiro, iremos procurar o elemento
    for (int i = 0; i < lista->qtdElemento; i++)
    {
        if(lista->minha_lista[i] == elemento)
        {
            estaNaLista = true;
            indice = i;
            break;
        }
    }

    //Se nao estiver na lista
    if (!estaNaLista)
    {
        printf("Elemento nao existe na lista.");
        return;
    }

    //Se acharmos o elemento, iremos removê-lo
    for (int j = indice; j < lista->qtdElemento - 1; j++)
    {
        lista->minha_lista[j] = lista->minha_lista[j + 1];
    }
    lista->qtdElemento--;
}

int main ()
{
    int elemento, qtdElementoFornecido;
    Lista lista;

    lista.qtdElemento = 0;//Aqui, estou inicializando minha lista com zero

    //Recebendo os elementos do usuário
    printf("Quantos elementos: \n");
    scanf("%d", &qtdElementoFornecido);

    printf("Forneca %d numeros: \n", qtdElementoFornecido);
    for (int i = 0; i < qtdElementoFornecido; i++)
    {
        scanf("%d", &elemento);
        inserir_elemento(elemento, &lista);
    }

    //Imprimindo a lista Inicializada
    printf("\n\nLista:\n");
    for (int i = 0; i < lista.qtdElemento; i++)
    {
        printf("\n%d", lista.minha_lista[i]);
    }

    //Removendo um elemento
    printf("\n\nRemovendo Elemento: \n");
    printf("Elemento: ");
    scanf("%d", &elemento);

    removendo_elemento(elemento, &lista);

    //Imprimindo a lista Sem o elemento
    printf("\n\nLista Removida:\n");
    for (int i = 0; i < lista.qtdElemento; i++)
    {
        printf("\n%d", lista.minha_lista[i]);
    }

return 0;
}
