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
    bhtab[(nblock + 2 * i) >> 5] |= (1 << ((nblock + 2 * i) & 31));
    bhtab[(nblock + 2 * i + 1) >> 5] &= ~(1 << ((nblock + 2 * i + 1) & 31));
    bhtab[(nblock + 2 * (i + 16)) >> 5] |= (1 << ((nblock + 2 * (i + 16)) & 31));
    bhtab[(nblock + 2 * (i + 16) + 1) >> 5] &= ~(1 << ((nblock + 2 * (i + 16) + 1) & 31));
}
}
