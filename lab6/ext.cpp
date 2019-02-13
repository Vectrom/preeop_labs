#include "ext.h"
#include <iostream>

void init(Ext *struct_pointer) {
    struct_pointer->data = new int[5];
    struct_pointer->data_size = 0;
    struct_pointer->capacity = 5;
    struct_pointer->function_pointer = linear_size;
}

void initWithSizeAndPolicy(Ext *struct_pointer, int size, int (*function_pointer)(int)) {
    struct_pointer->data = new int[size];
    struct_pointer->data_size = 0;
    struct_pointer->capacity = size;
    struct_pointer->function_pointer = function_pointer;
}

int size(Ext *struct_pointer) {
    return struct_pointer->data_size;
}

int capacity(Ext *struct_pointer) {
    return struct_pointer->capacity;
}

void insert(Ext *struct_pointer, int elem) {
    (struct_pointer->data)[struct_pointer->data_size] = elem;
    (struct_pointer->data_size)++;

    if(struct_pointer->data_size >= struct_pointer->capacity) {
        int new_size = struct_pointer->function_pointer(struct_pointer->data_size);

        int *new_data = new int[new_size];

        for(int i = 0; i < struct_pointer-> data_size; i++)
            new_data[i] = (struct_pointer->data)[i];
        
        delete[] struct_pointer->data;
        struct_pointer->data = new_data;
        struct_pointer->capacity = new_size;
    }

}

int at(Ext *struct_pointer, int index) {
    return (struct_pointer->data)[index];
}

void clear(Ext *struct_pointer) {
    delete[] struct_pointer->data;
}

int linear_size(int old_size) {
	return old_size+5;
}