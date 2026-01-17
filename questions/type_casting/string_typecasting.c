
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define ATOF_TEST_STRING    "2.0"
#define ATOL_TEST_STRING    "1022.43"
#define ATOI_TEST_STRING    "129294"

int main(void)
{
    char* ptr;

    float float_value;
    double double_value;
    int int_value;

    float_value = (float)atof(ATOF_TEST_STRING);
    double_value = strtod(ATOL_TEST_STRING, &ptr);
    int_value = atoi(ATOI_TEST_STRING);

    //
    // What is the output value for float_value, double_value
    // & int_value ?
    //
    // float_value = 
    // double_value =
    // int_value = 
    //
    // Your explanation (mandatory):
    //
    // Explain all function usages.
    //
    //
    //
    //

    printf("Float value: %f\n", float_value);
    printf("Double value: %f\n", double_value);
    printf("Integer value: %d\n", int_value);

    return 0;
}