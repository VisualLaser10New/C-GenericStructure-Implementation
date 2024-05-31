//implementation with linked list, non circular

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"


#ifndef QUEUE_L
#define QUEUE_L

typedef int DATA_QL;

typedef struct
{
    link _head;
	link _tail;
    size_t _len;
}* queue_l;

#endif

queue_l init_queue_l(size_t len);

void enqueue_l(queue_l queue, DATA_QL value);

DATA_QL dequeue_l(queue_l queue);

DATA_QL peek_queue_l(queue_l queue);

size_t get_len_queue_l(queue_l queue);

bool is_empty_queue_l(queue_l queue);

void dispose_queue_l(queue_l queue);

void clear_queue_l(queue_l queue);

bool contains_queue_l(queue_l queue, DATA_QL needle);

DATA_QL get_element_queue_l(queue_l queue, int position);