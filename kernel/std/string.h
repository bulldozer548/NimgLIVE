/* ---------------------------------------------------
* Jonix - C Standard Library
*
* string.h
*
* Author(s): Jonathan Haigh
* Last edited by: Jonathan Haigh
* --------------------------------------------------*/

#ifndef _STRING_H
#define _STRING_H

#include "types.h"

void *   memcpy(void *dest, const void *src, size_t count);
void *   memmove(void *dest, const void *src, size_t count);
void *   memset(void *dest, int val, size_t count);
void *   memset_w(void *dest, int val, size_t count);

size_t   strlen(const char *str);
char *   strcpy(char *dest, const char *src);
char *   strcpy_n(char *dest, const char *src, size_t max_len);
char *   strcat(char *dest, const char *src);
int strcmp(const char *s1, const char *s2);

#endif
