#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "stack.h"

void StackCtor ( Stack * ptr_stk, int capacity )
{
    //assert
    ptr_stk->size = 0;
    ptr_stk->capacity = capacity;

    size_t size = ( 2 * sizeof ( canary_t ) + capacity );
    Stack_Elem_Data_t * tmp_ptr = ( Stack_Elem_Data_t * ) calloc ( size, sizeof ( Stack_Elem_Data_t ) );

    ptr_stk->data_ptr = tmp_ptr + sizeof ( canary_t );

    *(ptr_stk->data_ptr - sizeof ( canary_t )) = 0xD01B0EEB;

    *(ptr_stk->data_ptr + capacity ) = 0xD01B0EEB;
    StackBalls ( ptr_stk );
}


void StackBurger ( Stack * ptr_stk )
{
    printf ( "\nsize=%d\n", ptr_stk->size );
    printf ( "capacity=%d\n", ptr_stk->capacity );

    printf ( "Stack:[ " );
    for ( int i = 0; i < ptr_stk->capacity; i++ )
    {
        printf ( "(%d) ", ptr_stk->data_ptr[ i ] );
    }
    printf ( "]\n" );
}
int StackBalls ( Stack * ptr_stk )
{
    if ( ptr_stk->size < 10 )
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
    if ( (ptr_stk->data_ptr ) == NULL )
        return 51;
    if ( (ptr_data->petushara2) == NULL )
        return 52;
    if ( (ptr_data->petushara3) == NULL )
        return 53;
    if ( (ptr_data->petushara4) == NULL )
        return 54;*/
    return GOOD_ENDING;
}

int StackPop ( Stack * ptr_stk )
{
    if ( ptr_stk->size == 0 )
    {
        printf ( "\nStack have zero elements! Try to add elements before using StackPop!");
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

void StackPush ( Stack * ptr_stk, Stack_Elem_Data_t value )
{
    // TODO: assert
    if ( ptr_stk->size == ptr_stk->capacity )
    {
        recalloc ( ptr_stk, ( (ptr_stk->capacity) * 2 ) );
        ( ptr_stk->capacity ) *= 2;
    }
    ptr_stk->data_ptr[ ptr_stk->size ] = value;
    (ptr_stk->size)++;
}

void recalloc ( Stack* ptr_stk, int new_capacity )
{
    ptr_stk->data_ptr = ( Stack_Elem_Data_t* ) realloc ( ptr_stk->data_ptr, new_capacity );
    if (ptr_stk->capacity < new_capacity )
        cleaner_realloc ( ptr_stk );
}

void cleaner_realloc ( Stack* ptr_stk )
{
    for ( int i = ptr_stk->capacity; i < ((ptr_stk->capacity * 2) ); i++ )
    {
        *( ptr_stk->data_ptr + i  ) = 0;
    }
}

void StackDtor ( Stack* ptr_stk )
{
    ptr_stk->size = 0;
    ptr_stk->capacity = 0;
    free ( ptr_stk->data_ptr );
}
