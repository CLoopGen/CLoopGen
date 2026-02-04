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
    // Variant 1: Consecutive (forward) memory access with unrolling and stride simulation
    // Instead of processing i, i-1, i-2, i-3 in descending order, we reframe the loop to
    // iterate in steps of 4 from a base index, accessing elements in increasing order
    // for improved cache locality. We reverse the update order within the block.

    Int32 start = i - 3;
    for (; start <= i && (start + 3) >= 3; start += 4) {
        Int32 idx0 = start;
        Int32 idx1 = start + 1;
        Int32 idx2 = start + 2;
        Int32 idx3 = start + 3;

        // Process in ascending index order: idx0 -> idx3
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
    i = start - 4; // Adjust original i to reflect progress
}
