#ifndef _TEXT_H_
#define _TEXT_H_

#include "implementation.h"

text_t *create_text();

char *get_line( text_t *txt, int index );

void append_line( text_t *txt, char *new_line );

void insert_line( text_t *txt, int index, char *new_line );

void set_line( text_t *txt, int index, char *new_line );

char *delete_line( text_t *txt, int index );

int length_text( text_t *txt );

#endif
