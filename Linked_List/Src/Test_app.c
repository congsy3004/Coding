#include <stdio.h>
#include "../Inc/linked_list.h"
#define LLIST_MAX_SIZE 
void main()
{
	llist_desc_t* new_list = llist_create();
	printf("new_list address = %p\n",new_list);
	printf("new_list->p_head = %p\n",new_list->p_head);
	printf("new_list->p_tail = %p\n",new_list->p_tail);
	printf("new_list->n_size = %d\n",new_list->node_size);
	return;
}