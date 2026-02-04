#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; outer++) {
        for (i = 0; i < 16; i++) {
            int index1 = nblock + 2 * i + outer;
            bhtab[index1 >> 5] |= (1 << (index1 & 31));
            int index2 = nblock + 2 * i + 1 + outer;
            bhtab[index2 >> 5] &= ~(1 << (index2 & 31));
        }
    }
}
