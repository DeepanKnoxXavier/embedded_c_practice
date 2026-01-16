
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct complex
{
    double real;
    double imaginary;
};

//
//  Explain what this function does.
//
//  Your explanation (mandatory):
//
//
//
//

void complex_print(struct complex* complex)
{
    printf("\nComplex number: %f + %fi\n", complex->real, complex->imaginary );
}

//
//  Explain what this function does.
//
//  Your explanation (mandatory):
//
//
//
//

void complex_add(struct complex* a, struct complex* b, struct complex* result)
{
    result->real = a->real + b->real;
    result->imaginary = a->imaginary + b->imaginary;
}

//
//  Explain what this function does.
//
//  Your explanation (mandatory):
//
//
//
//

// Complete this function by yourself !

void complex_subtract(struct complex* a, struct complex* b, struct complex* result)
{

}

//
//  Explain what this function does.
//
//  Your explanation (mandatory):
//
//
//
//

// Complete this function by yourself.

void complex_conjugate(struct complex* a, struct complex* result)
{

}

//
//  Explain what this function does.
//
//  Your explanation (mandatory):
//
//
//
//

void complex_multiply(struct complex* a, struct complex* b, struct complex* result)
{
    result->real       = (a->real*b->real) - (a->imaginary*b->imaginary);
    result->imaginary  = (a->real*b->imaginary) + (a->imaginary*b->real); 
}

//
//  Explain what this function does.
//
//  Your explanation (mandatory):
//
//
//
//

//! Complete thie function by yourself.

double complex_absolute(struct complex* complex)
{
    return(0);
}

//
//  Explain what this function does.
//
//  Your explanation (mandatory):
//
//
//
//

double complex_divide(struct complex* a, struct complex* b, struct complex* result)
{
    double real;
    double imaginary;
    double denominator;

    real = a->real * b->real + a->imaginary * b->imaginary;
    imaginary = a->imaginary * b->real - a->real * b->imaginary;
    denominator = (b->real *b->real) + (b->imaginary * b->imaginary);

    real = real / denominator;
    imaginary = imaginary / denominator;

    result->real = real;
    result->imaginary = imaginary;
}

int main(void)
{
    static struct complex result = {0};
    static struct complex op1 = {0};
    static struct complex op2 = {0};

    op1.real = 1;
    op1.imaginary = 2;
    op2.real = 5;
    op2.imaginary = 9;

    complex_add(&op1, &op2, &result);

    // What is the output of this program.
    //
    // Your answer:
    //
    //
    // Your explanation:
    //
    //
    //
    //

    complex_print(&result);

    op1.real = 7.5;
    op1.imaginary = 2.5;
    op2.real = 1.0;
    op2.imaginary = -1.5;

    complex_multiply(&op1, &op2, &result);

    // What is the output of this program.
    //
    // Your answer:
    //
    //
    // Your explanation:
    //
    //
    //
    //

    complex_print(&result);

    op1.real = 1;
    op1.imaginary = 5;
    op2.real = 2.5;
    op2.imaginary = 3.5;

    complex_divide( &op1, &op2, &result );

    // What is the output of this program.
    //
    // Your answer:
    //
    //
    // Your explanation:
    //
    //
    //
    //

    complex_print( &result );

    //
    //  Write example codes using complex_subtract, complex_conjucate, complex_absolute
    //  functions and provide proper comments for each function usage.
    //  Before doing so, complete the function bodiesfor the above mentioned functions.
    //

    return 0;
}