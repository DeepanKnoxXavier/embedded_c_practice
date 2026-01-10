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
    // ==========================================
    // PROBLEM 1: Bitfields
    // ==========================================
    struct test_struct s;

    *((uint32_t*)&s) = 1029839284;

    //  What is the value of s.var, s.var2 and s.var3 ?
    //  YOUR ANSWER:
    //  s.var1 = 436
    //  s.var2 = 138
    //  s.var3 = 982
    //
    // Explain how you found these values (mandatory):
    //  1. Convert 1029839284 to Hex: 0x3D6229B4.
    //  2. Convert to Binary (32 bits): 0011 1101 0110 0010 0010 1001 1011 0100
    //  3. Assuming Little Endian (standard for x86/ARM), bitfields populate from LSB up.
    //     - var1 (Bits 0-9)  : ...01 1011 0100 -> 0x1B4 -> 436
    //     - var2 (Bits 10-19): ...00 1000 1010 -> 0x08A -> 138
    //     - var3 (Bits 20-31): 0011 1101 0110... -> 0x3D6 -> 982

    printf("Value of s.var1 = %d\n", s.var1);
    printf("Value of s.var2 = %d\n", s.var2);
    printf("Value of s.var3 = %d\n", s.var3);

    // ==========================================
    // PROBLEM 2: Pointer Casting & Endianness
    // ==========================================
    
    //  What does this operation do ?
    // YOUR ANSWER:
    //  It treats the 4-byte array `test_buffer_u8` as a single 32-bit integer and assigns
    //  the value 0x9E569011 to it. This writes bytes across the array based on Endianness.

    *((uint32_t*)test_buffer_u8) = 0x9E569011;

    // What are the elements present in test buffer U8 ?
    // YOUR ANSWER:
    // test_buffer_u8[0] = 0x11
    // test_buffer_u8[1] = 0x90
    // test_buffer_u8[2] = 0x56
    // test_buffer_u8[3] = 0x9E
    // YOUR EXPLANATION (mandatory):
    //  In a Little Endian system (LSB at lowest address):
    //  0x9E569011 breaks down as:
    //  - LSB (Least Significant Byte): 0x11 -> Goes to offset 0.
    //  - Next Byte: 0x90 -> Goes to offset 1.
    //  - Next Byte: 0x56 -> Goes to offset 2.
    //  - MSB (Most Significant Byte):  0x9E -> Goes to offset 3.

    printf("Value of test_buffer_u8[0]: %x\n", test_buffer_u8[0]);
    printf("Value of test_buffer_u8[1]: %x\n", test_buffer_u8[1]);
    printf("Value of test_buffer_u8[2]: %x\n", test_buffer_u8[2]);
    printf("Value of test_buffer_u8[3]: %x\n", test_buffer_u8[3]);

    // ==========================================
    // PROBLEM 3: Pointer Arithmetic
    // ==========================================

    //  What are the value of elements in test_buffer_u16.
    //  test_buffer_u16[0]  = 2940
    //  test_buffer_u16[1]  = 0
    //  test_buffer_u16[2]  = 4821
    //  test_buffer_u16[3]  = 2914
    //
    // YOUR EXPLANATION (mandatory):
    //  1. `ptr_u16 = test_buffer_u16` -> Ptr points to Index 0.
    //  2. `*ptr_u16++ = 2940` -> Assign 2940 to Index 0, THEN increment ptr to Index 1.
    //  3. `*++ptr_u16 = 4821` -> Pre-increment ptr to Index 2, THEN assign 4821.
    //     (CRITICAL: Index 1 was skipped and remains 0).
    //  4. `ptr_u16[1] = 2914` -> Ptr is at Index 2. `ptr[1]` means `*(ptr + 1)`,
    //     so it writes to Index 3.

    uint16_t* ptr_u16;

    ptr_u16 = test_buffer_u16;
    
    *ptr_u16++ = 2940;
    *++ptr_u16 = 4821;
    ptr_u16[1] = 2914;

    printf("Value of test_buffer_u16[0]: %d\n", test_buffer_u16[0]);
    printf("Value of test_buffer_u16[1]: %d\n", test_buffer_u16[1]);
    printf("Value of test_buffer_u16[2]: %d\n", test_buffer_u16[2]);
    printf("Value of test_buffer_u16[3]: %d\n", test_buffer_u16[3]);

    // ==========================================
    // PROBLEM 4: String Manipulation via Struct
    // ==========================================

    //  Calculate the output of the printf statement.
    //  Explain in detail what is going on step by step.
    //
    //  YOUR EXPLANATION:
    //  The string "TEST STRING0" is cast to a struct of 3 uint32 integers.
    //  Math is performed on these integers, which modifies the ASCII bytes in place.
    //
    //  Original: "TEST STRING0"
    //  Bytes: [T E S T] [  S T R] [I N G 0]
    //
    //  1. entry1 ("TEST"):
    //     - `+= (1 << 0)` : Adds 1 to Byte 0 ('T' -> 'U').
    //     - `-= (3 << 16)`: Subs 3 from Byte 2 ('S' -> 'P').
    //     Result: "UEPT"
    //
    //  2. entry2 (" STR"):
    //     - `+= (1 << 0)` : Adds 1 to Byte 0 (' ' -> '!').
    //     - `+= (1 << 16)`: Adds 1 to Byte 2 ('T' -> 'U').
    //     Result: "!SUR"
    //
    //  3. entry3 ("ING0"):
    //     - `+= (4 << 8)` : Adds 4 to Byte 1 ('N' -> 'R').
    //     - `+= (5 << 24)`: Adds 5 to Byte 3 ('0' -> '5').
    //     Result: "IRG5"
    //
    //  Final Output: UEPT!SURIRG5

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
