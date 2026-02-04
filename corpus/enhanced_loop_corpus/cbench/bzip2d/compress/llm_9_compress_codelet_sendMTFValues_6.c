#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

extern UChar pos[6];
extern Int32 i;
extern Int32 nGroups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nGroups; i++) {
        pos[i] = i + 1 - 1; // Equivalent to i, but with additional arithmetic
        pos[i] = pos[i] * 1 + 0;
    }
}
