#include "array.h"

array array_place(void *data, u32 max_size) {

    array arr;
    arr.data    = (container_item)data;
    arr.max_size = max_size;
    arr.size     = 0;

    return arr;
}

bool array_add(array *arr, container_item item) {

    if (arr->size >= arr->max_size)
		return false;

	arr->data[arr->size++] = item;
    return true;
}

container_item array_get(array *arr, u32 index) {
    return arr->data[index];
}

void array_del(array *arr, u32 index) {

    if (index == arr->size - 1) {
        arr->size--;
        return;
    }

    int j = index;
    for (; j < arr->size - 1; j++) {
        arr->data[j] = arr->data[j+1];
    }

    arr->size--;
	
    return;
}