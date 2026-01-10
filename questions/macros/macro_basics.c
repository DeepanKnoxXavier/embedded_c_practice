
#include <stdio.h>
#include <stdint.h>

#define TEST_FEATURE_ENABLE

static int arg1;
static int arg2;
static int result;

int main(void)
{
    //
    // What the output of the print statement?
    //
    // YOUR ANSWER:
    //
    //
    // YOUR EXPLANATION:
    //
    //
    //
    //
    //

#ifndef TEST_FEATURE_ENABLE
    printf("Test feature is disabled.\n");

#define OPERATION_ARGUMENTS_1

#endif /* TEST_FEATURE_ENABLE */

#ifdef TEST_FEATURE_ENABLE
    printf("Test feature is enabled !\n");

#define OPERATION_ARGUMENTS_2

#endif

//
// What will be the value of arg1 and arg2?
//
// YOUR ANSWER: 
//
// arg1 = 
// arg2 = 
//
// YOUR EXPLANATION:
//
//
//


#ifdef OPERATION_ARGUMENTS_1

    arg1 = 12;
    arg2 = 53;

#define OPERATION_RESULT_1

#endif /* OPERATION_ARGUMENTS_1 */

#ifdef OPERATION_ARGUMENTS_2

    arg1 = 38;
    arg2 = 371;

#define OPERATION_RESULT_2

#endif /* OPERATION_ARGUMENTS_2 */

    //
    //  What is the value of the result ?
    //
    //  YOUR ANSWER:
    //
    //  result = 
    //
    //  YOUR EXPLANATION:
    //
    //
    //
    //

    printf("Value of result = %d\n", arg1 + arg2);

    return 0;
}