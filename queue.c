/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    /* Empty queue */
    if (q != NULL){
      q->head = NULL;
      /* size initialize to zero */
      q->size = 0;
      /* tail initialize to NULL */
      q->tail = NULL;
    }
    /* NULL queue*/
    /* if malloc returned NULL */
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    list_ele_t *pos;
    for (pos = q->head; pos != NULL;){
      list_ele_t *prev = pos;
      pos = pos->next;
      free(prev);
    }
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    if (q == NULL){
        return false;
    }
    newh = malloc(sizeof(list_ele_t));
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    if (newh != NULL){
        newh->next = q->head;
        newh->value = strdup(s);
        
        q->head = newh;
        q->size++;

        if (q->size == 1){
          q->tail = q->head;
        }
    }
    return newh != NULL;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    return false;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    if(q == NULL || q->size == 0)
        return false;
    /* You need to fix up this code. */
    q->head = q->head->next;
    /* remove one element, so decrease the size by 1*/
    q->size--;
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    return q != NULL ? q->size : 0;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    if (q != NULL && q->size){
          if (q->head->next == NULL){
            return;
          }
      list_ele_t *prev, *curr, *next;
      prev = q->head;
      curr = q->head->next;
      next = q->head->next->next;
      prev->next = NULL;
      curr->next = prev;
      while (next != NULL){
        prev = curr;
        curr = next;
        next = next->next;
        curr->next = prev;
      }
      q->tail = q->head;
      q->head = curr;
    }
}

