// Author: Cody Boppert

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
