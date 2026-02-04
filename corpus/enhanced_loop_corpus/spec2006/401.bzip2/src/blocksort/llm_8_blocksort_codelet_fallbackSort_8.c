#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i += 2) {
        UInt32 val1 = ftab[i];
        bhtab[val1 >> 5] |= (1 << (val1 & 31));
        if (i + 1 < 256) {
            UInt32 val2 = ftab[i + 1];
            bhtab[val2 >> 5] |= (1 << (val2 & 31));
        }
    }
}
