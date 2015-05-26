/* Author: Cody Boppert */

#include <stdlib.h>
#include "text_struct.c"
#include "implementation.h"

text_t *allocate_tree( void )
{
   return (text_t *) malloc( sizeof( text_t ) );
}

line_t *allocate_object( void )
{
   return (line_t *) malloc( sizeof( line_t ) );
}

line_t *find( text_t *txt, int index )
{
   text_t *tmp_text;

   // Empty Tree
   if ( txt->left == NULL )
   {
      return NULL;
   }

   else
   {
      tmp_text = txt;

      while ( txt->right != NULL )
      {
         if ( index < tmp_text->key )
         {
            tmp_text = tmp_text->left;
         }

         else
         {
            tmp_text = tmp_text->right;
         }
      }

      if (  index == tmp_text->key )
      {
         return (line_t *) tmp_text->left;
      }

      else
      {
         return NULL;
      }
   }
}
