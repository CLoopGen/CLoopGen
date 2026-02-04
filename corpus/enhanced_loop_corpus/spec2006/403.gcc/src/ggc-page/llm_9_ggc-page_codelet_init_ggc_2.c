#include <stdio.h>

#include <inttypes.h>

extern size_t object_size_table[66];
extern unsigned int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const unsigned int limit = 32;
    for (order = 0; order < limit; ++order) {
        object_size_table[order] = (size_t)1 << (order << 1);
    }
    for (; order < (8 * 8); ++order) {
        object_size_table[order] = 0;
    }
}
