//Author: Cody Boppert

#include <stdio.h>
#include <stdlib.h>
#include "text.h"
#include "implementation.h"

text_t *create_text()
{
   text_t *tmp_text = allocate_tree();
   tmp_text->left = NULL;
   tmp_text->color = BLACK;

   return tmp_text;
}

char *get_line( text_t *txt, int index )
{


   return NULL;
}

void append_line( text_t *txt, char *new_line )
{
   insert_line( txt, length_text( txt ) + 1, new_line );
}

void insert_line( text_t *txt, int index, char *new_line )
{

   if ( is_empty_text( txt ) )
   {
      insert_into_empty_text( txt, index, new_line );
   }
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
   if ( txt->left == NULL )
   {
      return 0;
   }

   if ( txt->right == NULL )
   {
      return 1;
   }

   else
   {
      text_t *tmp_txt = txt;
      while ( txt->right != NULL )
      {
         tmp_txt = txt->right;
      }
      return tmp_txt->key;
   }
}
