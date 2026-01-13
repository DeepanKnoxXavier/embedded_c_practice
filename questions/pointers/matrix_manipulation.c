
#include <stdio.h>
#include <stdio.h>

//
// Explain what this function does.
//
// YOUR EXPLANATION:
//
//
//

void print_matrix(int* a, int n_rows, int n_columns)
{
    printf("Matrix:\n\n");

    int idx;

    for( idx = 0 ; idx < n_rows*n_columns ; idx++ )
    {
        // What are these calculations doing over here?

        printf("%d\t", *(a + idx) );

        if( ( ( idx + 1 )%n_columns ) == 0 )
            printf("\n");
    }

    printf("\n\n");
}


typedef void (*mm)(int* , int, int);

//
// Explain what is going on in this function.
//
// YOUR ANSWER:
//
//
//

void matrix_manipulate_1(int* a, int n_rows, int n_columns)
{
    int idx = 0;

    for( idx = 0 ; idx < n_columns ; idx++ )
    {
        a[idx] = idx;
        a[idx+n_rows] = idx + ( 2 << ( idx % n_rows ) ); 
    }
}

//
// Explain what is going on in this function.
//
// YOUR ANSWER:
//
//
//

void matrix_manipulate_2(int* a, int n_rows, int n_columns)
{
    int idx = 0;

    for( idx = 0 ; idx < n_columns ; idx++ )
    {
        a[idx] = idx % n_columns;
        a[idx+n_rows] = 7 + idx + ( 2 << ( idx % n_rows ) );
        a[idx+n_rows] = a[idx+n_columns]; 
    }
}

//
//  What is the final value of the matrix A ?
//
//  YOUR ANSWER:
//
//
//  YOUR EXPLANATION (mandatory):
//
//
//

int main(void)
{
    static int a[2][3] = {0};

    mm funcs[] = { [0] = matrix_manipulate_1, matrix_manipulate_2 };

    funcs[0]( (int*)&a[0], 2, 3 );
    funcs[1]( (int*)&a[0], 2, 3 );

    print_matrix( (int*)a, 2, 3 );

    return 0;
}