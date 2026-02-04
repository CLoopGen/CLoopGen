#include <stdio.h>

#include <inttypes.h>

extern size_t object_size_table[66];
extern unsigned int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp[64];
    for (order = 0; order < (8 * 8); ++order) {
        temp[order] = (size_t)1 << order;
    }
    for (order = 0; order < (8 * 8); ++order) {
        object_size_table[order] = temp[order];
    }
}
