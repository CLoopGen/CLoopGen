#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 256; depth1++) {
        for (int depth2 = 0; depth2 < 1; depth2++) {
            i = depth1;
            bhtab[(ftab[i]) >> 5] |= (1 << ((ftab[i]) & 31));
        }
    }
}
