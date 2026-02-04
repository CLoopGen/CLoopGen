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
    // Variant 2: Reduced computational intensity with indirect indexing and conditional skip
    // Introduce a stride to reduce effective trip count and add lightweight condition
    Int32 stride = 2;
    if (nblock > 1000) {
        // For larger blocks, process every second element to lower work
        for (i = 0; i < nblock; i += stride) {
            j = eclass8[i];
            k = ftab[j] - 1;
            ftab[j] = k;
            fmap[k] = i;
        }
        // Final pass on odd indices if needed (simulates partial coverage)
        for (i = 1; i < nblock && nblock <= 2000; i += stride) {
            j = eclass8[i];
            k = ftab[j] - 1;
            ftab[j] = k;
            fmap[k] = i;
        }
    } else {
        // Fallback to original behavior for small input
        for (i = 0; i < nblock; i++) {
            j = eclass8[i];
            k = ftab[j] - 1;
            ftab[j] = k;
            fmap[k] = i;
        }
    }
}
