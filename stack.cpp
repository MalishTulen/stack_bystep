#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "stack.h"

int StackCtor ( Stack * ptr_stk, int capacity )
{
    //assert
    ptr_stk->size = 0;
    ptr_stk->capacity = capacity;
    if ( ( capacity * sizeof ( Stack_Elem_Data_t ) ) % sizeof ( canary_t ) == 0)
        ptr_stk->equalazer = 0;
    else
        ptr_stk->equalazer = sizeof ( canary_t ) - capacity * sizeof ( Stack_Elem_Data_t ) % sizeof ( canary_t );

    size_t size = ( 2 + capacity + ptr_stk->equalazer );
    Stack_Elem_Data_t * tmp_ptr = ( Stack_Elem_Data_t * ) calloc ( size, sizeof ( Stack_Elem_Data_t ) );

    ptr_stk->data_ptr = ( Stack_Elem_Data_t* ) ( ( char* ) tmp_ptr + sizeof ( canary_t ) );

    *( tmp_ptr ) = PETUSHOK1;

    *( Stack_Elem_Data_t* ) ( ( char* ) ptr_stk->data_ptr + capacity * sizeof ( Stack_Elem_Data_t )  + ptr_stk->equalazer ) = PETUSHOK2;
    StackBalls ( ptr_stk );

    return STACKCTOR_DONE;
}


int StackBurger ( Stack * ptr_stk )
{
    printf ( "\nsize=%d\n", ptr_stk->size );
    printf ( "capacity=%d\n", ptr_stk->capacity );

    printf ( "PETUH1: %d\n", *( Stack_Elem_Data_t* ) ( ( char* ) ptr_stk->data_ptr - sizeof ( canary_t ) ) );
    printf ( "Stack:[ " );
    for ( int i = 0 ; i < ( ptr_stk->capacity ); i++ )
    {
        printf ( "(%d) ", *(ptr_stk->data_ptr + i )  );
    }
    printf ( "]\n" );

    printf ( "PETUH2: %d\n", *( Stack_Elem_Data_t* ) ( ( char* ) ( ptr_stk->data_ptr + ptr_stk->capacity ) + ptr_stk->equalazer ) );


    return STACKBURGER_DONE;
}

int StackBalls ( Stack * ptr_stk )
{
    if ( ptr_stk->size < 0 )
    {
        return ( ERROR_SIZE );
    }

    if ( ptr_stk->capacity < 0 )
    {
        return ( ERROR_CAPACITY );
    }
    if ( ( ptr_stk->data_ptr ) == NULL )
    {
        return ( ERROR_DATA_PTR );
    }
    if ( ptr_stk->size > ptr_stk->capacity )
    {
        return ( ERROR_S_LARGER_C );
    }
    if ( *( ( Stack_Elem_Data_t* ) ( char* ) (ptr_stk->data_ptr ) - sizeof ( canary_t ) ) != PETUSHOK1 )
    {
        printf ( "**\n%d\n***", ( *( ( Stack_Elem_Data_t* ) ( char* ) (ptr_stk->data_ptr ) - sizeof ( canary_t ) ) ) );
        return PETUSHOK1_ERROR;
    }

    if ( *( ( Stack_Elem_Data_t* ) ( char* ) ( ptr_stk->data_ptr + ptr_stk->capacity ) + ptr_stk->equalazer ) != PETUSHOK2 )
        return PETUSHOK2_ERROR;
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
    if ( ( new_capacity * sizeof ( int ) ) % sizeof ( canary_t ) == 0)
        ptr_stk->equalazer = 0;
    else
        ptr_stk->equalazer = sizeof ( canary_t ) - new_capacity * sizeof ( int ) % sizeof ( canary_t );

    Stack_Elem_Data_t * tmp_ptr = ( Stack_Elem_Data_t* ) realloc ( ( char* ) ptr_stk->data_ptr - sizeof ( canary_t), new_capacity * sizeof ( Stack_Elem_Data_t ) + 2 * sizeof ( canary_t)  + ptr_stk->equalazer );
    ptr_stk->data_ptr = ( Stack_Elem_Data_t* ) ( ( char* ) tmp_ptr + sizeof ( canary_t ) );

    if (ptr_stk->capacity < new_capacity )
        cleaner_realloc ( ptr_stk );

    *( Stack_Elem_Data_t* ) ( ( char* ) ptr_stk->data_ptr - sizeof ( canary_t ) ) = PETUSHOK1;
    *( Stack_Elem_Data_t* ) ( ( char* ) ptr_stk->data_ptr + new_capacity * sizeof ( Stack_Elem_Data_t )  + ptr_stk->equalazer ) = PETUSHOK2;

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
