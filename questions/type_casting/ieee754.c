
#include <stdio.h>
#include <stdint.h>

//
// What do you meant by IEEE754 ?
// Explain IEEE754 standard in detail.
//
//
//

#define IEEE754(x)  ( *((uint32_t*)&x) )

int main(void)
{
    static float x[] = { 1.0f, 2.5f, -0.125f, -2939.4882f };

    int index;

    //
    // Why is the specific output coming when typecasting float to int by reference.
    // 

    for( index = 0 ; index < sizeof(x)/sizeof(x[0]) ; index++ )
    {
        printf("IEEE754 representation of %f : 0x%x\n", x[index], IEEE754(x[index]) );
    }

    return 0;
}