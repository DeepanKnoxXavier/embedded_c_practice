
#include <stdio.h>
#include <stdint.h>

#define STRINGIFY_BASE(x)       #x
#define STRINFIGY(x)            STRINGIFY_BASE(x)

#define feature_macro_0      1246
#define feature_macro_1      3291

#define feature_macro(x)     feature_macro_##x   

//
//  Explain what these macros do in detail.
//
//  Your explanation (mandatory):
//
//
//
//

#define CAT_2(a1,a2)            a1 ## a2
#define CAT_3(a1,a2,a3)         a1 ## a2 ## a3
#define CAT_4(a1,a2,a3,a4)      a1 ## a2 ## a3 ## a4
#define CAT(n,...)              CAT_##n(__VA_ARGS__)

#define FUNCTION(x)     x*x

static const int test_var_1 = 10;

int main(void)
{
    //
    // What is the output of this printf statement ?
    //
    // Your answer:
    //
    // Your explanation (mandatory):
    //
    //
    //
    //
 
    printf( "%d\n", CAT(3, test, _var_, 1) );

    //
    //  What is the output of this program?
    //
    //  Your answer:
    //
    //  Your explanation:
    //
    //
    //
    //

    printf("Output of macro: %d\n", FUNCTION(1+2));

    return 0;
}