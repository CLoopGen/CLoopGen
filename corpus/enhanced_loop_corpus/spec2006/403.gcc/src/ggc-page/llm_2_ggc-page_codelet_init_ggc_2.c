#include <stdio.h>

#include <inttypes.h>

extern size_t object_size_table[66];
extern unsigned int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (order = 0; order < (8 * 8); ++order) {
        size_t value = (size_t)1 << order;
        object_size_table[order] = value;
    }
}
