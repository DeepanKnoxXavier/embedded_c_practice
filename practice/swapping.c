#include <stdio.h>
#include <stdint.h>

int main(void)
{
    //  What the values of instance 1, instance 2 & instance 3 of variable var ?
    //  Value of 1st instance of var: 0x06641295
    //  Value of 2nd instance of var: 0x95126406
    //  Value of 3rd instance of var: 0x6A219809
    //  Your explanation (mandatory):
    //  1. Instance 1 swaps the upper and lower 16 bits (0x1295 <-> 0x0664).
    //  2. Instance 2 reverses the byte order (Little Endian <-> Big Endian swap).
    //     (0x06641295 -> 0x95, 0x12, 0x64, 0x06 -> 0x95126406).
    //  3. Instance 3 swaps adjacent bits using alternating bit masks (0x55/0xAA).
    //     (e.g., Hex '9' [1001] becomes '6' [0110]).

    uint32_t var = 0x12950664;

    var = ( ( var & 0x0000FFFF ) << 16 ) | ( ( var >> 16 ) & 0x0000FFFF );
    
    printf("Value of var (first instance): 0x%.8x\n", var);

    var = ( ( var & 0x000000FF ) << 24 ) | ( ( var & 0x0000FF00 ) << 8 ) | ( ( var & 0x00FF0000 ) >> 8 ) | ( ( var & 0xFF000000 ) >> 24 ); 

    printf("Value of var (second instance): 0x%.8x\n", var);

    var = ( ( var & 0x55555555 ) << 1 ) | ( ( var & 0xAAAAAAAA ) >> 1 );

    printf("Value of var (third instance): 0x%.8x\n", var );

    return 0;
}
