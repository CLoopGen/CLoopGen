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
    for (i = 0; i < nblock; i++) {
        temp[eclass8[i]]++;
    }
    for (Int32 j = 0; j < 257; j++) {
        ftab[j] += temp[j];
    }
}
