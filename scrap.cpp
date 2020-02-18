#include <stdio.h>
#include <stdlib.h>

void* testMalloc();

int main()
{
    // void* voidPtr;
    // char str[] ={};

    // voidPtr = testMalloc();
    // printf("voidPtr: %p\n", voidPtr);
    // printf("sizeOf int in 64 bit: %zu\n", sizeof(int));
    //prinft("sizeOf str[] %zu\n", );

    char str[20] = {};
    printf("%s\n", str);
    scanf("%s", str);
    printf("%s\n", str);
    
    return 0;
}

void* testMalloc()
{
    return malloc(sizeof(int));
}