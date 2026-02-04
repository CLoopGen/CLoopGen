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
    // Variant 2: Strided memory access pattern using a fixed offset array
    // Introduce a small lookup table for offsets to simulate a non-sequential access pattern.
    // Although logically equivalent, this changes the memory access stride and may affect cache behavior.

    const Int32 offset[4] = {0, -1, -2, -3};  // Define strided access pattern

    for (; i >= 3; i -= 4) {
        for (Int32 k = 0; k < 4; ++k) {
            Int32 idx = i + offset[k];
            quadrant[idx] = 0;
            j = (j >> 8) | (((UInt16)block[idx]) << 8);
            ftab[j]++;
        }
    }
}
