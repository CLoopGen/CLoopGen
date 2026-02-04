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
        for (v = 0; v < nGroups; v++) {
            pos[v] = v;
            for (Int32 inner = 0; inner < 1; inner++);
        }
    }
}
