#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 i;
extern Int32 nBhtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nBhtab; i += 2) {
        if (i < nBhtab) bhtab[i] = 0;
        if (i + 1 < nBhtab) bhtab[i + 1] = 0;
    }
}
