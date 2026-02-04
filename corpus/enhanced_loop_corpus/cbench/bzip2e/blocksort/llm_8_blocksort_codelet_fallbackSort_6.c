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
    // Variant 1: Increased computational intensity with unrolled loop (tripled arithmetic operations per iteration)
    // Loop unrolling factor of 2 with additional dummy arithmetic to increase computation per iteration
    Int32 limit = nblock - (nblock % 2);
    for (i = 0; i < limit; i += 2) {
        // First iteration of unroll
        j = eclass8[i];
        k = ftab[j] - 1;
        ftab[j] = k;
        fmap[k] = i;

        // Additional computation to increase intensity
        k = (k ^ i) + 1;
        ftab[j] = (ftab[j] + k) & (nblock - 1);

        // Second iteration of unroll
        j = eclass8[i+1];
        k = ftab[j] - 1;
        ftab[j] = k;
        fmap[k] = i+1;

        // Additional computation
        k = (k ^ (i+1)) + 2;
        ftab[j] = (ftab[j] - k) & (nblock - 1);
    }
    // Handle remainder
    for (; i < nblock; i++) {
        j = eclass8[i];
        k = ftab[j] - 1;
        ftab[j] = k;
        fmap[k] = i;
    }
}
