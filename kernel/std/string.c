#include "string.h"

void *memcpy(void *dest, const void *src, size_t count)
{
	char *dest_c = (char*)dest;
	char *src_c  = (char*)src;
	size_t i;

	for (i = 0; i < count; i++)
		*(dest_c + i) = *(src_c + i);

	return dest;
}

void *memmove(void *dest, const void *src, size_t count)
{
	char *dest_c = (char*)dest;
	char *src_c  = (char*)src;
	size_t i;

	if (src > dest) {
		for (i = 0; i < count; i++)
			*(dest_c + i) = *(src_c + i);
	} else {
		for (i = count-1; i >= 0; i--)
			*(dest_c + i) = *(src_c + i);
	}

	return dest;
}

void *memset(void *dest, int val, size_t count)
{
	char *dest_c = (char*)dest; 
	char val_c   = (char)val; 
	size_t i;

	for (i = 0; i < count; i++)
		*(dest_c + i) = val_c;

	return dest;
}

void *memset_w(void *dest, int val, size_t count)
{
	u16 *dest_w = (u16*)dest; 
	u16 val_w   = (u16)val; 
	size_t i;

	for (i = 0; i < count; i++)
		*(dest_w + i) = val_w;

	return dest;
}

size_t strlen(const char *str)
{
	size_t len = 0;

	while (*str != '\0') {
		len++;
		str++;
	}

    return len;
}

char *strcpy(char *dest, const char *src){

	int i;

	for (i = 0; *(src+i) != '\0'; i++)
		*(dest + i) = *(src + i);

	*(dest + i) = '\0';

	return dest;
}

char *strcpy_n(char *dest, const char *src, size_t max_len)
{
	int i;

	for (i = 0; i < max_len - 1 && *(src + i) != '\0'; i++)
		*(dest + i) = *(src + i);

	*(dest + i) = '\0';

	return dest;
}

char *strcat(char *dest, const char *src)
{
	return strcpy(dest + strlen(dest), src);
}

int strcmp(const char *s1, const char *s2)
{
	int i;
	for (i = 0; true; i++){
		if (s1[i] == '\0' && s2[i] == '\0')
			return 0;

		if (s1[i] != s2[i])
			return s1[i] - s2[i];
	}
}

char char2lower(char c)
{
	if ('A' <= c && c <= 'Z')
		return c + ' ';
	else 
		return c;
}

char char2upper(char c)
{
	if ('a' <= c && c <= 'z')
		return c - ' ';
	else 
		return c;
}

void str2lower(char *str)
{
	u32 length = strlen(str);

	u32 i = 0;
	for(; i < length; i++)
		str[i] = char2lower(str[i]);
}

void str2upper(char *str)
{
	u32 length = strlen(str);
	
	u32 i = 0;
	for(; i < length; i++)
		str[i] = char2upper(str[i]);
}