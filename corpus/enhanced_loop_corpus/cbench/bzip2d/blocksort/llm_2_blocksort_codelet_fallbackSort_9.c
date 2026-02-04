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
    // Instead of accessing strided indices, accumulate values in temporary variables
    // and write to consecutive locations in bhtab to improve spatial locality.
    UInt32 temp1, temp2;
    for (i = 0; i < 32; i++) {
        Int32 index1 = (nblock + 2 * i) >> 5;
        Int32 bit1 = (nblock + 2 * i) & 31;
        Int32 index2 = (nblock + 2 * i + 1) >> 5;
        Int32 bit2 = (nblock + 2 * i + 1) & 31;

        temp1 = bhtab[index1] | (1 << bit1);
        temp2 = bhtab[index2] & ~(1 << bit2);

        // Write back in a more cache-friendly order if indices are close
        bhtab[index1] = temp1;
        bhtab[index2] = temp2;
    }
}
