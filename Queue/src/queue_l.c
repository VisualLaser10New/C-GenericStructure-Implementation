#include "queue_l.h"

queue_l init_queue_l(size_t len)
{
	queue_l temp = (queue_l)malloc(sizeof(queue_l));
	temp->_len = 0;
	temp->_head = NULL;
	temp->_tail = NULL;
	return temp;
}

void enqueue_l(queue_l queue, DATA_QL value)
{
	link temp_node = alloc_node();
	temp_node->value= value;
	temp_node->next = NULL;
	if(queue->_tail == NULL)
	{
		//if tail is null, head is null too, that means the list is empty
		queue->_head = temp_node;
		queue->_tail = temp_node;
	}
	else
	{
		queue->_tail->next = temp_node;
		queue->_tail = temp_node;
	}
	(queue->_len)++;
}

DATA_QL dequeue_l(queue_l queue)
{
	if(queue->_len == 0)
		return 0;

	link return_temp = queue->_head;
	DATA_QL return_data = return_temp->value;
	queue->_head = queue->_head->next;

	//destroy temporary node
	free(return_temp);
	(queue->_len)--;

	//check if queue is empty
	if(queue->_len ==0 || queue->_head == NULL)
		queue->_tail = NULL;

	return return_data;
}

DATA_QL peek_queue_l(queue_l queue)
{
	return (queue->_len == 0) ? 0 : queue->_head->value;
}

size_t get_len_queue_l(queue_l queue)
{
	return queue->_len;
}

bool is_empty_queue_l(queue_l queue)
{
	return queue->_len == 0;
}

void dispose_queue_l(queue_l queue)
{
	clear_queue_l(queue);
	free(queue);
}

void clear_queue_l(queue_l queue)
{
	destroy_list(&(queue->_head));

	queue->_head = NULL;
	queue->_tail = NULL;
	queue->_len = 0;
}

bool contains_queue_l(queue_l queue, DATA_QL needle)
{
	return find_val_list(queue->_head, needle) != NULL;
}

DATA_QL get_element_queue_l(queue_l queue, int position)
{
	return (DATA_QL)getAtPos(queue->_head, position)->value;
}