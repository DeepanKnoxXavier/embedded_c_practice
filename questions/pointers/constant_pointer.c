
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


static uint32_t variable = 0x12314232;

const uint32_t* pVariable;

int main(void)
{
    // Is assignment to this pointer variable `pVariable` permitted ?
    // Check it out yourself.
    // Make sure to comment out line 25 before compiling the code.

    pVariable = &variable;

    printf("Value of variable pointed to by the pointer: 0x%8x\n", *pVariable);

    // Will this work ?
    // Compile and check it out yourself
    // UPDATE ANSWER HERE: 

    *pVariable = 0x19203952;

    return 0;
}