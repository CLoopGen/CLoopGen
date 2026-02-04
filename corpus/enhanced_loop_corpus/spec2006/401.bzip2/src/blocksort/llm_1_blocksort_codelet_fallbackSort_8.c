#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 256; outer += 16) {
        for (i = outer; i < outer + 16 && i < 256; i++)
            bhtab[(ftab[i]) >> 5] |= (1 << ((ftab[i]) & 31));
    }
}
