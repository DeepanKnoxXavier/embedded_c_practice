
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_STRING_SIZE        256

// What does this line do ?
// YOUR ANSWER:
//
//
//
// ATTACH REFERENCE HERE:
//
//
//

char test_string[TEST_STRING_SIZE] = {0};

int main(void)
{
    strcpy(test_string, "TEST STRING 1");

    //
    // What is the output of the 1st iteration ?
    //
    // YOUR ANSWER:
    //
    //
    // YOUR EXPLANATION:
    //
    //

    printf("Output of test_string (1st iteration): %s\n", test_string);

    (*test_string)++;
    (*(test_string + 8)) += 2;
    (*(test_string + 10)) += 10;

    //
    // What is the output of the 2nd iteration ?
    //
    // YOUR ANSWER:
    //
    //
    // YOUR EXPLANATION:
    //
    //

    printf("Output of test_string (2nd iteration): %s\n", test_string);

    strcat(test_string, "TEST STRING 2");

    //
    // What is the output of the 3rd iteration ?
    //
    // YOUR ANSWER:
    //
    //
    // YOUR EXPLANATION:
    //
    //

    printf("Output of test_string (3rd iteration): %s\n", test_string);

    //
    // What is the output of the 4th iteration ?
    //
    // YOUR ANSWER:
    //
    //
    // YOUR EXPLANATION:
    //
    //

    strncpy( test_string, "WHAT DIFFERENCE 3", 6);

    printf("Output of test_string (4th iteration): %s\n", test_string);

    //
    // What is the output of the 5th iteration ?
    //
    // YOUR ANSWER:
    //
    //
    // YOUR EXPLANATION:
    //
    //

    char* ptr = NULL;

    ptr = strchr( test_string, 'D' );

    *ptr += 3;

    printf("Output of test_String (5th iteration): %s", test_string);

    return 0;
}