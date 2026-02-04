#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *speech;
extern int subframe_size;
extern int temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in forward order, then complete in second pass)
    int stride = 2;
    for (i = 0; i < subframe_size; i += stride)
        speech[i] = (speech[i] * temp + 16384) >> 15;
    for (i = 1; i < subframe_size; i += stride)
        speech[i] = (speech[i] * temp + 16384) >> 15;
}
