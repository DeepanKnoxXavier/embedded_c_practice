
#include <stdio.h>
#include <stdint.h>

//
// Explain the working of each macro.
//
// STRINGIFY_BASE (mandatory):
//
//
//
// STRINGIFY (mandatory):
//
//
//
// APPEND (mandatory):
//
//
//
// APPEND_STRING (mandatory):
//
//
//
// CONDITIONAL_CODE_TRUE (mandatory):
//
//
//
// CONDITIONAL_CODE_FALSE (mandatory):
//
//
//

/* String operation macros. */

#define STRINGIFY_BASE(x)       (#x)
#define STRINFIGY(x)            STRINGIFY_BASE(x)
#define APPEND(s1,s2)           s1##s2
#define APPEND_STRING(s1,s2)    STRINFIGY(APPEND(s1,s2))

//
// Explain how these conditional macros work?
// Explain step by step how the macros are decoded.
// Explain by substitution each step in detail.
//
//
//
//

#define IF_0(t, f)  f
#define IF_1(t, f)  t
#define IF(x)       APPEND(IF_, x)

#define CONDITIONAL_CODE_TRUE(x, __code1, __code2)     \
    IF(x)(DEBRACKET(__code1), DEBRACKET(__code2))

#define CONDITIONAL_CODE_FALSE(x, __code1, __code2)     \
    IF(x)(DEBRACKET(__code2), DEBRACKET(__code1))

#define DEBRACKET(...)      __VA_ARGS__

#define STRUCTURE_BASE_ARGUMENTS                \
    int result;                                 \
    int arg1;                              \
    int arg2;

// What does this macro expand to.

struct arg_struct{
    STRUCTURE_BASE_ARGUMENTS
    int arg3;
    int arg4;
};

//
// With an example, explain how this macro will expand?
//
// YOUR EXPLANATION (mandatory):
//
//
//

#define DEFINE_ARG_STRUCT(var,val1, val2, val3, val4)       \
struct arg_struct var = {   .arg1 = val1,                   \
                            .arg2 = val2,                   \
                            .arg3 = val3,                   \
                            .arg4 = val4,                   \
                            .result = 0,                    \
                        };

void add_struct_args_impl(struct arg_struct* s1, struct arg_struct* s2, struct arg_struct* s3)
{
    s3->arg1 = s1->arg1 + s2->arg1;
    s3->arg2 = s1->arg2 + s2->arg2;
    s3->arg3 = s1->arg3 + s2->arg3;
    s3->arg4 = s1->arg4 + s2->arg4;
    s3->result = s1->result + s2->result;
}

//
// Explain how the below macro is used to implement thie function
// add_struct_args_impl and how it simplifies the code ?
//
// YOUR EXPLANATION (mandatory):
//
//
//
//

#define ADD_STRUCT_ARGS(s1,s2,s3)   \
    add_struct_args_impl( &s1, &s2, &s3 )

#define PRINT_ARGS_STRUCT(s)                    \
    printf("Name of args struct: %s\n", #s);    \
    printf("arg1 value: %d\n", s.arg1);         \
    printf("arg2 value: %d\n", s.arg2);         \
    printf("arg3 value: %d\n", s.arg3);         \
    printf("arg4 value: %d\n", s.arg4);         \
    printf("result value: %d\n", s.result);

//
// What will this entire main function written using macros expand to ?
// Write down the entire program after decoding the macros manually.
// 
//
//
//
//
//
//
//
//

int main(void)
{
    printf("%s",  APPEND_STRING(s1,s2));

    CONDITIONAL_CODE_TRUE( 0, printf("TEST 1"); , printf("TEST 2"); );
    CONDITIONAL_CODE_FALSE( 1, printf("TEST CONDITION FAILED");, printf("TEST CONDITION PASSED"); )

    DEFINE_ARG_STRUCT( s1, 0, 1, 2, 3);
    DEFINE_ARG_STRUCT( s2, 12, 29, 49, 34);
    DEFINE_ARG_STRUCT( s3, 0, 0, 0, 0 );

    ADD_STRUCT_ARGS( s1, s2, s3 );

    PRINT_ARGS_STRUCT(s3);

    return 0;
}