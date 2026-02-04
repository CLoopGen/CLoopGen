#include <stdio.h>

#include <inttypes.h>

extern size_t object_size_table[66];
extern unsigned int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t accumulator = 1;
    for (order = 0; order < (8 * 8); ++order) {
        object_size_table[order] = accumulator;
        accumulator <<= 1;
    }
}
