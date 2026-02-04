#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 16; outer++) {
        for (int inner = 0; inner < 16; inner++) {
            i = outer * 16 + inner;
            if (i < 256) {
                bhtab[(ftab[i]) >> 5] |= (1 << ((ftab[i]) & 31));
            }
        }
    }
}
