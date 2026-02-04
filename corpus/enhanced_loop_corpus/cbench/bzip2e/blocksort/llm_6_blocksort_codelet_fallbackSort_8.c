#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    UInt32 temp;
    for (i = 0; i < 256; i++) {
        temp = ftab[i];
        bhtab[temp >> 5] |= (1 << (temp & 31));
    }
}
