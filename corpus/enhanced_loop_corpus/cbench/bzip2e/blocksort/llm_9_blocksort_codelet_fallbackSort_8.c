#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        Int32 val1 = ftab[i];
        Int32 val2 = ftab[255 - i];
        bhtab[val1 >> 5] |= (1 << (val1 & 31));
        bhtab[val2 >> 5] |= (1 << (val2 & 31));
    }
}
