//Usage example
//compile: gcc *.c src\*.c -o main && main.exe

#include <stdio.h>
#include <stdlib.h>
#include "src/linked_list.h"

int main()
{
	link list=NULL, list2 = NULL;
	/*list = generate_list(7);

	updateAtPos(list, 0, 4);
	print_list(list);

	destroyl(list);*/

	list = arr2list((int []){39,5,78,345,2,89}, 6);
	list2 = arr2list((int []){33,5,65,345,26,89}, 6);
	printf("Declaration of list1 and list2\n");
	print_list(list);
	print_list(list2);

	/*printf("\nIntersection of list1 and list2\n");
	link list3 = intersect_list(list, list2);
	print_list(list3);

	printf("\nReverse of list3\n");
	list3 = reverse_list(&list3);
	print_list(list3);

	printf("\nPlaying with NULL list4\n");
	*/link list4 = NULL;/*
	print_list(list4);
	list4 =reverse_list(&list4);
	print_list(list4);
	append_val(&list4, 5);
	print_list(list4);
	destroy_list(&list4);
	print_list(list4);*/
	
	printf("\nConcatenation of list1 and list2\n");
	list4 = concat_list(list, list2);
	print_list(list4);
	link list6 = sublist(list4, 5, 7);
	printf("List 6:\n");
	print_list(list6);
	printf("\nMerge sort of list4\n");
	link list5 = mergesort_list(list4);
	print_list(list5);
	printf("\nReverse the shellsorted list5 and print with articulate function\n");
	list5 = reverse_list(&list5);
	print_list(list5);

	printf("\nShuffle list5\n");
	list5 = shuffle_list(list5);
	print_list(list5);

	printf("\nResort list\n");
	list5= mergesort_list(list5);
	print_list(list5);
}