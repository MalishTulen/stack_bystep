#include <stdio.h>
#include <malloc.h>
#include <assert.h>

const int GOVNO = 0;

#include "stack.h"
//2 modes: debug and release
int main()
{
    Stack * ptr_stk = ( Stack * ) calloc ( 1, sizeof ( Stack ) );

    //printf("%d", sizeof(int));
    StackCtor( ptr_stk, 10 );
    StackPush ( ptr_stk, 10 );
    StackPush ( ptr_stk, 10 );
    StackPush ( ptr_stk, 10 );

    StackBurger ( ptr_stk );

}
