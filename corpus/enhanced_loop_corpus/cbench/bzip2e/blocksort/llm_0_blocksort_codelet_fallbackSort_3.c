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
    for (Int32 j = 0; j < nblock; j++) {
        for (i = j; i <= j; i++) {
            ftab[eclass8[i]]++;
        }
    }
}
