/* Author: Cody Boppert */

#include <stdlib.h>
#include "text_struct.c"
#include "implementation.h"

text_t *get_node( void );
void return_node( text_t *txt );

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

// Intermediate layer for dealing with memory allocation
// Adopted from Professor Peter Brass's Advanced Data Structures Text section 1.4
#define BLOCKSIZE 10000
text_t *current_block = NULL;
int size_left;
text_t *free_list = NULL;

text_t *get_node( void )
{
   text_t *tmp;
   if ( free_list != NULL )
   {
      tmp = free_list;
      free_list = free_list->left;
   }

   else
   {
      if ( current_block == NULL || size_left == 0 )
      {
         current_block = ( text_t * ) malloc( BLOCKSIZE * sizeof( text_t ) );
         size_left = BLOCKSIZE;
      }
      tmp = current_block++;
      size_left -= 1;
   }

   tmp->left = NULL;
   tmp->right = NULL;
   tmp->key = 0;
   tmp->color = BLACK;
   tmp->valid = 1;

   return tmp;
}
