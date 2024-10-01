typedef int Stack_Elem_Data_t;

#include <stdio.h>
#include <malloc.h>
#include "stack.h"

void StackCtor ( Stack * ptr_data, int new_capacity )
{
    //assert
    ptr_data->petushara1 = 0xD01B0EB1;
    ptr_data->petushara2 = 0xD01B0EB2;
    size_t size = (2 * sizeof ( long long ) + (( new_capacity * sizeof ( int ) ) / 8 * 8 ) );
    ptr_data->stk_ptr = ( Stack_Elem_Data_t * ) calloc ( size, sizeof ( Stack_Elem_Data_t ) );

    ptr_data->petushara3 = ptr_data->stk_ptr

    *(ptr_data->petushara3) = 0xD01B0EB3;
    *(ptr_data->petushara4) = 0xD01B0EB4;

    ptr_data->size = 0;
    ptr_data->capacity = new_capacity;
    if ( ( ptr_data->size == 0 ) && !( ptr_data->capacity == 0 ) )
    {
        ptr_data->is_blank = true;
    }
    else
        ptr_data->is_blank = false;
    ptr_data->stk_ptr[0] = 10;
}

void StackPush ( Stack * ptr_data, Stack_Elem_Data_t value )
{
    //assert
    if ( ptr_data->size == ptr_data->capacity )
    {
        ptr_data->stk_ptr = ( Stack_Elem_Data_t* ) realloc ( ptr_data,  ptr_data->capacity + 1 );
        (ptr_data->capacity)++;
    }

    *(ptr_data->stk_ptr + ptr_data->size) = value;
    (ptr_data->size)++;
}

void StackBurger ( Stack * ptr_data )
{
    printf ( "Stack:[ " );
    for ( int i = 2; i < ptr_data->capacity; i++ )
    {
        printf ( "(%d) ", *( ptr_data->stk_ptr + ptr_data->capacity ) );
    }
    printf ( "]" );
}

