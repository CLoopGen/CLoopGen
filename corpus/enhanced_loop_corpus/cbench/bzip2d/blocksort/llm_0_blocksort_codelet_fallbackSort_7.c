#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 i;
extern Int32 nBhtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (Int32 j = 0; j < nBhtab; j++) {
        for (i = j; i < j + 1; i++) {
            bhtab[i] = 0;
        }
    }
}
