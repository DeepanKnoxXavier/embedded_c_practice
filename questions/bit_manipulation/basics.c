
#include <stdio.h>
#include <stdint.h>


int main(void)
{
    uint32_t var = 10;

    // What will be the output ?
    // YOUR ANSWER:
    // YOUR EXPLANATION (mandatory):
    //
    //
    //

    var |= 1U;

    printf("Value of var (first instance): %d\n", var);

    // What will be the output ?
    // YOUR ANSWER:
    // YOUR EXPLANATION (mandatory):
    //
    //
    //

    var <<= 1;

    printf("Value of var (second instance): %d\n", var);

    // What will be the output ?
    // YOUR ANSWER:
    // YOUR EXPLANATION (mandatory):
    //
    //
    //

    var = var | ( 5 << 3 );

    printf("Value of var (third instance): %d\n", var);

    // What will be the output ?
    // YOUR ANSWER:
    // YOUR EXPLANATION (mandatory):
    //
    //
    //

    var ^= 3U;

    printf("Value of var (fourth instance): %d\n", var);

    // What will be the output ?
    // YOUR ANSWER:
    // YOUR EXPLANATION (mandatory):
    //
    //
    //

    var &= 15U;

    printf("Value of var (fifth instance): %d\n", var);


    // What will be the output ?
    // YOUR ANSWER:
    // YOUR EXPLANATION (mandatory):
    //
    //
    //

    var &= ~3U;

    printf("Value of var (sixth instance): %d\n", var);

    // What will be the output ?
    // YOUR ANSWER:
    // YOUR EXPLANATION (mandatory):
    //
    //
    //

    var ^= 21U;

    printf("Value of var (seventh instance): %d\n", var);

    // What will be the output ?
    // YOUR ANSWER:
    // YOUR EXPLANATION (mandatory):
    //
    //
    //

    var = ( var << 1 ) | 0x3DE0C0010;

    printf("Value of var (eight instance): %d\n", var);

    // What will be the output ?
    // YOUR ANSWER:
    // YOUR EXPLANATION (mandatory):
    //
    //
    //

    var >>= 2U;

    printf("Value of var (ninth instance): %d\n", var);

    // What will be the output ?
    // YOUR ANSWER:
    // YOUR EXPLANATION (mandatory):
    //
    //
    //

    var += ( var ^ 0x055AA0AF );

    printf("Value of var (tenth instance): %d\n", var);


    return 0;
}