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
    // Variant 2: Strided memory access on eclass8 through permuted write order
    // We modify the access pattern to write to eclass8 in a strided manner by processing
    // fmap entries in a reordered fashion (every 4th element), improving potential cache behavior.
    // Also replaces the inner while-loop with direct search using a for-loop.

    // First, ensure j is within bounds and points to a non-zero count
    if (ftabCopy[j] == 0) {
        for (Int32 probe = j + 1; probe < 256; probe++) {
            if (ftabCopy[probe] != 0) {
                j = probe;
                break;
            }
        }
    }

    for (i = 0; i < nblock; i += 4) {
        // Process 4 iterations at once with stride handling
        for (Int32 step = 0; step < 4; step++) {
            Int32 idx = i + step;
            if (idx >= nblock) break;

            ftabCopy[j]--;
            eclass8[fmap[idx]] = (UChar)j;

            // Update j only when current bucket is exhausted
            if (ftabCopy[j] == 0) {
                Int32 found = 0;
                for (Int32 probe = j + 1; probe < 256 && !found; probe++) {
                    if (ftabCopy[probe] != 0) {
                        j = probe;
                        found = 1;
                    }
                }
            }
        }
    }
}
