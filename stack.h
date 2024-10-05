#ifndef STACK_HEADER
#define STACK_HEADER

#define ASSERT( ptr_stk  )      {                                                                                        \
int c;                                                                                                                   \
if ( ( c = StackBalls ( ptr_stk )) != STACKBALLS_DONE )  {                                                               \
    fprintf ( stderr, "\n####\n#%d error in file %s in func (%s), line %d\n###\n", c, __FILE__, __func__, __LINE__);     \
    fprintf ( stderr, "\nPress Enter to continue" );                                                                     \
    getchar(); }}                                                                                                        \


enum ERROR_CODES
{
    ERROR_SIZE = 0,
    ERROR_CAPACITY = 1,
    ERROR_DATA_PTR = 2,
    ERROR_S_LARGER_C = 3,
    ERROR_ZERO_SIZE = 666,
};

enum PETUSHKI
{
    PETUSHOK1 = 12345678,
    PETUSHOK2 = 12345678,
    PETUSHOK1_ERROR = 666,
    PETUSHOK2_ERROR = 667
};

enum PODZALUPNIY_TVOROG
{//TODO 1-FUNC_DONE, 2-FUNC_ERROR
    STACKCTOR_DONE = 0,
    STACKBURGER_DONE = 0,
    STACKBALLS_DONE = 0,
    STACKPUSH_DONE = 0,
    RECALLOC_DONE = 0,
    CLEANERREALLOC_DONE = 0,
    STACKDTOR_DONE = 0,
};

typedef int Stack_Elem_Data_t;
typedef long long canary_t;

struct Stack
{
    Stack_Elem_Data_t * data_ptr;            // *((char *) data - sizeof(canary_t)) = 0xFEE1DEAD
    int size;
    int capacity;
    int equalazer;
};

int StackCtor ( Stack * ptr_data, int new_capacity );

int StackPush ( Stack * ptr_data, Stack_Elem_Data_t value );

int StackBurger ( Stack * ptr_data );

int StackBalls ( Stack * ptr_stk );

int StackPop ( Stack * ptr_data );

int recalloc ( Stack* ptr_stk, int new_capacity );

int cleaner_realloc ( Stack* ptr_stk );

int StackDtor ( Stack* ptr_stk );

#endif
