#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef STACK
#define STACK
typedef DATA_S_A int

typedef struct n
{
	size_t _len;
	size_t _alloc_len;
	DATA_S_A * _arr;
}stack_a;
#endif

stack_a alloc_stack_a(size_t len);

stack_a _realloc_stack_a(stack_a stack, size_t new_len_stack)

void push_stack_a(stack_a stack, DATA_S_A value);

DATA_S_A pop_stack_a(stack_a stack);

DATA_S_A peek_stack_a(stack_a stack);

size_t get_len_stack_a(stack_a stack);

bool is_empty_stack_a(stack_a stack);

bool is_full_stack_a(stack_a stack);

void clear_stack_a(stack_a stack);

void dispose_stack_a(stack_a *stack);