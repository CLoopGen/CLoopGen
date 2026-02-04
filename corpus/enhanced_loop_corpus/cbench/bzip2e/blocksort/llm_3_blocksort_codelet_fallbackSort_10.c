#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

typedef unsigned char UChar;

extern UInt32 *fmap;
extern Int32 nblock;
extern Int32 ftabCopy[256];
extern Int32 i;
extern Int32 j;
extern UChar *eclass8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via lookup table for j advancement
    // Precompute a jump table that maps current j to the next valid index with non-zero count
    Int32 nextValid[256];
    Int32 lastValid = 255;
    for (Int32 idx = 255; idx >= 0; idx--) {
        if (ftabCopy[idx] > 0) {
            lastValid = idx;
        }
        nextValid[idx] = lastValid;
    }

    for (i = 0; i < nblock; i++) {
        // Use precomputed nextValid to get a usable j without while loops
        if (j >= 256 || ftabCopy[j] == 0) {
            j = nextValid[j];
        }
        ftabCopy[j]--;
        eclass8[fmap[i]] = (UChar)j;
    }
}
