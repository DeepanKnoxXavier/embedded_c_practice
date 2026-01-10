
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_STRING_SIZE        256

// What does this line do ?
// YOUR ANSWER:
//
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
    //
    //
    // YOUR EXPLANATION:
    //
    //

    printf("Output of test_string (1st iteration): %s\n", test_string);

    (*test_string)++;
    (*(test_string + 8)) += 2;
    (*(test_string + 10)) += 10;

    //
    // What is the output of the 2nd iteration ?
    //
    // YOUR ANSWER:
    //
    //
    // YOUR EXPLANATION:
    //
    //

    printf("Output of test_string (2nd iteration): %s\n", test_string);

    strcat(test_string, "TEST STRING 2");

    //
    // What is the output of the 3rd iteration ?
    //
    // YOUR ANSWER:
    //
    //
    // YOUR EXPLANATION:
    //
    //

    printf("Output of test_string (3rd iteration): %s\n", test_string);

    //
    // What is the output of the 4th iteration ?
    //
    // YOUR ANSWER:
    //
    //
    // YOUR EXPLANATION:
    //
    //

    strncpy( test_string, "WHAT DIFFERENCE 3", 6);

    printf("Output of test_string (4th iteration): %s\n", test_string);

    //
    // What is the output of the 5th iteration ?
    //
    // YOUR ANSWER:
    //
    //
    // YOUR EXPLANATION:
    //
    //

    char* ptr = NULL;

    ptr = strchr( test_string, 'D' );

    *ptr += 3;

    printf("Output of test_String (5th iteration): %s\n", test_string);

    //
    // What is the output of the string comparison operations?
    //
    // YOUR ANSWER:
    //
    //
    // YOUR EXPLANATION:
    //
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
    //
    //
    // YOUR EXPLANATION:
    //
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
    // length of string 1:
    // length of string 2:
    //
    // YOUR EXPLANATION:
    //
    //
    //

    strcpy( test_string_1, "TEST STRING 1" );
    strcpy( test_string_2, "TEST \0STRING 2" );

    printf("Value of test string 1: %d\n", strlen(test_string_1));
    printf("Value of test string 2: %d\n", strlen(test_string_2));

    //
    // What the output of the contatenated string?
    //
    // YOUR ANSWER:
    //
    // YOUR EXPLANATION:
    //
    //
    //
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
    //
    //
    // YOUR EXPLANATION:
    //
    //
    //
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
    //
    // YOUR EXPLANATION:
    //
    //
    //
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
    //
    //
    // YOUR EXPLANATION:
    //
    //
    //
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
    //
    //
    // YOUR EXPLANATION:
    //
    //
    //
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
    //
    //
    //
    // YOUR EXPLANATION:
    //
    //
    //
    //
    //
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