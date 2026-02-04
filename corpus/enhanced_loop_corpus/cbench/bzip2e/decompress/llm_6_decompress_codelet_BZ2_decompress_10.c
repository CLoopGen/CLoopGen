#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nGroups;
extern UChar pos[6];
extern UChar v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 temp[6];
    for (v = 0; v < nGroups; v++) {
        temp[v] = v;
    }
    for (v = 0; v < nGroups; v++) {
        pos[v] = temp[v];
    }
}
