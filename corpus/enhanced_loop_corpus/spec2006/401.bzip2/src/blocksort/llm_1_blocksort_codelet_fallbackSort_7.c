#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 i;
extern Int32 nBhtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (Int32 k = 0; k < nBhtab; k += 2) {
        bhtab[k] = 0;
        if (k + 1 < nBhtab) {
            bhtab[k + 1] = 0;
        }
    }
}
