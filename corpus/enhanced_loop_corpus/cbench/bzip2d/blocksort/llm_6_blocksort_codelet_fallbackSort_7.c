#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 i;
extern Int32 nBhtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    UInt32 temp = 0;
    for (i = 0; i < nBhtab; i++) {
        temp += bhtab[i];
        bhtab[i] = 0;
    }
    // Introduces a loop-carried dependency via 'temp' (accumulation pattern)
    // RAW dependency: each iteration reads bhtab[i] before writing
    // WAW on bhtab[i] is removed since each write is to a unique index
    // New loop-carried dependency through 'temp' creates a reduction-like data flow
}
