#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 d1;
extern int32 d2;
extern int32 elemsize;
extern char **ref;
extern char *mem;
extern int32 i;
extern int32 offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access with varying offset, we write consecutive pointers into ref[]
    // assuming mem is a contiguous block large enough for d1 pointers worth of data.
    int32 stride = d2 * elemsize;
    for (i = 0, offset = 0; i < d1; i++, offset += stride)
        ref[i] = mem + i * stride;
}
