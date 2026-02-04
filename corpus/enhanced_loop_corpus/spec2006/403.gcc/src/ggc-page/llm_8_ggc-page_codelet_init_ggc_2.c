#include <stdio.h>

#include <inttypes.h>

extern size_t object_size_table[66];
extern unsigned int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (order = 0; order < (8 * 8); ++order) {
        size_t power = 1;
        for (unsigned int i = 0; i < order; ++i) {
            power *= 2;
        }
        object_size_table[order] = power;
    }
}
