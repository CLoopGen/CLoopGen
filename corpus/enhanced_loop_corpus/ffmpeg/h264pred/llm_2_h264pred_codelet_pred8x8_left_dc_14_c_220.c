#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access, we assume data is laid out consecutively in memory
    // We reinterpret the stride as 1 and access elements in a linear fashion
    ptrdiff_t base1 = -1;
    ptrdiff_t base2 = -1 + 4 * stride;
    for (i = 0; i < 4; i++) {
        dc0 += src[base1 + i];
        dc2 += src[base2 + i];
    }
}
