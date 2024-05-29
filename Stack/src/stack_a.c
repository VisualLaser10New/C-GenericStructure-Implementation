#include "stack_a.h"

//stack implemented with array


stack_a alloc_stack_a(size_t len)
{
    stack_a stack_tmp;
    stack_tmp._arr = (DATA_S_A*)malloc(sizeof(DATA_S_A) * len);
    stack_tmp._len = 0;
    stack_tmp._alloc_len = len;
    return stack_tmp;
}

void _realloc_stack_a(stack_a *stack, size_t new_len_stack)
{
    stack->_arr=(DATA_S_A*)realloc(stack->_arr, sizeof(DATA_S_A)* new_len_stack);
    stack->_alloc_len = new_len_stack;
}

void push_stack_a(stack_a *stack, DATA_S_A value)
{
    if(stack->_len == stack->_alloc_len)
    {
        //double the len size
        _realloc_stack_a(stack, 2*(stack->_alloc_len));
    }
    stack->_arr[(stack->_len)++] = value;
}

DATA_S_A pop_stack_a(stack_a *stack)
{
    if(stack->_len == 0)
        return 0;

    DATA_S_A tmp_value= stack->_arr[--(stack->_len)];
    stack->_arr[stack->_len] = (DATA_S_A) 0;
    return tmp_value;
}

DATA_S_A peek_stack_a(stack_a *stack)
{
    if(stack->_len == 0)
        return 0;
    return stack->_arr[stack->_len -1];
}

size_t get_len_stack_a(stack_a *stack)
{
    return stack->_len;
}

bool is_empty_stack_a(stack_a *stack)
{
    return (stack->_len == 0);
}

bool is_full_stack_a(stack_a *stack)
{
    return (stack->_len != 0);
}

void clear_stack_a(stack_a *stack)
{
    for(size_t i = 0; i< stack->_alloc_len; i++)
    {
        stack->_arr[i] = (DATA_S_A)0;
    }
    stack->_len = 0;
}

void dispose_stack_a(stack_a *stack)
{
    free(stack->_arr);
    stack->_alloc_len = 0;
    stack->_len = 0;
}
