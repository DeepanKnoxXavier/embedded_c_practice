
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define TEST_STRING         "This is the test string"

char output_string[12] = {0};

int main(void)
{
    //  What is the output of the following program ?
    //  YOUR EXPLANATION:
    //
    //
    //
    //

    const char* p1 = TEST_STRING;
    char* p2 = output_string;

    while(p1[1] != '\0')
    {
        *p2 = *p1;
        p2++;
        p1 += 2;
    }

    printf("Manipulated string: %s\n", output_string);

    return 0;
}