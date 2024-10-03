#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "stack.h"

void StackCtor ( Stack * ptr_stk, int capacity )
{
    //assert
    //*(ptr_data->petushara1) = 0xD01B0EB1;
    //*(ptr_data->petushara2) = 0xD01B0EB2;
    //size_t size = (/*2 * sizeof ( canary_t ) +*/ (( new_capacity * sizeof ( Stack_Elem_Data_t ) ) ) );
    ptr_stk->data_ptr = ( Stack_Elem_Data_t * ) calloc ( capacity, sizeof ( Stack_Elem_Data_t ) );
    //ptr_data->petushara3 = ptr_data->stk_ptr;

    //*(ptr_data->petushara3) = 0xD01B0EB3;

    //*(ptr_data->petushara4) = 0xD01B0EB4;

    ptr_stk->size = 0;
    ptr_stk->capacity = capacity;

    //*(ptr_data->stk_ptr(5)) = 10;
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
    if ( ptr_stk->size < 0 )
        return ERROR_SIZE;

    if ( ptr_stk->capacity < 0 )
        return ERROR_CAPACITY;

    if ( ( ptr_stk->data_ptr ) == NULL )
        return ERROR_DATA_PTR;

    if ( ptr_stk->size > ptr_stk->capacity )
        return ERROR_S_LARGER_C;

    /*if ( (ptr_data->petushara1) == NULL )
        return 51;
    if ( (ptr_data->petushara2) == NULL )
        return 52;
    if ( (ptr_data->petushara3) == NULL )
        return 53;
    if ( (ptr_data->petushara4) == NULL )
        return 54;*/

    return 0;
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
