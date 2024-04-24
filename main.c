//Usage example

#include <stdio.h>
#include <stdlib.h>
#include "src/linked_list.h"

int main()
{
	link list, list2;
	/*list = generate_list(7);

	updateAtPos(list, 0, 4);
	print_list(list);

	destroyl(list);*/

	list = arr2list((int []){39,5,78,345,2,89}, 6);
	list2 = arr2list((int []){33,5,65,345,26,89}, 6);
	print_list(list);

	link list3 = intersect(list, list2);
	print_list(list3);

}