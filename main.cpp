#include <stdio.h>
#include <malloc.h>
#include <assert.h>

const int GOVNO = 0;

#include "stack.h"
//2 modes: debug and release
int main()
{
    Stack gooooal = {};
    Stack * ptr_stk = &gooooal;
fprintf ( stderr, "***1\n");
    StackCtor ( ptr_stk, 3 );
printf("\nEqualazer = %d\n", ptr_stk->equalazer);
fprintf ( stderr, "***2\n");

    ASSERT ( ptr_stk );

fprintf ( stderr, "***3\n" );
    StackBurger ( ptr_stk );
    StackPush ( ptr_stk, 10 );
fprintf ( stderr, "***4\n" );
    StackBurger ( ptr_stk );
    StackPush ( ptr_stk, 20 );
fprintf ( stderr, "***5\n" );
    StackBurger ( ptr_stk );
    StackPush ( ptr_stk, 30 );
fprintf ( stderr, "***6\n" );
    StackBurger ( ptr_stk );
    StackPush ( ptr_stk, 1000 );
fprintf ( stderr, "***61\n" );
    StackBurger ( ptr_stk );

    StackPush ( ptr_stk, 5 );
fprintf ( stderr, "***62\n" );
    ASSERT ( ptr_stk );

    StackBurger ( ptr_stk );
    printf ( "\nReturn value: %d\n\n", StackPop ( ptr_stk ));
    StackBurger ( ptr_stk );

    printf ( "\nReturn value: %d\n\n", StackPop ( ptr_stk ));
    StackBurger ( ptr_stk );

fprintf ( stderr, "***8\n");

    ASSERT ( ptr_stk );

    StackBurger ( ptr_stk );

fprintf ( stderr, "***9\n");
    StackDtor ( ptr_stk );
}
