#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 i;
extern Int32 nBhtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nBhtab; i++) {
        if (i % 2 == 0) {
            bhtab[i] = 0;
        } else {
            continue;
        }
    }
}
