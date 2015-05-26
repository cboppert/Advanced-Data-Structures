//Author: Cody Boppert

#ifndef _STACK_H_
#define _STACK_H_

#include "text_struct.c"

// Just a wrapper so I can easily use this stack for a different type of object in the future if I want
typedef struct st_o_t
{
   text_t *obj;
} stack_obj_t;

typedef struct st_n_t
{
   struct st_n_t *previous;
   stack_obj_t *obj;

} stack_node_t;

void put( stack_node_t *stack, stack_obj_t *obj );

stack_obj_t *pop( stack_node_t *stack );
#endif
