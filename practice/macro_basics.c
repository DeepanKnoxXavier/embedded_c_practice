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
    //  Test feature is enabled !
    //
    // YOUR EXPLANATION:
    //  1. The macro `TEST_FEATURE_ENABLE` is defined at the top of the file.
    //  2. The preprocessor encounters `#ifndef TEST_FEATURE_ENABLE` (If Not Defined).
    //     Since it IS defined, this block is skipped entirely.
    //  3. The preprocessor encounters `#ifdef TEST_FEATURE_ENABLE`.
    //     Since it IS defined, this block is compiled, and the printf executes.
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
// arg1 = 38
// arg2 = 371
//
// YOUR EXPLANATION:
//  1. Because the first `#ifndef` block was skipped, `OPERATION_ARGUMENTS_1` was NEVER defined.
//     Therefore, the code setting arg1=12 is ignored.
//  2. Because the second `#ifdef` block was entered, `OPERATION_ARGUMENTS_2` WAS defined.
//     Therefore, the preprocessor activates the block below where arg1=38 and arg2=371.
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
    //  result = 409
    //
    //  YOUR EXPLANATION:
    //  The program calculates the sum of the active arguments:
    //  38 + 371 = 409.
    //
    //

    printf("Value of result = %d\n", arg1 + arg2);

    return 0;
}
