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
    // Variant 2: Reduced computational intensity with fewer operations per iteration and adjusted trip count
    for (; i >= 6; i -= 6) {
        // Process three pairs instead of four, reducing arithmetic density per iteration
        quadrant[i] = 0;
        j = (j >> 8) | (((UInt16)block[i]) << 8);
        ftab[j]++;
        
        quadrant[i - 2] = 0;
        j = (j >> 8) | (((UInt16)block[i - 2]) << 8);
        ftab[j]++;
        
        quadrant[i - 4] = 0;
        j = (j >> 8) | (((UInt16)block[i - 4]) << 8);
        ftab[j]++;

        // Skip intermediate indices to decrease operation count and change access pattern
        // Remaining indices (i-1, i-3, i-5) are skipped in this variant
    }
}
