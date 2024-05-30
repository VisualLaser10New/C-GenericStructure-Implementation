//implementation with circular array

#include "queue_a_c.h"

queue_a_c alloc_queue_a_c(size_t len)
{
    if(len <= 0)
        return NULL;

    queue_a_c queue_tmp = (queue_a_c)malloc(sizeof(queue_a_c));
    queue_tmp->_arr = (DATA_QAC*)malloc(sizeof(DATA_QAC)*len);
    queue_tmp->_len = 0;
    queue_tmp->_alloc_len = len;
    queue_tmp->_head = 0;
    queue_tmp->_tail = 0;
    return queue_tmp;
}

void _realloc_queue_a_c(queue_a_c queue, size_t new_len_queue)
{
    queue->_arr=(DATA_QAC*)realloc(queue->_arr, sizeof(DATA_QAC)* new_len_queue);
    queue->_alloc_len = new_len_queue;
}

void enqueue_a_c(queue_a_c queue, DATA_QAC value)
{
    if(queue->_len == queue->_alloc_len)
    {
        _realloc_queue_a_c(queue, queue->_alloc_len * 2);
    }

    queue->_arr[queue->_tail] = value;
    queue->_tail = (queue->_tail +1) % queue->_alloc_len;
    (queue->_len)++;
}

DATA_QAC dequeue_a_c(queue_a_c queue)
{
    if(queue->_len == 0 || queue->_alloc_len == 0)
    {
        return 0;
    }
    DATA_QAC ret_temp = queue->_arr[queue->_head];
    queue->_arr[queue->_head] = 0;
    queue->_head = (queue->_head -1) % queue->_alloc_len;
    (queue->_len)--;
    return ret_temp;
}

DATA_QAC peek_queue_a_c(queue_a_c queue)
{
    if(queue->_len == 0 || queue->_alloc_len == 0)
    {
        return 0;
    }
    return queue->_arr[queue->_head];
}