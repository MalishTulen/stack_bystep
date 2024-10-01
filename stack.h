#ifndef STACK_HEADER
#define STACK_HEADER
//TODO long long as puteshara_t
typedef int Stack_Elem_Data_t;
struct Stack
{
    long long petushara1;
    long long * petushara3;
    Stack_Elem_Data_t * stk_ptr;
    long long * petushara4;
    int size;
    int capacity;
    bool is_blank;
    long long petushara2;
};

void StackCtor ( Stack * ptr_data, int new_capacity );

void StackPush ( Stack * ptr_data, Stack_Elem_Data_t value );

void StackBurger ( Stack * ptr_data );

#endif
