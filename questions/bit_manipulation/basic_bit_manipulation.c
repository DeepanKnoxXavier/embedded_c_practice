
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
    // YOUR ANSWER:
    // YOUR REASON (mandatory):
    //
    //
    //

    printf("Value of variable var = %d (first instance)\n", var );

    var += BIT_GET_FIELD( var, 2, 2 );
    var += BIT_GET_FIELD( var, 2, 0 );
    var = BIT_SHIFT( var, -1 );

    //  What will be the output of the second instance of var ?
    // YOUR ANSWER:
    // YOUR REASON (mandatory):
    //
    //
    //

    printf("Value of variable var = %d (second instance)\n", var );

    var -= BIT_SHIFT( 1, 2 );
    var += BIT_SET_FIELD( var, 14, 4, 0 );
    var += BIT_SET_FIELD( var, 1, 1, 1 );

    //  What will be the output of the third instance of var ?
    // YOUR ANSWER:
    // YOUR REASON (mandatory):
    //
    //
    //

    printf("Value of variable var = %d (third instance)\n", var);

    return 0;
}