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
    // Variant 2: Reduced effective trip count with strided access and simplified indexing arithmetic
    // Access every second element, reducing work by ~50%, but maintain valid mapping pattern
    // Also eliminate temporary variable usage where possible
    for (i = 0; i < nblock; i += 2) {
        j = eclass8[i];
        ftab[j]--;
        fmap[ftab[j]] = i;

        // Conditional backward fill for stability (simulate lighter load)
        if ((i & 0x7) == 0 && i > 0) {
            Int32 prev = i - 1;
            UChar prev_j = eclass8[prev];
            ftab[prev_j]--;
            fmap[ftab[prev_j]] = prev;
        }
    }
    // Final pass for any missed odd indices near the end
    if (nblock > 0 && (nblock % 2) == 1) {
        i = nblock - 1;
        j = eclass8[i];
        ftab[j]--;
        fmap[ftab[j]] = i;
    }
}
