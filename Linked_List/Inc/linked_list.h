/******************************************************************************
 * @file           : linked_list.h
 * @brief          : Brief description
 * @author         : Your Name
 * @date           : 09-Jul-2025
 ******************************************************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------
 *                           << Include Files >>                                   
 * -------------------------------------------------------------------------*/
#include "llist_type.h"
#include <stdint.h>

/* -------------------------------------------------------------------------
 *                           << Exported Types >>                                   
 * -------------------------------------------------------------------------*/
enum llist_retval
{
	LLIST_RET_OK, // return OK value
	LLIST_RET_NOK, // return OK value
	LLIST_RET_TRUE, // return OK value
	LLIST_RET_FALSE, // return OK value
};
/** 
 * @brief This struct describes a linked list 
 */
struct llist_desc
{
	llist_node_t* p_head;
	llist_node_t* p_tail;
	uint32_t 	  node_size;
	llist_handler_t llist_handler_cb;
};
/* -------------------------------------------------------------------------
 *                           << Exported Constants >>                                   
 * -------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------
 *                           << Exported Macros >>                                   
 * -------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------
 *                           << Exported Functions >>                                   
 * -------------------------------------------------------------------------*/
llist_desc_t* llist_create();
llist_retval_t llist_destroy( llist_desc_t* list );
llist_retval_t llist_init( llist_desc_t* list );
llist_retval_t llist_is_empty( llist_desc_t* list );
uint32_t	  llist_get_size( llist_desc_t* list );
llist_retval_t llist_ins_head( llist_desc_t* list, void* data );
llist_retval_t llist_ins_tail( llist_desc_t* list, void* data );
llist_retval_t llist_pop_head( llist_desc_t* list );
llist_retval_t llist_pop_tail( llist_desc_t* list );

llist_retval_t llist_ins_after(llist_node_t* node, void* data );
llist_retval_t llist_find(llist_desc_t* list, void* dest, void* find );

#ifdef __cplusplus
}
#endif

#endif /* LINKED_LIST_H */

/******************************** END OF FILE ********************************/