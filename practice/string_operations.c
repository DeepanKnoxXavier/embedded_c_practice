#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_STRING_SIZE        256

// What does this line do ?
// YOUR ANSWER:
//  It declares a character array of size 256 and initializes every byte to 0 (Null Character).
//
//
// ATTACH REFERENCE HERE:
//  
//
//

char test_string[TEST_STRING_SIZE] = {0};

char test_string_1[TEST_STRING_SIZE] = {0};
char test_string_2[TEST_STRING_SIZE] = {0};
char test_string_3[TEST_STRING_SIZE] = {0};
char test_string_4[TEST_STRING_SIZE] = {0};

int main(void)
{
    int ret;

    strcpy(test_string, "TEST STRING 1");

    //
    // What is the output of the 1st iteration ?
    //
    // YOUR ANSWER:
    //  Output of test_string (1st iteration): TEST STRING 1
    //
    // YOUR EXPLANATION:
    //  The string was just copied using strcpy. No modifications have been made yet.
    //

    printf("Output of test_string (1st iteration): %s\n", test_string);

    (*test_string)++;
    (*(test_string + 8)) += 2;
    (*(test_string + 10)) += 10;

    //
    // What is the output of the 2nd iteration ?
    //
    // YOUR ANSWER:
    //  Output of test_string (2nd iteration): UEST STRKNQ 1
    //
    // YOUR EXPLANATION:
    //  1. (*test_string)++ : Increments char at index 0 ('T' -> 'U').
    //  2. (*(test_string + 8)) += 2 : Index 8 is 'I'. 'I' + 2 = 'K'.
    //  3. (*(test_string + 10)) += 10 : Index 10 is 'G'. 'G' + 10 = 'Q'.
    //

    printf("Output of test_string (2nd iteration): %s\n", test_string);

    strcat(test_string, "TEST STRING 2");

    //
    // What is the output of the 3rd iteration ?
    //
    // YOUR ANSWER:
    //  Output of test_string (3rd iteration): UEST STRKNQ 1TEST STRING 2
    //
    // YOUR EXPLANATION:
    //  strcat appends the source string to the end of the destination string.
    //  It overwrites the null terminator of the first string and adds a new one at the end.
    //

    printf("Output of test_string (3rd iteration): %s\n", test_string);

    //
    // What is the output of the 4th iteration ?
    //
    // YOUR ANSWER:
    //  Output of test_string (4th iteration): WHAT DTRKNQ 1TEST STRING 2
    //
    // YOUR EXPLANATION:
    //  strncpy copies exactly 6 characters ("WHAT D") into the start of the array.
    //  Indices 0-5 are overwritten.
    //  Indices 6 onwards ('S'...) remain untouched because strncpy does NOT add a null terminator
    //  if the count (6) is reached before the source string ends.
    //  
    //

    strncpy( test_string, "WHAT DIFFERENCE 3", 6);

    printf("Output of test_string (4th iteration): %s\n", test_string);

    //
    // What is the output of the 5th iteration ?
    //
    // YOUR ANSWER:
    //  Output of test_String (5th iteration): WHAT GTRKNQ 1TEST STRING 2
    //
    // YOUR EXPLANATION:
    //  1. strchr finds the pointer to the first occurrence of 'D' (Index 5).
    //  2. *ptr += 3 increments that character: 'D' (68) + 3 = 'G' (71).
    //  3. The string changes from "WHAT D..." to "WHAT G...".
    //

    char* ptr = NULL;

    ptr = strchr( test_string, 'D' );

    *ptr += 3;

    printf("Output of test_String (5th iteration): %s\n", test_string);

    //
    // What is the output of the string comparison operations?
    //
    // YOUR ANSWER:
    //  1. test_string matches with comparison string.
    //  2. test_string is greater that comparison string.
    //  3. test_string is lesser than comparison string.
    //
    // YOUR EXPLANATION:
    //  Current test_string: "WHAT GTRKNQ 1TEST STRING 2"
    //  1. Exact match returns 0.
    //  2. Ends in "STRING 1". '2' (ASCII 50) > '1' (ASCII 49). Result > 0.
    //  3. Ends in "STRING 5". '2' (ASCII 50) < '5' (ASCII 53). Result < 0.
    //

    ret = strcmp(test_string, "WHAT GTRKNQ 1TEST STRING 2");

    if( ret == 0 )
    {
        printf("test_string matches with comparison string.\n");
    }
    else if( ret > 0 )
    {
        printf("test_string is greater that comparison string.\n");
    }
    else if( ret < 0 )
    {
        printf("test_string is lesser than comparison string.\n");
    }

    ret = strcmp(test_string, "WHAT GTRKNQ 1TEST STRING 1");

    if( ret == 0 )
    {
        printf("test_string matches with comparison string.\n");
    }
    else if( ret > 0 )
    {
        printf("test_string is greater that comparison string.\n");
    }
    else if( ret < 0 )
    {
        printf("test_string is lesser than comparison string.\n");
    }

    ret = strcmp(test_string, "WHAT GTRKNQ 1TEST STRING 5");

    if( ret == 0 )
    {
        printf("test_string matches with comparison string.\n");
    }
    else if( ret > 0 )
    {
        printf("test_string is greater that comparison string.\n");
    }
    else if( ret < 0 )
    {
        printf("test_string is lesser than comparison string.\n");
    }

    //
    // What is the output of this section?
    //
    // YOUR ANSWER:
    //  TEST STRING
    //  Number of characters before finding matching string pattern: 1
    //
    // YOUR EXPLANATION:
    //  strcspn counts characters *until* it finds any character from the set "Ea".
    //  Index 0 is 'T' (Not in set).
    //  Index 1 is 'E' (In set!).
    //  Stop counting. Result is 1.
    //

    memset( test_string, 0, sizeof(test_string)/sizeof(test_string[0]) );
    strcpy(test_string, "TEST STRING");

    printf("%s\n", test_string);

    ret = (int)strcspn(test_string, "Ea");

    printf("Number of characters before finding matching string pattern: %d\n", ret);

    //
    // What is the length of string 1 and string 2? 
    //
    // YOUR ANSWER:
    //
    // length of string 1: 13
    // length of string 2: 5
    //
    // YOUR EXPLANATION:
    //  1. String 1 is normal. Length is 13.
    //  2. String 2 has an embedded null: "TEST \0STRING 2".
    //     Standard string functions (strcpy, strlen) stop processing at the first '\0'.
    //     So it only sees "TEST ". Length is 5.
    //

    strcpy( test_string_1, "TEST STRING 1" );
    strcpy( test_string_2, "TEST \0STRING 2" );

    printf("Value of test string 1: %d\n", strlen(test_string_1));
    printf("Value of test string 2: %d\n", strlen(test_string_2));

    //
    // What the output of the contatenated string?
    //
    // YOUR ANSWER:
    //  test_string after contatenation: TEST STRINGAPPENWHA
    //
    // YOUR EXPLANATION:
    //  1. strncat appends MAX n characters.
    //  2. "APPENDED STRING" (5) -> Adds "APPEN".
    //  3. "WHAT IS..." (3) -> Adds "WHA".
    //  Total: "TEST STRING" + "APPEN" + "WHA".
    //

    memset( test_string, 0, sizeof(test_string)/sizeof(test_string[0]) );

    strcpy( test_string, "TEST STRING" );

    strncat( test_string, "APPENDED STRING", 5 );
    strncat( test_string, "WHAT IS APPENDED ?", 3);

    printf("test_string after contatenation: %s\n", test_string);

    //
    // What is the output of the string comparison operation ?
    //
    // YOUR ANSWER:
    //  Compared strings are equal.
    //
    // YOUR EXPLANATION:
    //  1. `test_string + 6` points to "TRINGAPPENWHA" (Skipping "TEST S").
    //  2. We compare 6 characters with "TRINGAPWQNLHPT".
    //  3. First 6 chars of both are "TRINGA".
    //  4. They match exactly.
    //

    ret = strncmp( test_string + 6, "TRINGAPWQNLHPT", 6 );

    if( ret == 0 )
    {
        printf("Compared strings are equal.\n");
    }
    else
    {
        printf("Compared strings are not equal.\n");
    }

    //
    // What is the value printed by the printf statement?
    //
    // YOUR ANSWER:
    //  Value: 5
    //
    // YOUR EXPLANATION:
    //  1. strpbrk finds the first char from "value" in the string -> Finds 'v' at index 1.
    //  2. strchr searches for ',' starting from that 'v'. Finds comma at index 9 (",command...").
    //  3. The pointer is incremented by 9.
    //     Offset logic: ',' is index 0 relative to itself.
    //     0(,) 1(c) 2(o) 3(m) 4(m) 5(a) 6(n) 7(d) 8(:) 9(5).
    //     The pointer now points to the character '5'.
    //  4. '5' - '0' = integer 5.
    //

    memset( test_string, 0, sizeof(test_string)/sizeof(test_string[0]) );

    strcpy( test_string, "{value:4,command:5}" );

    ptr = strpbrk( test_string, "value" );
    ptr = strchr( ptr, ',' ) + 9;

    printf("Value: %d\n", (int)(ptr[0] - '0') );

    //
    // What is the value of the test string after all string operations ?
    //
    // YOUR ANSWER:
    //  Value of test string: evil did i gwelb
    //
    // YOUR EXPLANATION:
    //  1. strrchr(..., 'd') finds the LAST 'd' (start of "dwell").
    //  2. *ptr += 3 turns 'd' into 'g' -> "evil did i gwell".
    //  3. strrchr(..., 'l') finds the LAST 'l' (end of "gwell").
    //  4. *ptr -= 10 turns 'l' (108) into 'b' (98).
    //

    memset( test_string, 0, sizeof(test_string)/sizeof(test_string[0]) );
    strcpy( test_string, "evil did i dwell" );

    ptr = strrchr( test_string, 'd' );
    *ptr += 3;
    ptr = strrchr( ptr, 'l' );
    *ptr -= 10;

    printf("Value of test string: %s\n", test_string);

    //
    // What is the maximum number of characters which is matching between the string?
    //
    // YOUR ANSWER:
    //  Maximum number of characters matched: 4
    //
    // YOUR EXPLANATION:
    //  strspn returns the length of the initial segment of s1 composed ENTIRELY of chars from s2.
    //  s1: A 0 2 9 F J J 3
    //  s2: A 0 2 9 3 2 4 9
    //  'A', '0', '2', '9' are present in s2.
    //  'F' is NOT present in s2.
    //  Sequence breaks at 'F'. Length is 4.
    //

    memset( test_string_1, 0, sizeof(test_string_1)/sizeof(test_string_1[0]) );
    memset( test_string_2, 0, sizeof(test_string_2)/sizeof(test_string_2[0]) );

    strcpy( test_string_1, "A029FJJ3" );
    strcpy( test_string_2, "A0293249" );

    ret = strspn( test_string_1, test_string_2 );

    printf("Maximum number of characters matched: %d\n", ret);

    //
    // What the value of sum of the return values ?
    // The return values are represented by the value ret.
    //
    // YOUR ANSWER:
    //  Value of sum of return values: 135
    //
    // YOUR EXPLANATION:
    //  NOTE: There is an off-by-one logical error in the parsing code (`ptr += 8`),
    //  which causes it to read the *second* digit of the number and the following separator.
    //
    //  Logic trace for "value1:12,":
    //  1. strstr finds "value1". ptr points to 'v'.
    //  2. ptr += 8 skips 8 chars: v(0)a(1)l(2)u(3)e(4)1(5):(6)1(7). It lands on '2'.
    //  3. Calculation: 10 * '2' + ',' (comma).
    //     10 * 50 + 44 - (zeros adjustments) -> 20 + (-4) = 16.
    //
    //  Calculations:
    //  - Value 1 (reads "2,"): 16
    //  - Value 2 (reads "2,"): 16
    //  - Value 3 (reads "3,"): 26
    //  - Value 4 (reads "0}"): 10*0 + ('}' - '0') = 77.
    //  Total = 16 + 16 + 26 + 77 = 135.
    //

    memset( test_string, 0, sizeof(test_string)/sizeof(test_string[0]) );

    strcpy( test_string, "{value1:12,value2:32,value3:83,value4:10}" );

    ret = 0;

    ptr = strstr( test_string, "value1" );
    ptr += 8;

    ret += 10 * (int)(ptr[0] - '0') + (int)(ptr[1] - '0');

    ptr = strstr( test_string, "value2" );
    ptr += 8;

    ret += 10 * (int)(ptr[0] - '0') + (int)(ptr[1] - '0');

    ptr = strstr( test_string, "value3" );
    ptr += 8;

    ret += 10 * (int)(ptr[0] - '0') + (int)(ptr[1] - '0');

    ptr = strstr( test_string, "value4" );
    ptr += 8;

    ret += 10 * (int)(ptr[0] - '0') + (int)(ptr[1] - '0');

    printf("Value of sum of return values: %d\n", ret);

    return 0;
}
