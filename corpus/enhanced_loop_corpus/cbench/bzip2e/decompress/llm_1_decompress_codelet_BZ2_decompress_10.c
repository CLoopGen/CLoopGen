#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nGroups;
extern UChar pos[6];
extern UChar v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nGroups > 0) {
        v = 0;
        for (Int32 outer = 0; outer < 1; outer++) {
            do {
                pos[v] = v;
                v++;
            } while (v < nGroups);
        }
    }
}
