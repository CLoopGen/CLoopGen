#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i += 4) {
        bhtab[(ftab[i]) >> 5] |= (1 << ((ftab[i]) & 31));
        if (i + 1 < 256) bhtab[(ftab[i+1]) >> 5] |= (1 << ((ftab[i+1]) & 31));
        if (i + 2 < 256) bhtab[(ftab[i+2]) >> 5] |= (1 << ((ftab[i+2]) & 31));
        if (i + 3 < 256) bhtab[(ftab[i+3]) >> 5] |= (1 << ((ftab[i+3]) & 31));
    }
}
