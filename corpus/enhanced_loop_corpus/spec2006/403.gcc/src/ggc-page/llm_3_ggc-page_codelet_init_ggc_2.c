#include <stdio.h>

#include <inttypes.h>

extern size_t object_size_table[66];
extern unsigned int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Strided memory access: write every 2nd element first, then fill in gaps
    // This creates a non-consecutive access pattern with stride 2
    for (order = 0; order < (8 * 8); order += 2)
        object_size_table[order] = (size_t)1 << order;

    for (order = 1; order < (8 * 8); order += 2)
        object_size_table[order] = (size_t)1 << order;
}
