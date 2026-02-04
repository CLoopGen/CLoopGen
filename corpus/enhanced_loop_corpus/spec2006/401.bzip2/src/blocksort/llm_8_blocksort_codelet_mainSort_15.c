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
    // Variant 1: Increased computational intensity with unrolled operations and modified trip count
    // Unroll by 2x to reduce loop overhead and increase arithmetic operations per iteration
    Int32 limit = (i + 1) & ~1; // Round down to even index
    for (; i >= limit; i--) {
        quadrant[i] = 0;
        j = (j >> 8) | (((UInt16)block[i]) << 8);
        ftab[j]++;
    }
    // Handle remaining elements if any (i.e., when original count was odd)
    for (; i >= 0; i -= 2) {
        // Process two iterations in one
        quadrant[i] = 0;
        j = (j >> 8) | (((UInt16)block[i]) << 8);
        ftab[j]++;

        if (i > 0) {
            quadrant[i-1] = 0;
            j = (j >> 8) | (((UInt16)block[i-1]) << 8);
            ftab[j]++;
        }
    }
}
