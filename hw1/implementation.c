/* Author: Cody Boppert */

#include <stdlib.h>
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
   return NULL;
}
