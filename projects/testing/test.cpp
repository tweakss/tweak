#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int intToChar(int num, char *arr);

int main()
{
    char charsOfInt[10];
    int endOfInt;

    endOfInt = intToChar(98564, charsOfInt) - 1;
    printf("endOfInt:%d\n", endOfInt);
    for(int i = endOfInt; i >= 0; i--)
    {
        //printf("i is: %d, %c\n", i, charsOfInt[i]);
        printf("%c", charsOfInt[i]);
    }

    return 0;
}

int intToChar(int num, char *arr)
{
	int digit;
    int index = 0;

	for (int i = num; i > 0; i /= 10)
	{
		printf("i = %d\n", i);
        digit = i % 10;
        printf("digit: %d ", digit);
        arr[index] = digit + 48;
        printf("index is: %d, charsOfInt[%d]: %d\n", index, index, arr[index]);
        index++;
    
	}
    return index;
}