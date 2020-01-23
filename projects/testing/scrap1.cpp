#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void setArray(char *arr);

int main()
{
    char temp[10];

    setArray(temp);
    for(int i = 0; i < 10; i++)
    {
        printf("%c", temp[i]);
    }

    return 0;
}

void setArray(char *arr)
{
    for(int i = 0; i < 10; i++)
    {
        arr[i] = 48+i;
    }
}