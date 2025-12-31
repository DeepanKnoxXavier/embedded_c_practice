
#include <stdio.h>
#include <stdint.h>


int main(void)
{
    //  What the values of instance 1, instance 2 & instance 3 of variable var ?
    //  Value of 1st instance of var:
    //  Value of 2nd instance of var:
    //  Value of 3rd instance of var:
    //  Your explanation (mandatory):
    //
    //
    //

    uint32_t var = 0x12950664;

    var = ( ( var & 0x0000FFFF ) << 16 ) | ( ( var >> 16 ) & 0x0000FFFF );
    
    printf("Value of var (first instance): 0x%.8x\n", var);

    var = ( ( var & 0x000000FF ) << 24 ) | ( ( var & 0x0000FF00 ) << 8 ) | ( ( var & 0x00FF0000 ) >> 8 ) | ( ( var & 0xFF000000 ) >> 24 ); 

    printf("Value of var (second instance): 0x%.8x\n", var);

    var = ( ( var & 0x55555555 ) << 1 ) | ( ( var & 0xAAAAAAAA ) >> 1 );

    printf("Value of var (third instance): 0x%.8x\n", var );

    return 0;
}