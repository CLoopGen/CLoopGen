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
for (; i >= 3; i -= 4) {
    // Variant 1: Consecutive memory access with precomputed indices to improve spatial locality
    Int32 idx0 = i;
    Int32 idx1 = i - 1;
    Int32 idx2 = i - 2;
    Int32 idx3 = i - 3;

    quadrant[idx0] = 0;
    j = (j >> 8) | (((UInt16)block[idx0]) << 8);
    ftab[j]++;
    
    quadrant[idx1] = 0;
    j = (j >> 8) | (((UInt16)block[idx1]) << 8);
    ftab[j]++;
    
    quadrant[idx2] = 0;
    j = (j >> 8) | (((UInt16)block[idx2]) << 8);
    ftab[j]++;
    
    quadrant[idx3] = 0;
    j = (j >> 8) | (((UInt16)block[idx3]) << 8);
    ftab[j]++;
}
}
