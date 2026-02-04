#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    UInt32 temp1, temp2;
    for (i = 0; i < 32; i++) {
        Int32 index1 = (nblock + 2 * i) >> 5;
        Int32 shift1 = (nblock + 2 * i) & 31;
        Int32 index2 = (nblock + 2 * i + 1) >> 5;
        Int32 shift2 = (nblock + 2 * i + 1) & 31;

        temp1 = bhtab[index1];
        temp1 |= (1 << shift1);
        bhtab[index1] = temp1;

        temp2 = bhtab[index2];
        temp2 &= ~(1 << shift2);
        bhtab[index2] = temp2;
    }
}
