#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t **outFilter;
extern int *outFilterSize;
extern int dstW;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access with multiples of outFilterSize, 
    // we reorganize the access to be consecutive in memory.
    // We calculate base index and then access consecutive elements.
    int base = (dstW - 1) * (*outFilterSize) + i;
    for (i = 0; i < *outFilterSize; i++) {
        int idx = base + i;
        int16_t val = (*outFilter)[idx];
        (*outFilter)[idx + (*outFilterSize)] = val;
        (*outFilter)[idx + 2*(*outFilterSize)] = val;
        (*outFilter)[idx + 3*(*outFilterSize)] = val;
    }
}
