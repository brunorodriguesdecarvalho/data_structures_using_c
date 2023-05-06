//basic sample of a array in C language

#include <stdio.h>

int main()
{
    int array[5] = {0, 1, 2, 3, 4};
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}