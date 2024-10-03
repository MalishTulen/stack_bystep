#ifndef STACK_HEADER
#define STACK_HEADER

enum ERROR_CODES
{
    ERROR_SIZE = 0,
    ERROR_CAPACITY = 1,
    ERROR_DATA_PTR = 2,
    ERROR_S_LARGER_C = 3,
    ERROR_ZERO_SIZE = 666,
    GOOD_ENDING = 7;
};

//TODO long long as puteshara_t
typedef int Stack_Elem_Data_t;
typedef long long canary_t;
struct Stack
{
    Stack_Elem_Data_t * data_ptr;            // *((char *) data - sizeof(canary_t)) = 0xFEE1DEAD
    int size;
    int capacity;
};

void StackCtor ( Stack * ptr_data, int new_capacity );

void StackPush ( Stack * ptr_data, Stack_Elem_Data_t value );

void StackBurger ( Stack * ptr_data );

void StackBalls ( Stack * ptr_data );

int StackPop ( Stack * ptr_data );

void recalloc ( Stack* ptr_stk, int new_capacity );

void cleaner_realloc ( Stack* ptr_stk );

void StackDtor ( Stack* ptr_stk );

#endif
