#include <stdio.h>
#include <stdlib.h>

#ifndef NODE
#define NODE
typedef struct n
{
	int value;
	struct n *next;
}node;
#endif


#ifndef LINK
#define LINK
typedef node* link;
#endif


#ifndef ALLOCATOR
#define ALLOCATOR
link alloc_node();
#endif


#ifndef GENERATOR
#define GENERATOR
link generate_list(size_t size);
#endif

#ifndef ARRLIST
#define ARRLIST
link arr2list(int arr[], size_t size);
#endif

#ifndef APPENDVAL
#define APPENDVAL
void append_val(link list, int val);
#endif


#ifndef LASTNODE
#define LASTNODE
link last_node(link list);
#endif


#ifndef APPENDNODE
#define APPENDNODE
void append_node(link list, link nodo);
#endif

#ifndef INSERTVAL
#define INSERTVAL
void insert_val(link* list, int val, int pre_pos);
#endif

#ifndef INSERTNODE
#define INSERTNODE
void insert_node(link* list, link nodo, int pre_pos);
#endif

#ifndef REMOVENODE
#define REMOVENODE
void remove_node(link* list, int pos);
#endif

#ifndef GETPOS
#define GETPOS
link getAtPos(link list, int pos);
#endif

#ifndef FIND
#define FIND
link find(link list, int needle);
#endif

#ifndef LLENGTH
#define LLENGTH
size_t llength(link list);
#endif

#ifndef REVERSE
#define REVERSE
link reverse_list(link list);
#endif

#ifndef LISTARR
#define LISTARR
int* list2arr(link list);
#endif

#ifndef CONCAT
#define CONCAT
void list_concat(link list_con, link list_cat);
#endif

#ifndef DESTROY
#define DESTROY
void destroyl(link list);
#endif

#ifndef RMLAST
#define RMLAST
void remove_last(link list);
#endif

#ifndef SWAP
#define SWAP
void swap_elements(link* list, unsigned pos1, unsigned pos2);
#endif

#ifndef SETALL
#define SETALL
void set_all_values(link list, int value);
#endif

//dumb function
void print_list (link lista);