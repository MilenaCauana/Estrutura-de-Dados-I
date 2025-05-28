/*Implementação TAD - Milena Cauana

    ARQUIVO MAIN!*/
#include "float_vector2.h"
#include<stdio.h>

int main ()
{
    floatVector *vec = create(10);
    print(vec);

    append(vec, 0.1);
    append(vec, 0.2);
    print(vec);

    append(vec, 0.3);
    append(vec, 0.4);
    append(vec, 0.5);
    append(vec, 0.6);
    append(vec, 0.7);
    append(vec, 0.8);
    append(vec, 0.9);
    append(vec, 0.10);
    print(vec);

    append(vec, 0.11);

    destroy(&vec);

return 0;
}
