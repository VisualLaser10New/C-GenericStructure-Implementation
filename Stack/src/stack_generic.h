/*
This stack implementation provide to make an abstraction of two previous implementations of stack, stack_a and stack_l.
Whit this implementation can use same functions to manage both implementations of stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_a.h"
#include "stack_l.h"

#ifndef STACK_GENERIC
#define STACK_GENERIC
typedef int DATA_S_G;

//data type of stack
typedef enum 
{
	stack_a_implementation,
	stack_l_implementation
}stack_type;

//generic stack structure
typedef struct struct_stack_g
{
	stack_type _type;
	void * _stack;
} *stack_g;

#endif

// Base functions for the stack_g

stack_g alloc_stack_g(stack_type type, size_t len);

void _realloc_stack_g(stack_g stack, size_t new_len_stack);

void push_stack_g(stack_g stack, DATA_S_G value);

DATA_S_G pop_stack_g(stack_g stack);

DATA_S_G peek_stack_g(stack_g stack);

size_t get_len_stack_g(stack_g stack);

bool is_empty_stack_g(stack_g stack);

bool is_full_stack_g(stack_g stack);

void clear_stack_g(stack_g stack);

void dispose_stack_g(stack_g stack);


// More function for the stack_g

//swap two elements on top of stack
void swap_top_stack_g(stack_g stack);
