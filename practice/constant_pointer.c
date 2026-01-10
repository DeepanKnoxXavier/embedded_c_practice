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

    pVariable = &variable; // This IS permitted (changing where the pointer points).

    printf("Value of variable pointed to by the pointer: 0x%8x\n", *pVariable);

    // Will this work ?
    // Compile and check it out yourself
    // UPDATE ANSWER HERE: No, this will NOT work. It results in a compilation error (assignment of read-only location).
    // EXPLANATION: The declaration `const uint32_t*` means "pointer to a constant integer".
    // While the pointer itself is mutable (you can change the address it holds), the data it points to
    // is treated as read-only. You cannot modify the value using the dereference operator (*).

    *pVariable = 0x19203952;

    return 0;
}
