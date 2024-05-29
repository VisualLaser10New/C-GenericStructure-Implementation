#include "stack_l.h"

//stack implemented with linked list
void push_stack_l(stack_l stack, DATA_S_L value)
{
	//every element is inserted on the head of the list
	insert_val(stack->_top, value, -1);
	(stack->_len)++;
}

DATA_S_L pop_stack_l(stack_l stack)
{
	if(stack->_len == 0)
		return 0;
	DATA_S_L _output_temp = (*(stack->_top))->value;
	remove_node(stack->_top, 0);
	(stack->_len)--;
	return _output_temp;
}

DATA_S_L peek_stack_l(stack_l stack)
{
	if(stack->_len == 0)
		return 0;
	return (*(stack->_top))->value;
}


size_t get_len_stack_l(stack_l stack)
{
	return stack->_len;
}

bool is_empty_stack_l(stack_l stack)
{
	return stack->_top==NULL || stack->_len == 0;
}

void dispose_stack_l(stack_l stack)
{
	destroy_list(stack->_top);
}