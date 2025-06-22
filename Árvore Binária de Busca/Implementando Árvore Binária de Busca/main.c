#include <stdio.h>
#include "Implementando_ArvBinBusc.h"

int main ()
{
     ArvBin *raiz = cria_ArvBinBusc();
     int x, y;

     //Fazendo um menu
     do {
         printf("\n\n=========== MENU ==========\n");
         printf("Escolha uma opcao: \n");
         printf("1. Verificar se esta vazia.\n");
         printf("2. Inserir Elemento.\n");
         printf("3. Remover Elemento.\n");
         printf("4. Imprimir Arvore\n");
         printf("0. Sair.\n");
         printf("Opcao:");
         scanf("%d", &x);

         if (x == 1)
            if (estaVazia_ArvBinBusc(raiz))
            {
                printf("Esta Vazia!\n");
            } else
            {
                printf("Nao esta Vazia!\n");
            }

         if (x == 2)
         {
             printf("Valor a ser inserido: ");
             scanf("%d", &y);

             if (insere_ArvBinBusc (raiz, y))
             {
                 printf("Inserido com sucesso!\n");
             } else
             {
                 printf("Nao foi possivel inserir!\n");
             }
         }

         if (x == 3)
         {
             printf("Valor a ser removido: ");
             scanf("%d", &y);

             if (remove_ArvBinBusc(raiz, y))
             {
                 printf("Removido com sucesso!\n");
             } else
             {
                 printf("Nao foi possivel remover!\n");
             }
         }

         if (x == 4)
         {
             posOrdem_ArvBinBusc(raiz);
         }

         if (x == 0)
         {
             printf("Obrigada!\n");
             break;
         }


     } while (x != 0);

     void libera_ArvBinBusc(raiz);


return 0;
}
