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
    // Variant 1: Consecutive memory access with indirect indexing via fmap, unrolled-like pattern
    // Instead of decrementing ftabCopy[j] after finding non-zero entry via while-loop,
    // we precompute valid j indices and traverse them consecutively to enable better vectorization.
    Int32 j_ptr = 0;
    for (i = 0; i < nblock; i++) {
        if (ftabCopy[j_ptr] == 0) {
            // Advance j_ptr to next non-zero bucket without using while
            for (Int32 k = j_ptr + 1; k < 256; k++) {
                if (ftabCopy[k] != 0) {
                    j_ptr = k;
                    break;
                }
            }
        }
        ftabCopy[j_ptr]--;
        eclass8[fmap[i]] = (UChar)j_ptr;
    }
}
