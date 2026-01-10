
#include <stdint.h>
#include <stdio.h>

int add(int arg1, int arg2)
{
    return(arg1+arg2);
}

int sub(int arg1, int arg2)
{
    return(arg1-arg2);
}

int mul(int arg1, int arg2)
{
    return(arg1*arg2);
}

int div(int arg1, int arg2)
{
    return(arg1/arg2);
}

int mod(int arg1, int arg2)
{
    return(arg1%arg2);
}

typedef int (*operation_function)(int, int);

int main(void)
{
    int ret = 0;

    operation_function f1;
    operation_function f2;
    operation_function f3;
    operation_function f4;

    f1 = add;
    f2 = sub;
    f3 = mul;
    f4 = div;

    //
    // What is the value of ret?
    //
    // YOUR ANSWER:
    // ret = 
    //
    // YOUR EXPLANATION:
    //
    //
    //
    //

    ret = mod( f3( f1(10,5) + f2(100,5), f4(34,5) ), 100 );

    printf("Result: %d\n", ret);

    return 0;
}