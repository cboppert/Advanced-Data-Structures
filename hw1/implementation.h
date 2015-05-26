#ifndef _IMPLEMENTATION_H_
#define _IMPLEMENTATION_H_

//Object definitions
typedef struct tree_node {
   int key;

   enum { RED, BLACK } color;

   struct tree_node *left;
   struct tree_node *right;
} text_t;

typedef struct leaf {
   char *line;
} line_t;

text_t *allocate_tree( void );
line_t *allocate_object( void );

line_t *find( text_t *txt, int index );

#endif
