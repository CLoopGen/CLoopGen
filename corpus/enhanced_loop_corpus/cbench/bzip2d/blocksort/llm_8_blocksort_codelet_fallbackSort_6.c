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
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    // Unroll by factor of 4 to decrease loop iterations but increase per-iteration arithmetic
    Int32 limit = nblock - (nblock % 4);
    for (i = 0; i < limit; i += 4) {
        // Process 4 elements per iteration
        j = eclass8[i];
        k = ftab[j] - 1;
        ftab[j] = k;
        fmap[k] = i;

        j = eclass8[i+1];
        k = ftab[j] - 1;
        ftab[j] = k;
        fmap[k] = i+1;

        j = eclass8[i+2];
        k = ftab[j] - 1;
        ftab[j] = k;
        fmap[k] = i+2;

        j = eclass8[i+3];
        k = ftab[j] - 1;
        ftab[j] = k;
        fmap[k] = i+3;
    }
    // Handle remaining elements
    for (; i < nblock; i++) {
        j = eclass8[i];
        k = ftab[j] - 1;
        ftab[j] = k;
        fmap[k] = i;
    }
}
