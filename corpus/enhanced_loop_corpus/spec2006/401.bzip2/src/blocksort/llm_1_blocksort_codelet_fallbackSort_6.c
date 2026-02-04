#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

typedef unsigned char UChar;

extern UInt32 *fmap;
extern Int32 nblock;
extern Int32 ftab[257];
extern Int32 i;
extern Int32 j;
extern Int32 k;
extern UChar *eclass8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nblock; i++) {
        for (j = 0; j < 1; j++) {  // Artificially nested with fixed inner iteration
            j = eclass8[i];
            k = ftab[j] - 1;
            ftab[j] = k;
            fmap[k] = i;
        }
    }
}
