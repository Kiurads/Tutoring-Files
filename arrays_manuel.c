#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[10];

    for (int i = 0; i < 10; i++)
    {
        array[i] = (i + 1) * 2;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
    
}