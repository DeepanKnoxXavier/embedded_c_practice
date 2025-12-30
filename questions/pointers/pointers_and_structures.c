
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


struct test_structure
{
    uint8_t first_variable;
    uint8_t second_variable;
    uint8_t third_variable;
};


int main(void)
{
    struct test_structure s;
    struct test_structure* const ptr = &s;

    //  Question: Can the value of ptr be modified ?
    // Try changing the value of ptr and check if the compiler throws an error.
    // If the compiler throws and error reason it out.
    // YOUR ANSWER (mandatory):
    //
    //
    //
    //

    s.first_variable = 10;
    s.second_variable = 20;
    s.third_variable = 30;

    // What will be the value of the following ?
    // ptr->first_variable      YOUR ANSWER:
    // ptr->second_variable     YOUR ANSWER:
    // ptr->third_variable      YOUR ANSWER:
    //  NOTE: Do not compile and test before you enter the answer.
    //  YOUR REASON (mandatory):
    //
    //
    //
    //

    printf("First variable value: %d\n", ptr->first_variable);
    printf("Second variable value: %d\n", ptr->second_variable);
    printf("Third variable value: %d\n", ptr->third_variable);

    return 0;
}