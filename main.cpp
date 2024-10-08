#include <stdio.h>
#include <malloc.h>
#include <assert.h>

const int GOVNO = 0;

#include "stack.h"
//2 modes: debug and release
int main()
{
    int rand[10] = {};
 fprintf(stderr, "\ngfgfgfggf 1 \n" );

    Stack gooooal = {};
    Stack * ptr_stk = &gooooal;
    StackCtor ( ptr_stk, 5 );
 fprintf(stderr, "\ngfgfgfggf 2 \n" );

    for (int hui = 0; hui < 200; hui++)
    {
        StackPush( ptr_stk, hui );
fprintf(stderr, "rex %d \n", hui );
        StackDump ( ptr_stk );
    }
    for (size_t pidor = 0; pidor < 1000; pidor++)
    {
fprintf(stderr, "dex %d \n", pidor );

        rand[pidor] = pidor;
    }
    StackDtor ( ptr_stk );
}
