#include <stdio.h>
#include <string.h>

//  What is the output of the program? If code execution fails
//  explain why it is failing.
//
//  YOUR ANSWER:
//  This code won't output anything because it's going to crash immediately. 
//  You'll get a "Segmentation Fault" (or Bus Error) the moment it runs.
//
//  YOUR EXPLANATION:
//  The issue is how `p` is defined. When you do `char* p = "TEST1";`, you are pointing 
//  to a "String Literal." These are stored in a special "Read-Only" part of memory 
//  (like the .rodata segment) because they are hardcoded into the executable.
//
//  When line 25 tries to change the 'T' to a 'U' (`p[0]++`), the computer says 
//  "Hey, you aren't allowed to write here!" and kills the program to prevent data corruption. 
//
//  (If you actually wanted to change it, you should have used `char p[]` to make a 
//  modifiable copy on the stack!)

char* p = "TEST1";

int main(void)
{
    p[0]++;    
    printf("Altered string: %s", p);

    return 0;
}
