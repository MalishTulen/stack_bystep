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
//fprintf ( stderr, "ptr1\n");


    //printf("%d", sizeof(int));
    StackCtor ( ptr_stk, 3 );
//fprintf ( stderr, "ptr2\n");

    ASSERT ( ptr_stk );

//fprintf ( stderr, "ptr11\n" );
    StackBurger ( ptr_stk );
    StackPush ( ptr_stk, 10 );
//fprintf ( stderr, "ptr12\n" );
    StackBurger ( ptr_stk );
    StackPush ( ptr_stk, 20 );
//fprintf ( stderr, "ptr13\n" );
    StackBurger ( ptr_stk );
    StackPush ( ptr_stk, 30 );
//fprintf ( stderr, "ptr14\n" );
    StackBurger ( ptr_stk );
    StackPush ( ptr_stk, 1000 );

    StackBurger ( ptr_stk );

    StackPush ( ptr_stk, 5 );

    ASSERT ( ptr_stk );

    StackBurger ( ptr_stk );
    printf ( "\nReturn value: %d\n\n", StackPop ( ptr_stk ));
    StackBurger ( ptr_stk );

    printf ( "\nReturn value: %d\n\n", StackPop ( ptr_stk ));
    StackBurger ( ptr_stk );

//fprintf ( stderr, "ptr3\n");

    ASSERT ( ptr_stk );

    StackBurger ( ptr_stk );

//fprintf ( stderr, "ptr3\n");
    StackDtor ( ptr_stk );

    StackBurger ( ptr_stk );
}
