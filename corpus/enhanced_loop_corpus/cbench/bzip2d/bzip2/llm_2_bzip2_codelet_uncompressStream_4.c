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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < nUnused; i += 2)
        unused[i] = unusedTmp[i];
}
