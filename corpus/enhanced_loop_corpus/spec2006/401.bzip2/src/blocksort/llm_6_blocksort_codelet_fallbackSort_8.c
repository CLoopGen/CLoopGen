#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    UInt32 temp[256];
    for (i = 0; i < 256; i++) {
        Int32 index = ftab[i] >> 5;
        Int32 shift = ftab[i] & 31;
        temp[i] = (1U << shift);
    }
    for (i = 0; i < 256; i++) {
        bhtab[ftab[i] >> 5] |= temp[i];
    }
}
