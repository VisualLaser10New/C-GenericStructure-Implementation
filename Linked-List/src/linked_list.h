#include <stdio.h>
#include <stdlib.h>


#define max(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

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
void append_val(link *list, int val);
#endif

#ifndef APPENDNODE
#define APPENDNODE
void append_node(link *list, link nodo);
#endif

#ifndef LASTNODE
#define LASTNODE
link last_node(link *list);
#endif

#ifndef SHELLSORT
#define SHELLSORT
link shellsort_list(link list);
#endif

#ifndef MERGESORT
#define MERGESORT
link mergesort_list(link list);
#endif

#ifndef INSERTVAL
#define INSERTVAL
void insert_val(link* list, int val, int pre_pos);
#endif

#ifndef INSERTNODE
#define INSERTNODE
void insert_node(link* list, link nodo, int pre_pos);
#endif

#ifndef UPDATE
#define UPDATE
void updateAtPos(link list, int pos, int update);
#endif

#ifndef REMOVENODE
#define REMOVENODE
void remove_node(link* list, int pos);
#endif

#ifndef GETPOS
#define GETPOS
link getAtPos(link list, unsigned pos);
#endif

#ifndef FIND
#define FIND
link find_val_list(link list, int needle);
#endif

#ifndef CONCAT
#define CONCAT
link concat_list(link list_con, link list_cat);
#endif

#ifndef LLENGTH
#define LLENGTH
size_t llength(link list);
#endif

#ifndef REVERSE
#define REVERSE
link reverse_list(link* list);
#endif

#ifndef LISTARR
#define LISTARR
int* list2arr(link list);
#endif

#ifndef DUPLICATE
#define DUPLICATE
link duplicate_list(link list);
#endif

#ifndef DESTROY
#define DESTROY
void destroy_list(link* list);
#endif

#ifndef RMLAST
#define RMLAST
void remove_last(link list);
#endif

#ifndef SUBLIST
#define SUBLIST
link sublist(link list, unsigned from, unsigned to);
#endif

#ifndef MERGEPROCESS
#define MERGEPROCESS
link _merge_sorting_list(link first, link second);
#endif

#ifndef COPYLIST
#define COPYLIST
link clone_list(link *list);
#endif

#ifndef SWAP
#define SWAP
void swap_elements_list(link* list, unsigned pos1, unsigned pos2);
#endif

#ifndef SETALL
#define SETALL
void set_all_values_list(link list, int value);
#endif


#ifndef INTERSECT
#define INTERSECT
link intersect_list(link list1, link list2);
#endif

#ifndef SUMALL
#define SUMALL
int sum_all_values_list(link list);
#endif

#ifndef SUMPARALLEL
#define SUMPARALLEL
link sum_parallel_values_list(link list, link list2);
#endif

#ifndef MAXVAL
#define MAXVAL
link max_value_list(link list);
#endif

#ifndef MINVAL
#define MINVAL
link min_value_list(link list);
#endif

#ifndef AVGVAL
#define AVGVAL
float avg_value_list(link list);
#endif

#ifndef SHIFTING
#define SHIFTING
link shift_list(link list, long offset, int pad_values);
link rotating_shift_list(link list, long offset);
#endif


//dumb functions
void print_list (link lista);
void print_list_articulate (link lista);