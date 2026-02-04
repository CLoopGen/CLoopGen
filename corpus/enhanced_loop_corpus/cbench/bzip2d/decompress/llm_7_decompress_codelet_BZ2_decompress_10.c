#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nGroups;
extern UChar pos[6];
extern UChar v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    UChar prev = 0;
    for (v = 0; v < nGroups; v++) {
        pos[v] = prev + v;
        prev = pos[v];
    }
}
