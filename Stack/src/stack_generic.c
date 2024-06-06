#include "stack_generic.h"

stack_g alloc_stack_g(stack_type type, size_t len)
{
	stack_g stack = (stack_g)malloc(sizeof(struct struct_stack_g));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: can't allocate memory for stack\n");
		exit(EXIT_FAILURE);
	}
	stack->_type = type;
	switch (type)
	{
	case stack_a_implementation:
		stack->_stack = (void *)alloc_stack_a(len);
		break;
	case stack_l_implementation:
		stack->_stack = (void *)init_stack_l();
		break;
	default:
		fprintf(stderr, "Error: invalid stack type\n");
		exit(EXIT_FAILURE);
	}
	return stack;
}

void _realloc_stack_g(stack_g stack, size_t new_len_stack)
{
	if(stack->_type == stack_a_implementation)
	{
		_realloc_stack_a((stack_a)stack->_stack, new_len_stack);
	}
}

void push_stack_g(stack_g stack, DATA_S_G value)
{
	if(stack->_type == stack_a_implementation)
	{
		push_stack_a((stack_a)stack->_stack, value);
	}
	else if (stack->_type == stack_l_implementation)
	{
		push_stack_l((stack_l)stack->_stack, value);
	}
}

DATA_S_G pop_stack_g(stack_g stack)
{
	if(stack->_type == stack_a_implementation)
	{
		return pop_stack_a((stack_a)stack->_stack);
	}
	else if (stack->_type == stack_l_implementation)
	{
		return pop_stack_l((stack_l)stack->_stack);
	}
	return 0;
}

DATA_S_G peek_stack_g(stack_g stack)
{
	if(stack->_type == stack_a_implementation)
	{
		return peek_stack_a((stack_a)stack->_stack);
	}
	else if (stack->_type == stack_l_implementation)
	{
		return peek_stack_l((stack_l)stack->_stack);
	}
	return 0;
}

size_t get_len_stack_g(stack_g stack)
{
	if(stack->_type == stack_a_implementation)
	{
		return get_len_stack_a((stack_a)stack->_stack);
	}
	else if (stack->_type == stack_l_implementation)
	{
		return get_len_stack_l((stack_l)stack->_stack);
	}
	return 0;
}

bool is_empty_stack_g(stack_g stack)
{
	if(stack->_type == stack_a_implementation)
	{
		return is_empty_stack_a((stack_a)stack->_stack);
	}
	else if (stack->_type == stack_l_implementation)
	{
		return is_empty_stack_l((stack_l)stack->_stack);
	}
	return false;
}

bool is_full_stack_g(stack_g stack)
{
	if(stack->_type == stack_a_implementation)
	{
		return is_full_stack_a((stack_a)stack->_stack);
	}
	else if (stack->_type == stack_l_implementation)
	{
		return false; //stack_l_implementation can't be full
	}
	return false;
}

void clear_stack_g(stack_g stack)
{
	if(stack->_type == stack_a_implementation)
	{
		clear_stack_a((stack_a)stack->_stack);
	}
	//stack_l_implementation doesn't need a clear function
}

void dispose_stack_g(stack_g stack)
{
	if(stack == NULL)
	{
		return;
	}

	if(stack->_type == stack_a_implementation)
	{
		dispose_stack_a((stack_a)stack->_stack);
	}
	else if (stack->_type == stack_l_implementation)
	{
		dispose_stack_l((stack_l)stack->_stack);
	}
	stack->_stack = NULL;
	stack->_type = 0;
	free(stack);
}

void swap_top_stack_g(stack_g stack)
{
	if(get_len_stack_g(stack) == 0)
		return;
	
	DATA_S_G temp1 = pop_stack_g(stack);
	DATA_S_G temp2 = pop_stack_g(stack);

	push_stack_g(stack, temp2);
	push_stack_g(stack, temp1);
}
