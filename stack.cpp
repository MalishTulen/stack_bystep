#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "stack.h"

int StackCtor ( Stack * ptr_stk, int capacity )
{
    //assert
    ptr_stk->size = 0;
    ptr_stk->capacity = capacity;
    if ( ( capacity * sizeof ( int ) ) % 8 == 0)
        ptr_stk->equalazer = 0;
    else
        ptr_stk->equalazer = sizeof ( canary_t ) - capacity * sizeof ( int ) % 8 + 1;

    size_t size = ( 2 + capacity + ptr_stk->equalazer );
    Stack_Elem_Data_t * tmp_ptr = ( Stack_Elem_Data_t * ) calloc ( size, sizeof ( Stack_Elem_Data_t ) );

    ptr_stk->data_ptr = tmp_ptr + 1;

    *( tmp_ptr ) = 12345678;

    *(ptr_stk->data_ptr + capacity + ptr_stk->equalazer ) = 12345678;
    StackBalls ( ptr_stk );

    return STACKCTOR_DONE;
}


int StackBurger ( Stack * ptr_stk )
{
    printf ( "\nsize=%d\n", ptr_stk->size );
    printf ( "capacity=%d\n", ptr_stk->capacity );

    printf ( "Stack:[ " );
    for ( int i = 0 ; i < ( ptr_stk->capacity + ptr_stk->equalazer + 2 ); i++ )
    {
        printf ( "(%d) ", *(ptr_stk->data_ptr + i - 1 )  );
    }
    printf ( "]\n" );

    return STACKBURGER_DONE;
}

int StackBalls ( Stack * ptr_stk )
{
    if ( ptr_stk->size < 0 )
    {
        StackBurger ( ptr_stk );
        return ( ERROR_SIZE );
    }

    if ( ptr_stk->capacity < 0 )
        StackBurger ( ptr_stk );
        return ( ERROR_CAPACITY );
    if ( ( ptr_stk->data_ptr ) == NULL )
        StackBurger ( ptr_stk );
        return ( ERROR_DATA_PTR );
    if ( ptr_stk->size > ptr_stk->capacity )
        StackBurger ( ptr_stk );
        return ( ERROR_S_LARGER_C );
    /*if ( (ptr_stk->data_ptr ) == NULL )
        return 51;
    if ( (ptr_data->petushara2) == NULL )
        return 52;
    if ( (ptr_data->petushara3) == NULL )
        return 53;
    if ( (ptr_data->petushara4) == NULL )
        return 54;*/
    return STACKBALLS_DONE;
}

int StackPop ( Stack * ptr_stk )
{
    if ( ptr_stk->size == 0 )
    {
        printf ( "\nStack have zero elements! Try to add elements before using StackPopa!");
        return ERROR_ZERO_SIZE;
    }
    else
    {
        if ( ptr_stk->size < ptr_stk->capacity/2 )
        {
        ptr_stk->data_ptr = ( Stack_Elem_Data_t* ) realloc ( ptr_stk,  ptr_stk->capacity / 4 );
        }
        int nigger = *( ptr_stk->data_ptr/* + sizeof ( canary_t )*/ + ptr_stk->size - 1 );
        printf ("%d", nigger );
        *( ptr_stk->data_ptr/* + sizeof ( canary_t )*/ + ptr_stk->size - 1 ) = 0;
        (ptr_stk->size)--;
        return ( nigger );
    }
}

int StackPush ( Stack * ptr_stk, Stack_Elem_Data_t value )
{
    // TODO: assert
    if ( ptr_stk->size == ptr_stk->capacity )
    {
        recalloc ( ptr_stk, ( (ptr_stk->capacity) * 2 ) );
        ( ptr_stk->capacity ) *= 2;
    }
    ptr_stk->data_ptr[ ptr_stk->size ] = value;
    (ptr_stk->size)++;

    return STACKPUSH_DONE;
}

int recalloc ( Stack* ptr_stk, int new_capacity )
{
    if ( ( new_capacity * sizeof ( int ) ) % 8 == 0)
        ptr_stk->equalazer = 0;
    else
        ptr_stk->equalazer = sizeof ( canary_t ) - new_capacity * sizeof ( int ) % 8 + 1;
    ptr_stk->data_ptr = ( Stack_Elem_Data_t* ) realloc ( ptr_stk->data_ptr, new_capacity + 2 + ptr_stk->equalazer );
    if (ptr_stk->capacity < new_capacity )
        cleaner_realloc ( ptr_stk );

    *( ptr_stk->data_ptr - 1 ) = PETUSHOK1;
    *( ptr_stk->data_ptr + new_capacity + ptr_stk->equalazer ) = PETUSHOK2;

    return RECALLOC_DONE;
}

int cleaner_realloc ( Stack* ptr_stk )
{
    for ( int i = ptr_stk->capacity; i < ((ptr_stk->capacity * 2) ); i++ )
    {
        *( ptr_stk->data_ptr + i  ) = 0;
    }

    return CLEANERREALLOC_DONE;
}

int StackDtor ( Stack* ptr_stk )
{
    ptr_stk->size = 0;
    ptr_stk->capacity = 0;
    free ( ptr_stk->data_ptr );

    return STACKDTOR_DONE;
}
