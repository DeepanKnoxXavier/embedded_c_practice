
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct test_struct{
    uint32_t var1 : 10;
    uint32_t var2 : 10;
    uint32_t var3 : 12;
};

struct string_as_a_struct{
    uint32_t entry1;
    uint32_t entry2;
    uint32_t entry3;
};

uint8_t test_buffer_u8[4] = {0};
uint16_t test_buffer_u16[4] = {0};

int main(void)
{
    struct test_struct s;

    *((uint32_t*)&s) = 1029839284;

    //  What is the value of s.var, s.var2 and s.var3 ?
    //  YOUR ANSWER:
    //  s.var1 =
    //  s.var2 =
    //  s.var3 =
    // Explain how you found these values (mandatory):
    //
    //
    //
    // 

    printf("Value of s.var1 = %d\n", s.var1);
    printf("Value of s.var2 = %d\n", s.var2);
    printf("Value of s.var3 = %d\n", s.var3);

    //  What does this operation do ?
    // YOUR ANSWER:
    //
    //
    //
    //

    *((uint32_t*)test_buffer_u8) = 0x9E569011;

    // What are the elements present in test buffer U8 ?
    // YOUR ANSWER:
    // test_buffer_u8[0] = 
    // test_buffer_u8[1] = 
    // test_buffer_u8[2] = 
    // test_buffer_u8[3] =
    // YOUR EXPLANATION (mandatory):
    //
    //
    //
    //

    printf("Value of test_buffer_u8[0]: %x\n", test_buffer_u8[0]);
    printf("Value of test_buffer_u8[1]: %x\n", test_buffer_u8[1]);
    printf("Value of test_buffer_u8[2]: %x\n", test_buffer_u8[2]);
    printf("Value of test_buffer_u8[3]: %x\n", test_buffer_u8[3]);

    //  What are the value of elements in test_buffer_u16.
    //  test_buffer_u16[0]  =
    //  test_buffer_u16[1]  =
    //  test_buffer_u16[2]  =
    //  test_buffer_u16[3]  =
    // YOUR EXPLANATION (mandatory):
    //
    //
    //
    //

    uint16_t* ptr_u16;

    ptr_u16 = test_buffer_u16;
    
    *ptr_u16++ = 2940;
    *++ptr_u16 = 4821;
    ptr_u16[1] = 2914;

    printf("Value of test_buffer_u16[0]: %d\n", test_buffer_u16[0]);
    printf("Value of test_buffer_u16[1]: %d\n", test_buffer_u16[1]);
    printf("Value of test_buffer_u16[2]: %d\n", test_buffer_u16[2]);
    printf("Value of test_buffer_u16[3]: %d\n", test_buffer_u16[3]);

    //  Calculate the output of the printf statement.
    //  Explain in detail what is going on step by step.
    //
    //  YOUR EXPLANATION:
    //
    //
    //
    //
    //
    //
    //

    char test_string[12] = {0};

    sprintf(test_string, "TEST STRING0");

    struct string_as_a_struct* string_struct;
 
    string_struct = (struct string_as_a_struct*)test_string;

    string_struct->entry1 += ( 1 << 0 );
    string_struct->entry1 -= ( 3 << 16 );
    string_struct->entry2 += ( 1 << 0 );
    string_struct->entry2 += ( 1 << 16 );
    string_struct->entry3 += ( 4 << 8 );
    string_struct->entry3 += ( 5 << 24 );

    printf("Manipulated string: %s", (char*)string_struct);

    return 0;
}