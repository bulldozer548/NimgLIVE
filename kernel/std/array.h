/* ---------------------------------------------------
* Jonix
*
* oarray.h
*
* Author(s): Jonathan Haigh
* Last edited by: Jonathan Haigh
* --------------------------------------------------*/

#ifndef _OARRAY_H
#define _OARRAY_H

#include "container_item.h"
#include "types.h"

typedef struct {
    container_item *data;
    u32    max_size;
    u32    size;
} array;


array			array_place(void *data, u32 max_size);
bool			array_add(array *arr, container_item item);
container_item	array_get(array *arr, u32 index);
void			array_del(array *arr, u32 index);

#endif
