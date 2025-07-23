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
#include <stdint.h>
/* -------------------------------------------------------------------------
*                           << Exported Types >>                                   
* -------------------------------------------------------------------------*/
typedef enum 
{
	LL_RET_NULL,
	LL_RET_OK, /**< the operation was succesful */
	LL_RET_NOK, /**< the operation failed */
	LL_RET_TRUE, /**< the operation return the true result for question-liked function */
	LL_RET_FALSE /**< the operation return the false result for question-liked function */
}ll_retval_t;

typedef struct ll_list ll_list_t;
typedef struct ll_iterator ll_iterator_t;







/* -------------------------------------------------------------------------
*                           << Exported Constants >>                                   
* -------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------
*                           << Exported Macros >>                                   
* -------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------
 *                           << Exported Functions >>                                   
 * -------------------------------------------------------------------------*/
ll_list_t*  ll_create();
ll_retval_t ll_destroy( ll_list_t* list );
ll_retval_t ll_is_empty( ll_list_t* list );
uint32_t	ll_list_count( ll_list_t* list );
void*  ll_get_headval( ll_list_t* list );
void*  ll_get_tailval( ll_list_t* list );
ll_retval_t ll_ins_head( ll_list_t* list, void* data );
ll_retval_t ll_ins_tail( ll_list_t* list, void* data );
ll_retval_t ll_pop_head( ll_list_t* list );
ll_retval_t ll_pop_tail( ll_list_t* list );
ll_retval_t ll_find(ll_list_t* list, void* dest, void* find );

ll_iterator_t* ll_iterator_create(const ll_list_t* list);
void ll_iterator_destroy(ll_iterator_t** ite);
void* ll_iterator_getval(const ll_iterator_t* ite);
ll_retval_t ll_iterator_next(ll_iterator_t* ite);

#ifdef __cplusplus
}
#endif

#endif /* LINKED_LIST_H */

/******************************** END OF FILE ********************************/