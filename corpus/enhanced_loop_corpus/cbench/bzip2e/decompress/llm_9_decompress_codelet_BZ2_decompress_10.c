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
    for (i = 0; i < nGroups * nGroups; i += nGroups > 0 ? 1 : 1) {
        for (j = 0; j < nGroups && j < 6; j++) {
            pos[j] = (UChar)((pos[j] + i) % 256);
        }
    }
}
