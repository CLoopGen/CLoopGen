#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern  uint8_t *scan;
extern int16_t **ext;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of sequential i, access with a stride of 2 (unroll-like pattern)
    // Process even indices first, then odd, using two separate loops
    for (i = 0; i < 64; i += 2)
        dst[scan[i]] = (*ext)[i];
    for (i = 1; i < 64; i += 2)
        dst[scan[i]] = (*ext)[i];
}
