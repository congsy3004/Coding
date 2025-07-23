/******************************************************************************
 * @file           : Untitled-1
 * @brief          : Brief description
 * 
 * Detailed description of the file's purpose and functionality.
 *
 * @author         : Your Name
 * @date           : 09-Jul-2025
 ******************************************************************************/

/* -------------------------------------------------------------------------
 *                           << Include Files >>                                   
 * -------------------------------------------------------------------------*/
#include "linked_list.h"
#include "stdlib.h"
#include <stdio.h>

/* -------------------------------------------------------------------------
 *                           << Private Types >>                                   
 * -------------------------------------------------------------------------*/
typedef struct ll_node
{
	void* p_data;
	struct ll_node* p_next;
}ll_node_t;

struct ll_list
{
	ll_node_t*	p_head;
	ll_node_t*	p_tail;
	uint32_t	mem_cnt;
};

struct ll_iterator
{
	ll_node_t* current_node;
};

/* -------------------------------------------------------------------------
 *                           << Private Variables >>                                   
 * -------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------
 *                           << Private Constants >>                                   
 * -------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------
 *                           << Private Macros >>                                   
 * -------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------
 *                           << Private Functions Declarations >>                                   
 * -------------------------------------------------------------------------*/
static ll_retval_t free_node(ll_node_t* node);
/* -------------------------------------------------------------------------
 *                           << Private Functions Definitions >>                                   
 * -------------------------------------------------------------------------*/
ll_retval_t free_node(ll_node_t* node)
{
	/**< Check if the input node is valid */
	if (!node){
		return LL_RET_NOK;
	}
	else{
		free(node);
	}
	return LL_RET_OK;
}
/* -------------------------------------------------------------------------
 *                           << Public Functions Definitions >>                                   
 * -------------------------------------------------------------------------*/
ll_list_t* ll_create()
{
	ll_list_t* new_list = malloc(sizeof(ll_list_t));
	if (new_list)
	{
		new_list->p_head = NULL;
		new_list->p_tail = NULL;
		new_list->mem_cnt = 0;
	}
	return new_list;
}
ll_retval_t ll_destroy( ll_list_t* list )
{
	/**< Check if the input list is valid */
	if (!list)
	{
		return LL_RET_NOK;
	}
	else{
		
		ll_node_t* cur_node = list->p_head; /**<Start from the head of the list */
		ll_node_t* next_node = NULL; /**< Store the pointer to the next node */
		while (cur_node) /**< Stop when passing over the tail */
		{
			next_node = cur_node->p_next; /**< Fetch the next node before the cur_node is freed */
			if( LL_RET_OK == free_node(cur_node) ) /**< If the cur_node is freed  */
			{
				list->mem_cnt--; 
				cur_node = next_node;
			}
			else{ /**< If the cur_node hasn't been freed successfully */
				return LL_RET_NOK;
				break;
			}
		}
		
		free(list);
	}
	return LL_RET_OK;
}

ll_retval_t ll_is_empty( ll_list_t* list )
{
	ll_retval_t retvat = LL_RET_TRUE;
	if ( list->mem_cnt > 0 )
	{
		retvat = LL_RET_FALSE;
	}
	return retvat;
}

ll_retval_t ll_ins_head( ll_list_t* list, void* data )
{
	ll_node_t* new_node = malloc(sizeof(ll_node_t));
	if ( !new_node ) // Check if new_node == NULL
	{
		return LL_RET_NOK;
	}
	else
	{
		new_node->p_data = data;
		new_node->p_next = list->p_head; // Connect the new_node to the current head
		list->p_head = new_node;
		if ( !(list->mem_cnt > 0) ) // If the list is empty
		{
			list->p_tail = list->p_head; //Set the new _node as the tail too
		}
		list->mem_cnt++;
		return LL_RET_OK;
	}

}

ll_retval_t ll_ins_tail( ll_list_t* list, void* data )
{
	ll_node_t* new_node = malloc(sizeof(ll_node_t));
	if ( !new_node )
	{
		return LL_RET_NOK;
	}
	else
	{
		new_node->p_data = data;
		new_node->p_next = NULL;
		if ( !(list->mem_cnt > 0) )
		{
			list->p_head = new_node;
			list->p_tail = new_node;
		}
		else{
			list->p_tail->p_next = new_node;
			list->p_tail = new_node;
		}
		list->mem_cnt++;
	}

	return LL_RET_OK;
}

void*  ll_get_headval( ll_list_t* list )
{
	if (!list || !(list->p_head) ) /**< Check if the list or the head node is NULL */
	{
		return NULL;
	}
	else{
		return list->p_head->p_data;
	}
}

void*  ll_get_tailval( ll_list_t* list )
{
	if (!list || !(list->p_tail) ) /**< Check if the list or the head node is NULL */
	{
		return NULL;
	}
	else{
		return list->p_tail->p_data;
	}
}

ll_iterator_t* ll_iterator_create(const ll_list_t* list)
{
	ll_iterator_t* ite = NULL;
	if( list ){
		ite = malloc(sizeof(ll_iterator_t));
		if (ite)
		{
			ite->current_node = list->p_head;
		}
		
	}
	return ite;
}

void ll_iterator_destroy(ll_iterator_t **ite)
{
    if (ite && *ite)
    {
        free(*ite);
        *ite = NULL;
    }
}

void* ll_iterator_getval(const ll_iterator_t* ite)
{
	if ( (!ite) || !(ite->current_node) ) /**< Check if the ite or the current node is NULL */
	{
		return NULL;
	}
	else{
		return ite->current_node->p_data;
	}
}

ll_retval_t ll_iterator_next(ll_iterator_t* ite)
{
	if (!ite)
	{
		return LL_RET_NOK;
	}
	else{
		ite->current_node = ite->current_node->p_next;
		if ( !(ite->current_node) )
		{
			return LL_RET_NULL;
		}
	}
	return LL_RET_OK;
}
uint32_t ll_list_count( ll_list_t* list )
{
	if ( !list )
	{
		return 0;
	}
	else{
		return list->mem_cnt;
	}
}

#if 0
ll_retva_t ll_pop_head( ll_list_t* list );
ll_retva_t ll_pop_tail( ll_list_t* list );

ll_retva_t ll_find(ll_list_t* list, void* dest, void* find );
#endif 
void print_list(ll_list_t* list);
void main()
{
	uint8_t array[] = {1,2,3,4,5,6,7};
	uint8_t array1[] = {8,9,10,11,12,13};
	char string1[] = {'H','e','l','l','o','_'};
	char string2[] = {'W','o','r','l','d'};
	ll_list_t* list1 = ll_create();
	if ( list1  )
	{
		printf("a new list has been created at %p\n",list1);
		printf("sizeof string1 =  %d\n",sizeof(string1));
		printf("sizeof string2 =  %d\n",sizeof(string2));
	}
	else
	{
		printf("FAILED to create a new list\n");
	}
	
	for (size_t i = 0; i < sizeof(string1); i++)
	{
		ll_ins_tail(list1, (void*)&string1[i]);
	}
	
	print_list(list1);
	
	for (size_t i = 0; i < sizeof(string2); i++)
	{
		ll_ins_tail(list1, (void*)&string2[i]);
	}
	
	print_list(list1);
	return;
}

void print_list(ll_list_t* list)
{
	printf("The head is %c\n",*((uint8_t*)ll_get_headval(list)));
	printf("The tail is %c\n",*((uint8_t*)ll_get_tailval(list)));
	printf("The mem_cnt is %d\n",(uint8_t)ll_list_count(list));
	ll_iterator_t* ite = ll_iterator_create(list);
	if (!ite)
	{
		return;
	}
	else{
		do
		{
			printf("%c",*((char*)ll_iterator_getval(ite)));
			
		} while( LL_RET_NULL != ll_iterator_next(ite) );
	}
	ll_iterator_destroy(&ite);
	if ( !ite )
	{
		printf(" \nDestroyed the iterator \n");
	}
	

}
/******************************** END OF FILE ********************************/