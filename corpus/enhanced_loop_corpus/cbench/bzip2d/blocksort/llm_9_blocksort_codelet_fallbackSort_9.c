#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        Int32 base = nblock + 4 * i;
        bhtab[(base + 0) >> 5] |= (1 << ((base + 0) & 31));
        bhtab[(base + 1) >> 5] &= ~(1 << ((base + 1) & 31));
        bhtab[(base + 2) >> 5] |= (1 << ((base + 2) & 31));
        bhtab[(base + 3) >> 5] &= ~(1 << ((base + 3) & 31));
    }
}
