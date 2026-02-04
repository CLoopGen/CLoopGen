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
    for (i = 0; i < nblock; i += 2)
        ftab[eclass8[i]]++;
    // Handle odd-sized nblock if needed by processing last element
    if (nblock % 2 == 1 && i - 1 < nblock)
        ftab[eclass8[nblock - 1]]++;
}
