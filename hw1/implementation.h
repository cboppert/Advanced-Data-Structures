#ifndef _IMPLEMENTATION_H_
#define _IMPLEMENTATION_H_

#include "text_struct.c"

text_t *allocate_tree( void );
line_t *allocate_object( void );

int is_empty_text( text_t *txt );

line_t *find( text_t *txt, int index );

line_t *create_line( char *line );

void insert_into_empty_text( text_t *txt, int index, char *new_line );

#endif
