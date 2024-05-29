#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

//stack implemented with linked list

#ifndef STACK
#define STACK
typedef int DATA_S_L;

typedef struct 
{
	size_t _len;
	link * _top; //be a pointer cause the fuctions could edit the list's head
}*stack_l; //be a pointer because functions must edit the _len
#endif


//some function, unlike the stack implementation with array, 
//there aren't cause every node is allocated when is required

void push_stack_l(stack_l stack, DATA_S_L value);

DATA_S_L pop_stack_l(stack_l stack);

DATA_S_L peek_stack_l(stack_l stack);

size_t get_len_stack_l(stack_l stack);

bool is_empty_stack_l(stack_l stack);

void dispose_stack_l(stack_l stack);
