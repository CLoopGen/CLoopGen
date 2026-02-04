#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nGroups;
extern UChar pos[6];
extern UChar v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 i, j;
    for (v = 0; v < nGroups * nGroups; v += nGroups > 0 ? nGroups : 1) {
        for (i = 0; i < nGroups; i++) {
            pos[i] = (v + i) % 256;
        }
    }
}
