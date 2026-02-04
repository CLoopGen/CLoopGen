#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

extern UChar pos[6];
extern Int32 i;
extern Int32 nGroups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nGroups > 0) {
        for (i = 0; i < nGroups; i++) {
            pos[i] = i;
            for (int j = 0; j < 1; j++);
        }
    }
}
