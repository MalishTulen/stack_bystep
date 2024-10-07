#include <stdio.h>
#include <malloc.h>
#include <assert.h>

const int GOVNO = 0;

#include "stack.h"
//2 modes: debug and release
int main()
{
    int hueta[10] = {};
    Stack gooooal = {};
    Stack * ptr_stk = &gooooal;
    StackCtor ( ptr_stk, 100 );

    for (int hui = 0; hui < 200; hui++)
    {
        StackPush( ptr_stk, hui );
fprintf(stderr, "rex %d \n", hui );
    }
    for (size_t pidor = 0; pidor < 1000; pidor++)
    {
fprintf(stderr, "dex %d \n", pidor );
        hueta[pidor] = pidor;
    }
    StackDtor ( ptr_stk );
}
