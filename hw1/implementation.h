#ifndef _IMPLEMENTATION_H_
#define _IMPLEMENTATION_H_

typedef struct tree_node {
   int key;

   enum { RED, BLACK } color;

   struct tree_node *left;
   struct tree_node *right;
} text_t;

typedef struct leaf {
   char *line;
} object_t;

text_t *allocate_tree( void );
object_t *allocate_object( void );

#endif
