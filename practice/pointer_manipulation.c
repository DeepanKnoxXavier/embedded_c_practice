#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define TEST_STRING         "This is the test string"

char output_string[12] = {0};

int main(void)
{
    //  What is the output of the following program ?
    //  YOUR EXPLANATION:
    //  Output: "Ti stets ti"
    //
    //  Detailed Logic:
    //  1. The code extracts characters at even indices (0, 2, 4...) due to `p1 += 2`.
    //     Input indices: 0(T), 2(i), 4( ), 6(s), 8(t), 10(e), 12(t), 14(s), 16( ), 18(t), 20(i), 22(g).
    //
    //  2. The Loop Condition `while(p1[1] != '\0')` is a "look-ahead" check.
    //     It checks if the *next* character (odd index) is null before processing the *current* character.
    //
    //  3. The "Off-By-One" Termination:
    //     When p1 points to the last character 'g' (index 22), p1[1] (index 23) is '\0'.
    //     The loop condition fails immediately, so the body is NOT executed for 'g'.
    //     Therefore, 'g' is excluded from the output.
    //
    //  4. Safety: The output buffer is initialized to {0}. We write 11 characters (indices 0-10).
    //     Index 11 remains '\0', ensuring a valid string print.

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
