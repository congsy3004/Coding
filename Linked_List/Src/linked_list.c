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
#include "llist_type.h"
#include "stdlib.h"

/* -------------------------------------------------------------------------
 *                           << Private Types >>                                   
 * -------------------------------------------------------------------------*/
// Define a function pointer type for freeing a node
typedef llist_retval_t (*fnp_free_node_t)(llist_node_t*);
/** 
 @brief This struct describes a node of the linked list 
 @param data pointer to the data of node 
 @param p_next pointer storing the address of the next node 
 */
 typedef struct llist_node
{
	void* data;
	llist_node_t* p_next;
};

typedef struct  llist_handler
{
	fnp_free_node_t free_node_cb;
};

/** 
 * @brief This struct describes a linked list 
 */
typedef struct llist_desc
{
	llist_node_t* p_head;
	llist_node_t* p_tail;
	uint32_t 	  size;
	llist_handler_t llist_handler_cb
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
static llist_retval_t free_node(llist_node_t* node);
/* -------------------------------------------------------------------------
 *                           << Private Functions Definitions >>                                   
 * -------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------
 *                           << Public Functions Definitions >>                                   
 * -------------------------------------------------------------------------*/
llist_desc_t* llist_create(uint32_t size)
{
	llist_desc_t* new_list = malloc(size);
	new_list->p_head = NULL;
	new_list->p_tail = NULL;
	new_list->size = size;
	new_list->llist_handler_cb.free_node_cb = free_node;

	return new_list;
}

llist_retval_t llist_is_empty( llist_desc_t* list )
{
	llist_retval_t retvat = LLIST_RET_TRUE;
	if ( list->p_head != NULL && list->p_tail != NULL )
	{
		retvat = LLIST_RET_FALSE;
	}
	return retvat;
}

llist_retval_t llist_ins_head( llist_desc_t* list, void* data )
{
	llist_node_t* new_node = malloc(sizeof(llist_node_t));
	if ( LLIST_RET_TRUE == llist_is_empty(list) )
	{
		list->p_tail = new_node;
	}
	new_node->data =  data;
	new_node->p_next = list->p_head;
	list->p_head = new_node;
}

llist_retval_t llist_ins_tail( llist_desc_t* list, void* data )
{
	llist_node_t* new_node = malloc(sizeof(llist_node_t));
	if ( LLIST_RET_TRUE == llist_is_empty(list) )
	{
		list->p_head = new_node;
	}
	new_node->data = data;
	new_node->p_next = NULL;
	list->p_tail->p_next = new_node;
	list->p_tail = new_node;
}

#if 0
llist_retva_t llist_destroy( llist_desc_t* list );
llist_retva_t llist_init( llist_desc_t* list );
uint32_t	  llist_get_size( llist_desc_t* list );
llist_retva_t llist_pop_head( llist_desc_t* list );
llist_retva_t llist_pop_tail( llist_desc_t* list );

llist_retva_t llist_ins_after(llist_node_t* node, void* data );
llist_retva_t llist_find(llist_desc_t* list, void* dest, void* find );
#endif 

/******************************** END OF FILE ********************************/