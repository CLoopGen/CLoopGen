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
        temp += bhtab[i];  // Introduce RAW dependency: each read of bhtab[i] feeds into temp
        bhtab[i] = 0;      // Write after read, but now there's a loop-carried dependency via temp
    }
    // Additional use of temp to prevent elimination (simulate meaningful use)
    if (temp > 0) {
        bhtab[0] = temp;
    }
}
