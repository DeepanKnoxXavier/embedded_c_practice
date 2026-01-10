#include <stdio.h>
#include <stdint.h>


int main(void)
{
    uint32_t var = 10;

    var |= 1U;

    printf("Value of var (first instance): %d\n", var);

   // YOUR ANSWER: 22
// YOUR EXPLANATION (mandatory):
// var is 11 (binary 1011).
// The operator <<= 1 shifts bits left by 1 position (multiplying by 2).
// 1011 << 1 = 10110 (Decimal 22).

    var <<= 1;

    printf("Value of var (second instance): %d\n", var);

     // YOUR ANSWER: 22
// YOUR EXPLANATION (mandatory):
// var is 11 (binary 1011).
// The operator <<= 1 shifts bits left by 1 position (multiplying by 2).
// 1011 << 1 = 10110 (Decimal 22).
    var = var | ( 5 << 3 );

    printf("Value of var (third instance): %d\n", var);

    // YOUR ANSWER: 62
// YOUR EXPLANATION (mandatory):
// var is 22 (binary 010110).
// (5 << 3) shifts binary 101 (5) left by 3 to get 101000 (Decimal 40).
// 22 | 40 -> 010110 | 101000 = 111110 (Decimal 62).
    var ^= 3U;

    printf("Value of var (fourth instance): %d\n", var);

    // YOUR ANSWER: 61
// YOUR EXPLANATION (mandatory):
// var is 62 (binary 111110).
// The operator ^= 3U performs an XOR with 3 (binary 000011).
// 111110 ^ 000011 = 111101 (Decimal 61).

   
    var &= 15U;

    printf("Value of var (fifth instance): %d\n", var);


     // YOUR ANSWER: 13
// YOUR EXPLANATION (mandatory):
// var is 61 (binary 0011 1101).
// The operator &= 15U masks the lower 4 bits (15 is 0000 1111).
// 0011 1101 & 0000 1111 = 0000 1101 (Decimal 13).
    var &= ~3U;

    printf("Value of var (sixth instance): %d\n", var);
// YOUR ANSWER: 12
// YOUR EXPLANATION (mandatory):
// var is 13 (binary 1101).
// ~3U inverts 3 (0011) to get ...1100. This mask clears bits 0 and 1.
// 1101 & 1100 = 1100 (Decimal 12).
    //

    var ^= 21U;

    printf("Value of var (seventh instance): %d\n", var);
// YOUR ANSWER: 25
// YOUR EXPLANATION (mandatory):
// var is 12 (binary 01100).
// 21 is binary 10101.
// 01100 ^ 10101 = 11001 (Decimal 25).
    

    var = ( var << 1 ) | 0x3DE0C0010;

    printf("Value of var (eight instance): %d\n", var);

    // YOUR ANSWER: -569638862
// YOUR EXPLANATION (mandatory):
// var is 25. (var << 1) is 50 (0x32).
// The constant 0x3DE0C0010 is 9 hex digits long (exceeds 32 bits). 
// When assigned to uint32_t, the upper bits are truncated, leaving 0xDE0C0010.
// 0xDE0C0010 | 0x32 = 0xDE0C0032.
// Because printf uses %d (signed integer format), this large hex value (MSB is 1) is interpreted as a negative number (-569,638,862).

    var >>= 2U;

    printf("Value of var (ninth instance): %d\n", var);
// YOUR ANSWER: 931332108
// YOUR EXPLANATION (mandatory):
// var (0xDE0C0032) is unsigned, so >>= 2 is a logical shift (fills with zeros).
// 0xDE0C0032 >> 2 = 0x3783000C.
// 0x3783000C in decimal is 931,332,108.
    

    var += ( var ^ 0x055AA0AF );

    printf("Value of var (tenth instance): %d\n", var);

// YOUR ANSWER: 1784455343
// YOUR EXPLANATION (mandatory):
// var is 0x3783000C.
// First, calculate XOR: 0x3783000C ^ 0x055AA0AF = 0x32D9A0A3.
// Then add to var: 0x3783000C + 0x32D9A0A3 = 0x6A5CA0AF.
// 0x6A5CA0AF in decimal is 1,784,455,343.
    return 0;
}
