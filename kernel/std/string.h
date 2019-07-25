#include "types.h"

#ifndef NIMGOS_STRINGS_H
#define NIMGOS_STRINGS_H

size_t strlen(const char *str);
void strcat(char *dest, const char *src);
int8 strcmp(const char *str1, const char *str2);
char *utoa(uint32 value, uint8 base);
char tolower(char c);
char toupper(char c);
void strlwr(char *str);
void strupr(char *str);

#endif //NIMGOS_STRINGS_H
