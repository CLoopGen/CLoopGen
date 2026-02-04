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
    // Variant 1: Consecutive memory access pattern with strided write to eclass8
    // Instead of using while to find next non-zero ftabCopy[j], we precompute valid indices
    Int32 nextIndex = 0;
    for (i = 0; i < nblock; i++) {
        if (ftabCopy[nextIndex] == 0) {
            // Linear scan without while: advance nextIndex by one per iteration if needed
            for (; nextIndex < 256 && ftabCopy[nextIndex] == 0; nextIndex++);
        }
        if (nextIndex < 256) {
            ftabCopy[nextIndex]--;
            eclass8[fmap[i]] = (UChar)nextIndex;
        }
    }
}
