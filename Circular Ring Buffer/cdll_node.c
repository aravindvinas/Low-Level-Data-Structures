/*
**************************************************************
* File     : cdll_node.c
* Desc     : Circular Doubly Linked List Node Implementation
* Author   : ap
**************************************************************
*/

/*
**************************************************************
* INCLUDES
**************************************************************
*/
#include "cdll_node.h"

/*
**************************************************************
* MACROS
**************************************************************
*/

/*
**************************************************************
* PRIVATE API
**************************************************************
*/
static inline void __cdll_add(cdll_node_t *new_node, cdll_node_t *prev_node, cdll_node_t *next_node)
{
    /* Update the prev and next of new_node */
    new_node->prev = prev_node;
    new_node->next = next_node;
    
    /* Update the prev of next_node to point to new_node */
    next_node->prev = new_node;
    
    /* Update the next of the prev_node to the new_node */
    prev_node->next = new_node;
}

/*
**************************************************************
* PUBLIC API
**************************************************************
*/

/*
**************************************************************
* FUNC      : void cdll_init(cdll_node *head)
* DESC      : Intialize the cdll head node
* Return    : None
**************************************************************
*/
void cdll_init(cdll_node_t *head)
{
    head->prev = head;
    head->next = head;
}

/*
**************************************************************
* FUNC      : void cdll_add_node(cdll_node_t *new_node, cdll_node_t *head)
* DESC      : Add a new node
* Return    : None
**************************************************************
*/
void cdll_add(cdll_node_t *new_node, cdll_node_t *head)
{
    __cdll_add(new_node, head, head->next);
}

/*
**************************************************************
* FUNC      : void cdll_add_node_tail(cdll_node_t *new_node, cdll_node_t *head)
* DESC      : Add a new node to tail
* Return    : None
**************************************************************
*/
void cdll_add_tail(cdll_node_t *new_node, cdll_node_t *head)
{
    __cdll_add(new_node, head->prev, head);
}

/*
**************************************************************
* FUNC      : void cdll_del(cdll_node_t *new_node)
* DESC      : Delete a node
* Return    : None
**************************************************************
*/
void cdll_del(cdll_node_t *node)
{
   node->prev->next = node->next; 
   node->next->prev = node->prev;

   node->prev = NULL;
   node->next = NULL;
}

/*
**************************************************************
* FUNC      : bool cdll_is_empty(cdll_node_t *head)
* DESC      : Check if the list is empty
* Return    : True (0b1) / False (0b0)
**************************************************************
*/
bool cdll_is_empty(const cdll_node_t *head)
{
   return (head->next == head);
}
