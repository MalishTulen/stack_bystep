#ifndef STACK_HEADER
#define STACK_HEADER

#define STACK_ASSERT( ptr_stk  )      ({                                                                            \
                                                                                                                    \
int c;                                                                                                              \
if ( ( c = StackCheck ( ptr_stk )) != FUNC_DONE )                                                                   \
    switch ( c )                                                                                                    \
    {                                                                                                               \
        case 1:                                                                                                     \
        {                                                                                                           \
            fprintf ( stderr, "\nERROR ( CAPACITY < 0 )  in file %s in func (%s), "                                 \
                              "line %d\n\nPress Enter to continue", __FILE__, __func__, __LINE__);                  \
            getchar();                                                                                              \
            break;                                                                                                  \
        }                                                                                                           \
        case 2:                                                                                                     \
        {                                                                                                           \
            fprintf ( stderr, "\nERROR ( BAD DATA PTR )  in file %s in func (%s), "                                 \
                              "line %d\n\nPress Enter to continue", __FILE__, __func__, __LINE__);                  \
            getchar();                                                                                              \
            break;                                                                                                  \
        }                                                                                                           \
        case 3:                                                                                                     \
        {                                                                                                           \
            fprintf ( stderr, "\nERROR ( SIZE > CAPACITY )  in file %s in func (%s), "                              \
                              "line %d\n\nPress Enter to continue", __FILE__, __func__, __LINE__);                  \
            getchar();                                                                                              \
            break;                                                                                                  \
        }                                                                                                           \
        case 666:                                                                                                   \
        {                                                                                                           \
            fprintf ( stderr, "\nERROR ( YOU CANT POP EMPTY STACK )  in file %s in func (%s), "                     \
                              "line %d\n\nPress Enter to continue", __FILE__, __func__, __LINE__);                  \
            getchar();                                                                                              \
            break;                                                                                                  \
        }                                                                                                           \
        case 0:                                                                                                     \
        {                                                                                                           \
            fprintf ( stderr, "\nERROR ( SIZE < 0 )  in file %s in func (%s), "                                     \
                              "line %d\n\nPress Enter to continue", __FILE__, __func__, __LINE__);                  \
            getchar();                                                                                              \
            break;                                                                                                  \
        }                                                                                                           \
        case 1234:                                                                                                  \
        {                                                                                                           \
            fprintf ( stderr, "\nERROR ( BAD HASH DETECTED )  in file %s in func (%s), "                            \
                              "line %d\n\nPress Enter to continue", __FILE__, __func__, __LINE__);                  \
            getchar();                                                                                              \
            break;                                                                                                  \
        }                                                                                                           \
                                                                                                                    \
        default:                                                                                                    \
        {                                                                                                           \
            fprintf ( stderr, "UNKNOWN ERROR" );                                                                    \
            exit (52);                                                                                              \
        }                                                                                                           \
    }                                                                                                               \
        });

enum ERROR_CODES
{
    ERROR_SIZE = 0,
    ERROR_CAPACITY = 1,
    ERROR_DATA_PTR = 2,
    ERROR_S_LARGER_C = 3,
    ERROR_ZERO_SIZE = 666,
    BAD_HASH = 1234,
};

enum PETUSHKI
{
    PETUSHOK1 = 12345678,
    PETUSHOK2 = 12345678,
    PETUSHOK1_ERROR = 666,
    PETUSHOK2_ERROR = 667
};

enum FUNC_CHECK
{
    FUNC_DONE = 0
};

typedef int Stack_Elem_Data_t;
typedef long long canary_t;

struct Stack
{
    Stack_Elem_Data_t * data_ptr;            // *((char *) data - sizeof(canary_t)) = 0xFEE1DEAD
    int size;
    int capacity;
    int equalazer;
    unsigned long hehesh;
};

unsigned long one_hash          ( const Stack_Elem_Data_t * element );
int           give_me_that_hash ( Stack* ptr_stk );
bool          hash_check        ( Stack* ptr_stk );
int           StackPush         ( Stack * ptr_data, Stack_Elem_Data_t value );
int           StackCtor         ( Stack * ptr_data, int new_capacity );
int           StackDump         ( Stack * ptr_data );
int           StackCheck        ( Stack * ptr_stk );
int           StackPop          ( Stack * ptr_data );
int           recalloc          ( Stack* ptr_stk, int new_capacity );
int           cleaner_realloc   ( Stack* ptr_stk );
int           StackDtor         ( Stack* ptr_stk );
int           give_equalazer    ( Stack * ptr_stk, int capacity );

#endif
