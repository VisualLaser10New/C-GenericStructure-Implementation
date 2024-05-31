#include <stdio.h>
#include <stdlib.h>

#include "queue_l.h"
#include "queue_a_c.h"

//To compile: gcc main.c ./src/*.c ../Linked-List/src/*.c -I./src/ -I../Linked-List/src/ -o ./main_example

void main_queue_a_c()
{
	queue_a_c queue = alloc_queue_a_c(10);
	enqueue_a_c(queue, 1);
	enqueue_a_c(queue, 2);
	enqueue_a_c(queue, 3);
	enqueue_a_c(queue, 4);
	enqueue_a_c(queue, 5);
	enqueue_a_c(queue, 6);
	enqueue_a_c(queue, 7);
	
	printf("Queue AC:\n\t");
	size_t len = get_len_queue_a_c(queue)-1;
	for(size_t i=0;i< len; i++)
	{
		printf("%d\t", dequeue_a_c(queue));
	}
	printf("\n\tIs empty: %c\n\t", (is_empty_queue_a_c(queue)? 'Y':'N'));
	enqueue_a_c(queue, 55);
	enqueue_a_c(queue, 66);
	enqueue_a_c(queue, 77);
	enqueue_a_c(queue, 77);
	enqueue_a_c(queue, 77);
	enqueue_a_c(queue, 77);
	enqueue_a_c(queue, 77);

	len = get_len_queue_a_c(queue);
	for(size_t i=0;i< len; i++)
	{
		printf("%d\t", dequeue_a_c(queue));
	}
	printf("\n\tIs empty: %c\n", (is_empty_queue_a_c(queue)? 'Y':'N'));
	dispose_queue_a_c(queue);
}

void main_queue_l()
{
	queue_l queue = init_queue_l(10);
	enqueue_l(queue, 1);
	enqueue_l(queue, 2);
	enqueue_l(queue, 3);
	enqueue_l(queue, 4);
	enqueue_l(queue, 5);
	enqueue_l(queue, 6);
	enqueue_l(queue, 7);

	printf("Queue L: ");
	size_t len = get_len_queue_l(queue)-3;
	for(int i=0;i< len; i++)
	{
		printf("%d\t", dequeue_l(queue));
	}
	printf("\n");
	enqueue_l(queue, 55);
	enqueue_l(queue, 66);
	enqueue_l(queue, 77);
	enqueue_l(queue, 77);
	enqueue_l(queue, 77);
	enqueue_l(queue, 77);
	enqueue_l(queue, 77);

	printf("Queue L: ");
	len = get_len_queue_l(queue);
	for(int i=0;i< len; i++)
	{
		printf("%d\t", dequeue_l(queue));
	}
	printf("\n");
	printf("\n\tIs empty: %c\n", (is_empty_queue_l(queue)? 'Y':'N'));

	dispose_queue_l(queue);
}

int main()
{
	//main_queue_a_c();
	main_queue_l();
}