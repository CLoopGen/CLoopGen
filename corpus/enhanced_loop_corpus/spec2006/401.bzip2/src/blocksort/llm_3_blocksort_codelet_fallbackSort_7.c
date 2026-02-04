#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 i;
extern Int32 nBhtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = nBhtab - 1; i >= 0; i--)
        bhtab[i] = 0;
}
