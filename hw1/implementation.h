#ifndef _IMPLEMENTATION_H_
#define _IMPLEMENTATION_H_

#include "text_struct.c"

text_t *allocate_tree( void );
line_t *allocate_object( void );

line_t *find( text_t *txt, int index );

#endif
