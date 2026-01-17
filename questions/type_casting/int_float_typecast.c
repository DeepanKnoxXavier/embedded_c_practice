
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int a = 100;
    int b = 16;

    float result1;
    float result2;

    result1 = (float)(a/b);
    result2 = (float)a / (float)b;

    //
    // What will the value of result1 and result2?
    //
    // Your answer:
    // result1 = 
    // result2 = 
    //
    // Your explanation (mandatory):
    //
    //
    //
    //

    printf("Result of first operation: %f\n", result1);
    printf("Result of second operation: %f\n", result2);

    //
    // Will result1 be equal to result2 before integer typecasting?
    // Will result1 be equal to result2 after typecasting?
    //
    // Your answer & explanation (mandatory)
    //
    //
    //
    //

    if( result1 == result2 )
    {
        printf("Results 1 and 2 are equal\n");
    }
    else
    {
        printf("Results 1 and 2 are not equal\n");
    }

    //
    // Will result1 be equal to result2 before integer typecasting?
    // Will result1 be equal to result2 after typecasting?
    //
    // Your answer & explanation (mandatory)
    //
    //
    //
    //

    result1 = (float)((int)result1);
    result2 = (float)((int)result2);

    if( result1 == result2 )
    {
        printf("Results 1 and 2 are equal\n");
    }
    else
    {
        printf("Results 1 and 2 are not equal\n");
    }

    return 0;
}