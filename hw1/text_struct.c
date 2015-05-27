// Author: Cody Boppert

#ifndef _TEXT_STRUCT_C_
#define _TEXT_STRUCT_C_

//Object definitions
typedef struct tree_node {
   int key;
   //Valid is set to 1 when getting a node and to 0 when returning
   int valid;

   enum { RED, BLACK } color;

   // left may also point to an object if a leaf node
   // and the next item in free_list if deleted
   struct tree_node *left;
   struct tree_node *right;
} text_t;

typedef struct leaf {
   char *line;
} line_t;

#endif
