#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 j;
    UInt32 temp1, temp2;
    for (j = 0; j < 32; j++) {
        Int32 index1 = (nblock + 2 * j) >> 5;
        Int32 shift1 = (nblock + 2 * j) & 31;
        temp1 = 1 << shift1;
        bhtab[index1] |= temp1;

        Int32 index2 = (nblock + 2 * j + 1) >> 5;
        Int32 shift2 = (nblock + 2 * j + 1) & 31;
        temp2 = 1 << shift2;
        bhtab[index2] &= ~temp2;
    }
}
