#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[5];

    for (int i = 0; i < 5; i++)
    {
        array[i] = i + i;
    }

    printf("%d", *(array + 3));
}