#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "stack.h"

unsigned long give_hash ( const Stack_Elem_Data_t * element )
{
    unsigned long hash_koeff = 5381;
    unsigned long hash_result = 0;

    for (; *element; element++)
        hash_result = ( ( hash_koeff << 5) + hash_koeff ) + *element;

    return hash_result;
}

int StackCtor ( Stack * ptr_stk, int capacity )
{
    if ( capacity < 0 )
    {
        return -1;
    }
    ptr_stk->size = 0;
    ptr_stk->capacity = capacity;
    give_equalazer ( ptr_stk, capacity );

    size_t size = ( 2 + capacity + ptr_stk->equalazer );
    Stack_Elem_Data_t * tmp_ptr = ( Stack_Elem_Data_t * ) calloc ( size, sizeof ( Stack_Elem_Data_t ) );

    ptr_stk->data_ptr = ( Stack_Elem_Data_t* ) ( ( char* ) tmp_ptr + sizeof ( canary_t ) );

    ptr_stk->hehesh = give_hash ( ptr_stk->data_ptr );

    *( tmp_ptr ) = PETUSHOK1;

    *( Stack_Elem_Data_t* ) ( ( char* ) ptr_stk->data_ptr + capacity * sizeof ( Stack_Elem_Data_t )  + ptr_stk->equalazer ) = PETUSHOK2;
    StackDump ( ptr_stk );
    getchar();

    STACK_ASSERT ( ptr_stk );

    return FUNC_DONE;
}


int StackDump ( Stack * ptr_stk )
{
    STACK_ASSERT( ptr_stk );

    printf ( "\nsize=%d\n", ptr_stk->size );
    printf ( "capacity=%d\n", ptr_stk->capacity );
    printf ( "hash=%lu\n", ptr_stk->hehesh );
    printf ( "equalazer=%d\n",

    printf ( "PETUH1: %d\n", *( Stack_Elem_Data_t* ) ( ( char* ) ptr_stk->data_ptr - sizeof ( canary_t ) ) );
    printf ( "Stack:[ " );
    for ( int i = 0 ; i < ( ptr_stk->capacity ); i++ )
    {
        printf ( "(%d) ", *(ptr_stk->data_ptr + i )  );
    }
    printf ( "]\n" );

    printf ( "PETUH2: %d\n", *( Stack_Elem_Data_t* ) ( ( char* ) ( ptr_stk->data_ptr + ptr_stk->capacity ) + ptr_stk->equalazer ) );

    STACK_ASSERT( ptr_stk );

    return FUNC_DONE;
}

int StackCheck ( Stack * ptr_stk )
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
    if ( *( ( Stack_Elem_Data_t* ) ( ( char* ) ( ptr_stk->data_ptr ) - sizeof ( canary_t ) ) ) != PETUSHOK1 )
    {
        printf ( "**\n%d\n***", ( *( ( Stack_Elem_Data_t* ) ( char* ) (ptr_stk->data_ptr ) - sizeof ( canary_t ) ) ) );
        return PETUSHOK1_ERROR;
    }

    if ( *( ( Stack_Elem_Data_t* ) (  ( char* ) ( ptr_stk->data_ptr + ptr_stk->capacity ) + ptr_stk->equalazer ) ) != PETUSHOK2 )
    {
        printf ( "**\n%d\n***", *( ( Stack_Elem_Data_t* ) (  ( char* ) ( ptr_stk->data_ptr + ptr_stk->capacity ) + ptr_stk->equalazer ) ) );
        return PETUSHOK2_ERROR;
    }

   /* if ( ptr_stk->hehesh != ( int c = give_hash ( Stack_Elem_Data_t * element ) ) )
    {
        return ( BAD_HASH );
    }*/
    return FUNC_DONE;
}

int StackPop ( Stack * ptr_stk )
{
    STACK_ASSERT ( ptr_stk );

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

        ptr_stk->hehesh = give_hash ( ptr_stk->data_ptr );

        *( ptr_stk->data_ptr/* + sizeof ( canary_t )*/ + ptr_stk->size - 1 ) = 0;
        (ptr_stk->size)--;

        STACK_ASSERT( ptr_stk );

        return ( nigger );
    }
}

int StackPush ( Stack * ptr_stk, Stack_Elem_Data_t value )
{
    STACK_ASSERT( ptr_stk  );

    if ( ptr_stk->size == ptr_stk->capacity )
    {
        recalloc ( ptr_stk, ( (ptr_stk->capacity) * 2 ) );
        ( ptr_stk->capacity ) *= 2;
    }
    ptr_stk->data_ptr[ ptr_stk->size ] = value;
    (ptr_stk->size)++;

    STACK_ASSERT( ptr_stk );

    return FUNC_DONE;
}

int recalloc ( Stack* ptr_stk, int new_capacity )
{
    STACK_ASSERT( ptr_stk  );

    give_equalazer ( ptr_stk, new_capacity );

    Stack_Elem_Data_t * tmp_ptr = ( Stack_Elem_Data_t* ) realloc ( ( char* ) ptr_stk->data_ptr - sizeof ( canary_t), new_capacity * sizeof ( Stack_Elem_Data_t ) + 2 * sizeof ( canary_t)  + ptr_stk->equalazer );
    ptr_stk->data_ptr = ( Stack_Elem_Data_t* ) ( ( char* ) tmp_ptr + sizeof ( canary_t ) );

    if (ptr_stk->capacity < new_capacity )
        cleaner_realloc ( ptr_stk );

    *( Stack_Elem_Data_t* ) ( ( char* ) ptr_stk->data_ptr - sizeof ( canary_t ) ) = PETUSHOK1;
    *( Stack_Elem_Data_t* ) ( ( char* ) ptr_stk->data_ptr + new_capacity * sizeof ( Stack_Elem_Data_t )  + ptr_stk->equalazer ) = PETUSHOK2;

    STACK_ASSERT( ptr_stk );

    return FUNC_DONE;
}

int cleaner_realloc ( Stack* ptr_stk )
{
    STACK_ASSERT( ptr_stk  );

    for ( int i = ptr_stk->capacity; i < ((ptr_stk->capacity * 2) ); i++ )
    {
        *( ptr_stk->data_ptr + i  ) = 0;
    }

    STACK_ASSERT( ptr_stk );

    return FUNC_DONE;
}

int StackDtor ( Stack* ptr_stk )
{
    STACK_ASSERT( ptr_stk  );

    ptr_stk->size = 0;
    ptr_stk->capacity = 0;
    free ( ptr_stk->data_ptr );

    return FUNC_DONE;
}

int give_equalazer ( Stack * ptr_stk, int capacity )
{
    STACK_ASSERT( ptr_stk );

    if ( ( capacity * sizeof ( int ) ) % sizeof ( canary_t ) == 0 )
        ptr_stk->equalazer = 0;
    else
        ptr_stk->equalazer = sizeof ( canary_t ) - capacity * sizeof ( int ) % sizeof ( canary_t );

    return FUNC_DONE;
}
