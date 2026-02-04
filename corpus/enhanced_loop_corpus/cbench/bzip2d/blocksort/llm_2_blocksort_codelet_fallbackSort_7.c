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
    // Handle odd-sized array if needed
    if (nBhtab % 2 == 1)
        bhtab[nBhtab - 1] = 0;
}
