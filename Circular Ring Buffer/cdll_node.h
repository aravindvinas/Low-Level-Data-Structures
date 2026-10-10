#ifndef CDLL_NODE_H
#define CDLL_NODE_H

/*
**************************************************************
* File     : cdll_node.h
* Desc     : Header for Circular Doubly Linked List Node
* Author   : ap
**************************************************************
*/

/*
**************************************************************
* Requirements  : Circular Doubly Linked List Node
**************************************************************
*/

/*
**************************************************************
* INCLUDES
**************************************************************
*/
#include <stddef.h>
#include <stdbool.h>

/*
**************************************************************
* MACROS
**************************************************************
*/
#define CDLL_INIT(head) { .prev = &(head), .next = &(head)}

#define CDLL_CONTAINER_OF(m_ptr, c_t, m) \
    ((c_t *)( (char *)(1 ? (m_ptr) : &((c_t *)0)->m) - offsetof(c_t, m) ))

#define CDLL_ENTRY(m_ptr, c_t, m)       CDLL_CONTAINER_OF(m_ptr, c_t, m)
#define CDLL_FIRST_ENTRY(head, c_t, m) (!cdll_is_empty(head) ? CDLL_CONTAINER_OF( ( (head)->next ), c_t, m) : NULL)
#define CDLL_LAST_ENTRY(head, c_t, m)  (!cdll_is_empty(head) ? CDLL_CONTAINER_OF( ( (head)->prev ), c_t, m) : NULL)

/*
**************************************************************
* USER DATA TYPES
**************************************************************
*/
struct cdll_node{
    struct cdll_node *prev;
    struct cdll_node *next;
};

typedef struct cdll_node cdll_node_t;

/*
**************************************************************
* PUBLIC API 
**************************************************************
*/
void cdll_init(cdll_node_t *);
void cdll_add(cdll_node_t *, cdll_node_t *);
void cdll_add_tail(cdll_node_t *, cdll_node_t *);
void cdll_del(cdll_node_t *);
bool cdll_is_empty(const cdll_node_t *);

#endif /* CDLL_NODE_H */
