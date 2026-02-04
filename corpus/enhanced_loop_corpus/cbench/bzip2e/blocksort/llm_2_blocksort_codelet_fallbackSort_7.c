#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 i;
extern Int32 nBhtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < nBhtab; i += 2)
        bhtab[i] = 0;
    if (nBhtab > 0) {
        for (i = 1; i < nBhtab; i += 2)
            bhtab[i] = 0;
    }
}
