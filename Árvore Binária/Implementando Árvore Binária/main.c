#include <stdio.h>
#include "Implementando_ArvBin.h"

int main ()
{
    ArvBin *raiz =  cria_ArvBin();

    if (estaVazia_ArvBin(raiz))
    {
        printf("Arvore vazia!\n");
    } else
    {
        printf("Arvore NAO vazia!\n");
    }

    libera_ArvBin(raiz);

return 0;
}
