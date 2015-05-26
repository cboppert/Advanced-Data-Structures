//Author: Cody Boppert

#include <stdio.h>
#include <stdlib.h>
#include "text.h"
#include "implementation.h"

text_t *create_text()
{
   text_t *tmp_text = allocate_tree();
   tmp_text->left = NULL;

   return tmp_text;
}

char *get_line( text_t *txt, int index )
{

   return NULL;
}

void append_line( text_t *txt, char *new_line )
{

}

void insert_line( text_t *txt, int index, char *new_line )
{

}

void set_line( text_t *txt, int index, char *new_line )
{

}

char *delete_line( text_t *txt, int index )
{

   return NULL;
}

int length_text( text_t *txt )
{

   return 0;
}
