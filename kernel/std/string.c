#include "string.h"

size_t strlen(const char *str) {

    const char *end = str;
    while(*end++) ;
    return end - str;

}

void strcat(char *dest, const char *src) {

    char *tmp = dest;
    while (*dest) dest++;
    while ((*dest++ = *src++) != NULL) ;

}

int8 strcmp(const char *str1, const char *str2) {

    char a, b;

    do {
        a = *str1++;
        b = *str2++;
        if (a != b)
            return (a < b ? -1 : 1);
    } while (a && b);

    return 0;

}

char *utoa(uint32 value, uint8 base) {

    static char buf[11] = { 0 };
    uint8 i = 10;

    do {
        i--;
        buf[i] = "0123456789ABCDEF"[value % base];
        value /= 10;
    } while (value);

    return buf + i;

}

char tolower(char c) {

    if ('A' <= c && c <= 'Z')
        return c += ' ';
    return c;

}

char toupper(char c) {

    if('a' <= c && c <= 'z')
        c -= ' ';
    return c;

}

void strlwr(char *str) {

    while(*str) tolower(*str++);

}

void strupr(char *str) {

    while(*str) toupper(*str++);

}