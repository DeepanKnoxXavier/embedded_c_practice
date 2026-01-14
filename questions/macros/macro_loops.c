
#include <stdio.h>
#include <stdint.h>


//
//  Explain how this macro is expanded.
//
// YOUR EXPLANATION (mandatory):
//
//
//
//


#define FOR_EACH_IN_ARRAY(a, element_type, code)                                                                    \
    {                                                                                                               \
        element_type* element;                                                                                      \
        int index;                                                                                                  \
                                                                                                                    \
        for( index = 0, element = &a[0]; index < sizeof(a)/sizeof(a[0]) ; index++, element++ )                      \
        {                                                                                                           \
            code                                                                                                    \
        }                                                                                                           \
    }



int main()
{
    int array[5] = {1,2,3,4,5};

    //
    // What is the output of this loop?
    //
    // YOUR EXPLANATION (mandatory)
    //
    //
    //

    FOR_EACH_IN_ARRAY(array, int, 
        {
            if( index > 0 )
            {
                *(element) = index+ 5;
            }

            printf("Value of index %d = %d\n", index, *element);
        } 
    );

    return 0;
}