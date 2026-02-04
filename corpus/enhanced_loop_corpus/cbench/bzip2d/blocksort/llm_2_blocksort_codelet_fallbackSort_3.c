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
    // Variant 1: Strided memory access with stride of 2
    // Access eclass8 at even indices only, updating corresponding ftab entries
    for (i = 0; i < nblock; i += 2)
        ftab[eclass8[i]]++;
}
