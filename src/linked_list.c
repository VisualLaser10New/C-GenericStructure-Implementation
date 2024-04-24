//Visual Laser 10 New

#include "linked_list.h"

link alloc_node()
{
	return (link)malloc(sizeof(link));
}

link generate_list(size_t size)
{
	link first = alloc_node();
	link last = first;
	link tmp;

	for(size_t i=0; i<size; i++)
	{
		tmp = alloc_node();
		last->next=tmp;
		if(i+1!=size)
			last = tmp;
	}
	last->next = NULL;
	set_all_values(first, 0);
	return first;
}

link last_node(link list)
{
	if(list == NULL)
	{
		printf("ok");
		return NULL;
	}

	link tmp = list;
	link last = NULL;
	while(tmp != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	return last;
}

void print_list (link lista)
{
	link tmp= lista;
	//printf("Max Verstappen\n");
	while(tmp!= NULL)
	{
		printf("%i -> ", tmp->value);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

void append_val(link list, int val)
{
	link nodo = alloc_node();
	nodo->value= val;
	nodo->next = NULL;
	
	append_node(list, nodo);
}

void append_node(link list, link nodo)
{
	link last = last_node(list);
	printf("last %d\n", last->value);
	last->next = nodo;
}

void updateAtPos(link list, int pos, int update)
{
	link node = getAtPos(list, pos);
	node->value=update;
}

link getAtPos(link list, int pos)
{
	if((size_t)pos >= llength(list) || pos < 0)
	{
		return NULL;
	}

	int c=0;
	link tmp= list;
	while(tmp!= NULL)
	{
		if(c==pos)
			return tmp;
		tmp = tmp->next;
		c++;
	}
	return NULL;
}

link find(link list, int needle)
{
	link tmp= list;
	while(tmp!= NULL)
	{
		if(tmp->value == needle)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

size_t llength(link list)
{
	size_t c=0;
	link tmp= list;
	while(tmp!= NULL)
	{
		tmp = tmp->next;
		c++;
	}
	return c;
}

link getprec(link list, link node)
{
	if(list == node) //if is first return NULL
		return NULL;
	size_t c=0;
	link tmp= list;
	if(tmp==NULL) return NULL;
	while(tmp->next != NULL)
	{
		if(tmp->next->next == node->next)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

link arr2list(int arr[], size_t len)
{
	link output = generate_list(len);
	link now = output;
	for(size_t i=0;i< len;i++)
	{
		now->value=arr[i];
		now = now->next;
	}
	return output;
}

void insert_val(link* list, int val, int pre_pos)
{
	link nod = alloc_node();
	nod->value = val;
	insert_node(list, nod, pre_pos);
}

void insert_node(link* list, link ins_node, int pre_pos)
{
	if(pre_pos==-1)
	{
		ins_node->next=*list;
		*list = ins_node;
	}
	else if(pre_pos>=0)
	{
		link pre_node = getAtPos(*list, pre_pos);
		link next_node = pre_node->next;
		pre_node->next = ins_node;
		ins_node->next = next_node;
	}
}

void remove_node(link* list, int pos)
{
	link node = getAtPos(*list, pos);
	
	link pre_node = getprec(*list, node);

	link next_node = node->next;
	if(pre_node != NULL)
		pre_node->next = next_node;
	else
		*list = next_node;
	free(node);
}

link reverse_list(link list)
{
	link out = last_node(list);
	link pre_node = NULL;
	link now_node = list;
	link next_node = NULL;

	while(now_node != NULL)
	{
		next_node = now_node->next;
		now_node->next = pre_node;
		pre_node=now_node;
		now_node=next_node;
	}
	return out;
}

int* list2arr(link list)
{
	link tmp = list;
	int *arr =(int*) malloc(llength(list)*sizeof(int));
	int count =0;
	while(tmp != NULL)
	{
		*(arr+count) = tmp->value;
		tmp = tmp->next;
		count++;
	}
	return arr;
}

link intersect(link list1, link list2)
{
	//found and return a list with only elements are in both
	link output = alloc_node();
	output->next = NULL;
	link tmp1 = list1;
	while(tmp1 != NULL)
	{
		link tmp2 = list2;
		while(tmp2 != NULL)
		{
			//printf("%d\n",tmp1->value );
			if(tmp1-> value == tmp2->value)
			{
				append_val(output, tmp1->value);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return output;
}

link concat(link list_con, link list_cat)
{
	last_node(list_con)->next = list_cat;
}

void destroyl(link list)
{
	link tmp = list;
	while(tmp != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(tmp);
}

void swap_elements(link* list, unsigned pos1, unsigned pos2)
{
	size_t len = llength(*list);
	if((size_t)pos1 >= len || (size_t)pos2 >= len || pos1 >= pos2)
	{
		return;
	}

	
	link el1 = getAtPos(*list, pos1);
	link el2 = getAtPos(*list, pos2);


	insert_val(list, el1->value, pos2);
	insert_val(list, el2->value, pos1);
	

	remove_node(list, pos1);
	remove_node(list, pos2);
}

void set_all_values(link list, int value)
{
	link tmp = list;
	while(tmp!=NULL)
	{
		tmp->value=value;
		tmp = tmp->next;
	}
}

void remove_last(link list)
{
	remove_node(&list, llength(list)-1);
}
