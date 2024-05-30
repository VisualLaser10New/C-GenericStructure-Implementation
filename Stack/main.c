#include <stdio.h>
#include <stdlib.h>

#include "stack_l.h"
#include "stack_a.h"

//To compile: gcc main.c ./src/*.c ../Linked-List/src/*.c -I./src/ -I../Linked-List/src/ -o ./main_example

int main_stack_l()
{
	stack_l stack = init_stack_l();
	
	push_stack_l(stack, 1);
	push_stack_l(stack, 2);
	push_stack_l(stack, 3);
	push_stack_l(stack, 4);
	push_stack_l(stack, 5);
	
	printf("Stack Linked List: ");
	while(!is_empty_stack_l(stack))
	{
		printf("%d ", pop_stack_l(stack));
	}
	printf("\n");
	
	dispose_stack_l(stack);
	
	return 0;
}

int main_stack_a()
{
	stack_a stack = alloc_stack_a(5);
	
	push_stack_a(stack, 1);
	push_stack_a(stack, 2);
	push_stack_a(stack, 3);
	push_stack_a(stack, 4);
	push_stack_a(stack, 5);
	
	printf("Stack Array: ");
	while(!is_empty_stack_a(stack))
	{
		printf("%d ", pop_stack_a(stack));
	}
	printf("\n");
	
	dispose_stack_a(stack);
	
	return 0;
}

int main()
{
	main_stack_l();
	main_stack_a();
	
	return 0;
}