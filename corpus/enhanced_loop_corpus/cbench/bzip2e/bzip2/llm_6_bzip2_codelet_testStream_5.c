#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 i;
extern UChar unused[5000];
extern Int32 nUnused;
extern UChar *unusedTmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 j;
    for (j = 0; j < nUnused; j++) {
        unused[j] = unusedTmp[j];
        if (j > 0)
            unused[j] += unused[j - 1]; // Introduce RAW dependency: current depends on previous
    }
}
