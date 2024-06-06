#include <stdio.h>
#include <stdlib.h>

#include "stack_l.h"
#include "stack_a.h"
#include "stack_generic.h"

//To compile: gcc main.c ./src/*.c ../Linked-List/src/*.c -I./src/ -I../Linked-List/src/ -o ./main_example -Wall -Wextra

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

int main_stack_generic()
{
	// Create a stack_g of type STACK_A with length 5
	printf("Stack generic\n\n");
	stack_g stack = alloc_stack_g(stack_a_implementation, 5);

	// Push some values onto the stack
	push_stack_g(stack, 10);
	push_stack_g(stack, 20);
	push_stack_g(stack, 30);

	// Pop a value from the stack
	DATA_S_G poppedValue = pop_stack_g(stack);
	printf("Popped value: %d\n", poppedValue);

	// Peek at the top value of the stack
	DATA_S_G topValue = peek_stack_g(stack);
	printf("Top value: %d\n", topValue);

	// Get the length of the stack
	size_t stackLength = get_len_stack_g(stack);
	printf("Stack length: %zu\n", stackLength);

	// Check if the stack is empty
	bool isEmpty = is_empty_stack_g(stack);
	printf("Is stack empty? %s\n", isEmpty ? "Yes" : "No");

	// Check if the stack is full
	bool isFull = is_full_stack_g(stack);
	printf("Is stack full? %s\n", isFull ? "Yes" : "No");

	// Swap the top two elements of the stack
	swap_top_stack_g(stack);

	// Clear the stack
	clear_stack_g(stack);

	// Dispose of the stack
	dispose_stack_g(stack);

	return 0;
}

int main()
{
	//main_stack_l();
	//main_stack_a();
	main_stack_generic();
	
	return 0;
}