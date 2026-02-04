#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nop;
extern int *remap_axis_memory;
extern int **remap_axis;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive blocks of 64 elements, access every 128th element to create a strided pattern.
    // This simulates scenarios where data is accessed with a fixed stride larger than the natural width.
    int stride = 128;
    for (i = 0; i < nop; i++) {
        remap_axis[i] = remap_axis_memory + i * stride;
    }
}
