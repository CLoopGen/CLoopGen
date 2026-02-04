#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nblock;
extern Int32 ftab[257];
extern Int32 i;
extern UChar *eclass8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 temp[257] = {0};
    for (Int32 j = 0; j < nblock; j++) {
        temp[eclass8[j]]++;
    }
    for (Int32 k = 0; k < 257; k++) {
        ftab[k] += temp[k];
    }
}
