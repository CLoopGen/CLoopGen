#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then odd indices)
    int stride = 2;
    for (i = 0; i < count; i += stride)
        pal[i] &= 16777215;
    for (i = 1; i < count; i += stride)
        pal[i] &= 16777215;
}
