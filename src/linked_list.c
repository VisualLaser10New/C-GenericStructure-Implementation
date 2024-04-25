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
	set_all_values_list(first, 0);
	return first;
}

link last_node(link *list)
{
	if(*list == NULL)
	{
		return NULL;
	}

	link tmp = *list;
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
	while(tmp!= NULL)
	{
		printf("%i -> ", tmp->value);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

void print_list_articulate (link lista)
{
	link tmp= lista;
	//printf("Max Verstappen\n");
	for(int i=0; i<llength(lista); i++)
	{
		printf("[%i]\t", i);
	}
	printf("\n");

	while(tmp!= NULL)
	{
		printf("%i ->\t", tmp->value);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

void append_val(link *list, int val)
{
	link nodo = alloc_node();
	nodo->value= val;
	nodo->next = NULL;
	
	append_node(list, nodo);
}

void append_node(link *list, link nodo)
{
	link last = last_node(list);
	if (last == NULL)
	{
		*list = nodo;
	}
	else
	{
		last->next = nodo;
	}
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

link find_val_list(link list, int needle)
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

link reverse_list(link* list)
{
	link out = last_node(list);
	link pre_node = NULL;
	link now_node = *list;
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

link intersect_list(link list1, link list2)
{
	//found and return a list with only elements are in both
	link output = NULL; //= alloc_node();
	//output->next = NULL;
	link tmp1 = list1;
	while(tmp1 != NULL)
	{
		link tmp2 = list2;
		while(tmp2 != NULL)
		{
			//printf("%d\n",tmp1->value );
			if(tmp1-> value == tmp2->value)
			{
				append_val(&output, tmp1->value);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return output;
}

link duplicate_list(link list)
{
	link out = NULL;
	link tmp = list;

	while(tmp!=NULL)
	{
		append_val(&out, tmp->value);
		tmp = tmp->next;
	}
	return out;
}

link concat_list(link list_con, link list_cat)
{
	link out_con = duplicate_list(list_con);
	link out_cat = duplicate_list(list_cat);

	last_node(&out_con)->next = out_cat;
	return out_con;
}

void destroy_list(link* list)
{
	link tmp = *list;
	while(tmp != NULL)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	free(tmp);
	*list= NULL;
}

link shellsort_list(link list)
{
	//shell sort a list ascending
	link output = duplicate_list(list);
	size_t len = llength(list);
	size_t k=len, position=0, real_position =0;
	char back = 0; //if came back is 1, otherwise is 0
	k/=2;
	//printf("len: %d\n k:%d\n", len, k);
	while(1)
	{
		//printf("k: %d\n", k);
		if(k!= 0 && position+k > len-1 && !back)
		{
			//end of this view size
			position=0;
			k/=2;
		}
		else if(k<=1 && position+k > len-1)
		{
			//end
			break;
		}
		
		if(k==0)
		{
			//end
			break;
		}
		// printf("pos: %d\t pos+k: %d\t back:%d\n", position, position+k, back);
		// print_list(output);
		// printf("maybe to swap: %d > %d\n", getAtPos(output, position)->value, getAtPos(output, position+k)->value);
		// scanf("%*c");
		if(getAtPos(output, position)->value > getAtPos(output, position+k)->value)
		{
			//swap elements
			swap_elements_list(&output, position, position+k);
			//printf("SWAPPED\n");
			if((int)position-(int)k >= 0)
			{
				//back to check previous values
				//printf("back\n");
				if(back==0)
				{
					//store real position only if back was not active yet
					real_position= position;
					back = 1;
				}
				position-=k;
				continue;
			}
		}
		else
		{
			if(back)
			{
				//stop coming back
				position = real_position+1;
				back =0;
				continue;
			}
		}
		position++;
	}
	return output;
}

void swap_elements_list(link* list, unsigned pos1, unsigned pos2)
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

void set_all_values_list(link list, int value)
{
	link tmp = list;
	while(tmp!=NULL)
	{
		tmp->value=value;
		tmp = tmp->next;
	}
}

int sum_all_values_list(link list)
{
	int output = 0;
	link tmp = list;
	while(tmp != NULL)
	{
		output += tmp->value;
		tmp = tmp->next;
	}
	return output;
}

link sum_parallel_values_list(link list1, link list2)
{
	link output=NULL;
	if(llength(list1) != llength(list2))
		return NULL;
	
	link tmp1 = list1, tmp2 = list2;
	while(tmp1 != NULL)
	{
		append_val(&output, list1->value + list2->value);

		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return output;
}

link max_min_value_list(link list1, char max)
{
	//base function for max and min, not declared in header file
	//1 max, 0 min
	if(list1==NULL)
		return NULL;
	link tmp = list1, output = list1;

	while(tmp != NULL)
	{
		if(max)
		{
			if(tmp->value > output->value)
				output = tmp;
		}
		else
		{
			if(tmp->value < output->value)
				output = tmp;
		}
		tmp = tmp->next;
	}
	return output;
}

link max_value_list(link list)
{
	return max_min_value_list(list, 1);
}

link min_value_list(link list)
{
	return max_min_value_list(list, 0);
}

float avg_value_list(link list)
{
	if(list==NULL)
		return 0.0;

	link tmp = list;
	float sum = 0; int count = 0;
	while(tmp != NULL)
	{
		sum+= (float)tmp->value;
		count++;
		tmp = tmp->next;
	}
	return sum/(float)count;
}

void remove_last(link list)
{
	remove_node(&list, llength(list)-1);
}
