#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 j;
    for (i = 0, j = 255; i < 256; i++, j--) {
        if (i <= j) {
            bhtab[(ftab[i]) >> 5] |= (1 << ((ftab[i]) & 31));
            bhtab[(ftab[j]) >> 5] |= (1 << ((ftab[j]) & 31));
        }
    }
}
