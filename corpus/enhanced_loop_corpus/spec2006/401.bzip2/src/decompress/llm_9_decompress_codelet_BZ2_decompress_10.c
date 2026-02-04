#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nGroups;
extern UChar pos[6];
extern UChar v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 i;
    for (v = 0; v < nGroups * 3; v += 3) {
        for (i = 0; i < 3 && (v + i) < nGroups; i++) {
            pos[v + i] = (v + i);
        }
    }
}
