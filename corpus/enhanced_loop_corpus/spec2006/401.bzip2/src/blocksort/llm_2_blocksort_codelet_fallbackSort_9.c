#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of accessing strided indices, accumulate operations on consecutive bhtab elements
    UInt32 index_base;
    for (i = 0; i < 32; i++) {
        index_base = (nblock + 2 * i) >> 5;
        bhtab[index_base] |= (1 << ((nblock + 2 * i) & 31));
        bhtab[index_base] &= ~(1 << (((nblock + 2 * i + 1)) & 31));
    }
}
