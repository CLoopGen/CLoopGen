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
    // Variant 2: Strided memory access with indirect indexing via an offset array
    // Use a fixed strided pattern through a lookup table of relative offsets.
    // This simulates non-consecutive, configurable access patterns useful in data shuffling.

    static const Int32 offsets[4] = {0, -2, -1, -3}; // Mixed order access (indirect/strided pattern)

    for (; i >= 3; i -= 4) {
        // Apply mixed access order using offset table
        for (Int32 k = 0; k < 4; ++k) {
            Int32 idx = i + offsets[k];
            quadrant[idx] = 0;
            j = (j >> 8) | (((UInt16)block[idx]) << 8);
            ftab[j]++;
        }
    }
}
