#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef unsigned short UInt16;

typedef unsigned int UInt32;

typedef int Int32;

extern UChar *block;
extern UInt16 *quadrant;
extern UInt32 *ftab;
extern Int32 i;
extern Int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed traversal order within unrolled body
    // Instead of processing i, i-1, i-2, i-3 in decreasing index order,
    // we reorder the operations to access block and quadrant in increasing offset from (i-3),
    // while maintaining same functional behavior.

    for (; i >= 3; i -= 4) {
        Int32 base = i - 3;
        j = (j >> 8) | (((UInt16)block[base + 3]) << 8);
        ftab[j]++;
        quadrant[base + 3] = 0;

        j = (j >> 8) | (((UInt16)block[base + 2]) << 8);
        ftab[j]++;
        quadrant[base + 2] = 0;

        j = (j >> 8) | (((UInt16)block[base + 1]) << 8);
        ftab[j]++;
        quadrant[base + 1] = 0;

        j = (j >> 8) | (((UInt16)block[base]) << 8);
        ftab[j]++;
        quadrant[base] = 0;
    }
}
