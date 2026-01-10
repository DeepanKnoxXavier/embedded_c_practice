#include <stdint.h>
#include <stdio.h>

// Explain what these macros do ?
//
//
//
//

#define BIT_MASK(size, position)                    ( ( ( 1U << size ) - 1U ) << position )
#define BIT_SHIFT(value,shift)                      ( (int)shift >= 0 ) ? ( value << shift ) : ( value >> (-(int)shift) )
#define BIT_GET_FIELD(var, size, position)          ( ( var & BIT_MASK(size,position) ) >> position )
#define BIT_SET_FIELD(var, field, size, position)   ( ( var & ~BIT_MASK(size,position) ) | ( field << position ) )

int main(void)
{
    uint32_t var = 12;

    var = BIT_SHIFT( var, 5 );
    var = BIT_SHIFT( var, -3 );
    var = BIT_SET_FIELD( var, 3, 2, 0 );

    //  What will be the output of the first instance of var ?
// YOUR ANSWER: 51
// YOUR REASON (mandatory): 
// The variable starts at 12. It is left-shifted by 5 (result 384) and then right-shifted by 3 (result 48). 
// Finally, the SET_FIELD macro sets the first 2 bits (LSB) to 3 (binary 11). 
// 48 (110000) | 3 (000011) = 51.

    printf("Value of variable var = %d (first instance)\n", var );

    var += BIT_GET_FIELD( var, 2, 2 );
    var += BIT_GET_FIELD( var, 2, 0 );
    var = BIT_SHIFT( var, -1 );

    //  //  What will be the output of the second instance of var ?
// YOUR ANSWER: 27
// YOUR REASON (mandatory): 
// var is 51 (00110011). GET_FIELD at position 2 (bits 2-3) returns 0; var remains 51.
// GET_FIELD at position 0 (bits 0-1) returns 3; var becomes 51 + 3 = 54.
// Finally, a negative shift of -1 causes a right shift by 1. 54 >> 1 = 27.
    //
    //
    //

    printf("Value of variable var = %d (second instance)\n", var );

    var -= BIT_SHIFT( 1, 2 );
    var += BIT_SET_FIELD( var, 14, 4, 0 );
    var += BIT_SET_FIELD( var, 1, 1, 1 );

    //  //  What will be the output of the third instance of var ?
// YOUR ANSWER: 108
// YOUR REASON (mandatory): 
// var starts at 27. We subtract (1 << 2) = 4, so var becomes 23.
// The code then uses `+=` (addition) rather than assignment `=` for the SET_FIELD results.
// 1. SET_FIELD(23, ...) modifies the lower 4 bits of 23 to 14, resulting in 30. var becomes 23 + 30 = 53.
// 2. SET_FIELD(53, ...) modifies bit 1 of 53 to 1, resulting in 55. var becomes 53 + 55 = 108.
    //
    //

    printf("Value of variable var = %d (third instance)\n", var);

    return 0;
}
