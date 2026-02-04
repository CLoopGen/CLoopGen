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
    for (j = 1; j <= nUnused; j++) {
        unused[j - 1] = unusedTmp[j - 1] ^ unused[(j - 1 + nUnused - 1) % nUnused]; 
    }
}
