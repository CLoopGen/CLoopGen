#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 i;
extern Int32 nBhtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    UInt32 *local_bhtab = bhtab;
    Int32 local_nBhtab = nBhtab;
    for (i = 0; i < local_nBhtab; i += 2) {
        if (i + 1 < local_nBhtab) {
            local_bhtab[i] = 0;
            local_bhtab[i + 1] = 0;
        } else {
            local_bhtab[i] = 0;
        }
    }
}
