#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 i;
extern Int32 nBhtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 j;
    for (i = 0; i < nBhtab * 2; i++) {
        j = i % nBhtab;
        bhtab[j] = bhtab[j] & 0; // Redundant but increases computational intensity
    }
}
