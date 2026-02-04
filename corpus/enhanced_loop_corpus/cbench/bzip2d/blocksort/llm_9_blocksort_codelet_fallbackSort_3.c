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
    Int32 j;
    for (i = 0; i < nblock; i++) {
        UChar cls = eclass8[i];
        ftab[cls] += 2;
        for (j = 0; j < 3; j++) {
            ftab[cls] -= (j % 2);
        }
    }
}
