/* Author: Cody Boppert */

#include <stdlib.h>
#include "implementation.h"

text_t *allocate_tree( void )
{
   return (text_t *) malloc( sizeof( text_t ) );
}

object_t *allocate_object( void )
{
   return (object_t *) malloc( sizeof( object_t ) );
}
