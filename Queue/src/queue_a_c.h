#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#ifndef QUEUE_AC;
#define QUEUE_AC;

typedef int DATA_QAC;

typedef struct
{
    DATA_QAC * _arr;
    size_t _len;
    size_t _alloc_len;
    unsigned long long _head;
    unsigned long long _tail;
}* queue_a_c;

#endif

queue_a_c alloc_queue_a_c(size_t len);

void _realloc_queue_a_c(queue_a_c queue, size_t new_len_queue);

void enqueue_a_c(queue_a_c queue, DATA_QAC value);

DATA_QAC dequeue_a_c(queue_a_c queue);

DATA_QAC peek_queue_a_c(queue_a_c queue);

size_t get_len_queue_a_c(queue_a_c queue);

bool is_empty_queue_a_c(queue_a_c queue);

bool is_full_queue_a_c(queue_a_c queue);

void clear_queue_a_c(queue_a_c queue);

void dispose_queue_a_c(queue_a_c queue);