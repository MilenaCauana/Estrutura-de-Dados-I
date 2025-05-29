/*Implementação TAD - Milena Cauana

    ARQUIVO MAIN!*/
#include "float_vector2.h"
#include<stdio.h>

int main ()
{
    floatVector *vec = floatVector_create(10);
    floatVector_print(vec);

    floatVector_append(vec, 0.1);
    floatVector_append(vec, 0.2);
    floatVector_print(vec);

    floatVector_append(vec, 0.3);
    floatVector_append(vec, 0.4);
    floatVector_append(vec, 0.5);
    floatVector_append(vec, 0.6);
    floatVector_append(vec, 0.7);
    floatVector_append(vec, 0.8);
    floatVector_append(vec, 0.9);
    floatVector_append(vec, 0.10);
    floatVector_print(vec);

    floatVector_append(vec, 0.11);

    floatVector_destroy(&vec);

return 0;
}
