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
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = nUnused - 1; i >= 0; i--)
        unused[i] = unusedTmp[i];
}
